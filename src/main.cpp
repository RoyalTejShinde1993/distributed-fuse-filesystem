
#define FUSE_USE_VERSION 31
#include <fuse3/fuse.h>
#include "fs.h"

int main(int argc, char *argv[]) {
    return fuse_main(argc, argv, &fs_oper, NULL);
}
