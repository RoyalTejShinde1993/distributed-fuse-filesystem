
#pragma once
#include <string>
#include <unordered_map>

struct FileMeta {
    size_t size;
};

class MetadataStore {
public:
    std::unordered_map<std::string, FileMeta> files;
    bool exists(const std::string&);
    void create(const std::string&);
    FileMeta* get(const std::string&);
};

extern MetadataStore metadata;
