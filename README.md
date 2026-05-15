
# 🚀 Distributed FUSE Filesystem  
### ⚡ High-Performance Distributed Storage System (C++ | Raft | WAL | LSM | FUSE)

## ⚡ Overview
A production-style distributed filesystem built using:
- FUSE (Linux filesystem interface)
- Raft consensus algorithm
- Write-Ahead Logging (WAL)
- In-memory page cache
- Async I/O pipeline

Designed for:
- Fault tolerance
- High throughput
- Crash recovery
- Distributed consistency

---

## 🏗️ Architecture
Client → FUSE → PageCache → WAL → Raft Leader → Followers → Disk

## Architecture

```text
                     +----------------------+
                     |       Client         |
                     |  POSIX File Access   |
                     +----------+-----------+
                                |
                                v
                     +----------------------+
                     |      FUSE Layer      |
                     |  Userspace Filesystem|
                     +----------+-----------+
                                |
            +-------------------+-------------------+
            |                                       |
            v                                       v
+----------------------+               +----------------------+
|   Metadata Manager   |               |  Replication Engine  |
+----------+-----------+               +----------+-----------+
           |                                      |
           |                                      |
           v                                      v
+----------------------+               +----------------------+
|    Storage Node A    |<------------->|    Storage Node B    |
|  Chunk Storage       |   Replication |  Chunk Storage       |
+----------------------+               +----------------------+
           ^
           |
           |
+----------------------+
|   Storage Node C    |
|  Chunk Storage       |
+----------------------+
```
## Replication Workflow
```text
Client Write Request
        |
        v
+----------------------+
|   Metadata Manager   |
+----------+-----------+
           |
           | Select Replicas
           v
+----------------------+       +----------------------+
|    Storage Node A    | ----> |    Storage Node B    |
+----------------------+       +----------------------+
           |
           |
           v
+----------------------+
|    Storage Node C    |
+----------------------+

Replication Factor = 3
```

---

## ✨ Features
- Sub-ms cache reads
- WAL-based durability
- Raft replication
- Multi-threaded async pipeline
- Crash recovery via log replay
- POSIX-style filesystem ops

---

## 🧠 Design Highlights
- WAL-first write strategy ensures zero data loss
- Leader-follower Raft model ensures consistency
- LRU page cache reduces disk I/O
- Async queues decouple filesystem path

---

## 📊 Performance
- Read latency: ~0.5–1 ms
- Write latency: ~1–2 ms
- Crash recovery: linear WAL replay

---

## 🚀 Build & Run
```bash
mkdir build && cd build
cmake ..
make -j
./fuse_fs /mnt/fs
