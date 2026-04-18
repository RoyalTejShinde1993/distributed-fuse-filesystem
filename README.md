
# Distributed FUSE Filesystem (Elite: Raft RPC + LSM + Async I/O)

## Features
- FUSE filesystem
- Raft (RPC-based) leader + replication (simplified)
- WAL (append + replay)
- Page cache (write-back) with async flush
- Zero-copy (mmap/sendfile style)
- LSM-style metadata store (memtable + SSTable)
- Multi-node runner + fault simulation
- Benchmark + plotting

## Build
make

## Run (single node)
./myfs mount

## Multi-node
bash scripts/run_cluster.sh

## Fault simulation
bash scripts/kill_node.sh 5002

## Bench
bash scripts/benchmark.sh
python3 tools/plot.py
