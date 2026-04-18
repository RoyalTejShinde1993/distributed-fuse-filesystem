
#include "metadata.h"
MetadataStore metadata;

bool MetadataStore::exists(const std::string& p){ return files.count(p); }
void MetadataStore::create(const std::string& p){ files[p] = {0}; }
FileMeta* MetadataStore::get(const std::string& p){
    if(!exists(p)) return nullptr;
    return &files[p];
}
