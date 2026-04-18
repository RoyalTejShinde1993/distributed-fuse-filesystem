
#include "fs.h"
#include "metadata.h"
#include "cache.h"
#include "wal.h"
#include "raft.h"
#include "lsm.h"
#include <cstring>

static int fs_getattr(const char *path, struct stat *st, struct fuse_file_info *fi){
    memset(st,0,sizeof(struct stat));
    if(strcmp(path,"/")==0){ st->st_mode=S_IFDIR|0755; return 0;}
    auto m=metadata.get(path);
    if(!m) return -ENOENT;
    st->st_mode=S_IFREG|0644;
    st->st_size=m->size;
    return 0;
}

static int fs_create(const char *path, mode_t, struct fuse_file_info*){
    metadata.create(path);
    wal.append("CREATE "+std::string(path));
    raft.replicate("CREATE "+std::string(path));
    return 0;
}

static int fs_write(const char *path,const char *buf,size_t size,off_t,struct fuse_file_info*){
    std::string d(buf,size);
    cache.write(path,d);
    wal.append("WRITE "+std::string(path));
    raft.replicate("WRITE "+std::string(path));
    lsm.put(path,d);
    auto m=metadata.get(path);
    m->size=size;
    return size;
}

static int fs_read(const char *path,char *buf,size_t size,off_t,struct fuse_file_info*){
    std::string d=cache.read(path);
    if(d.empty()) d=lsm.get(path);
    memcpy(buf,d.c_str(),std::min(size,d.size()));
    return std::min(size,d.size());
}

struct fuse_operations fs_oper = {};

void init_fs_oper() {
    fs_oper.getattr = fs_getattr;
    fs_oper.create  = fs_create;
    fs_oper.write   = fs_write;
    fs_oper.read    = fs_read;
}
