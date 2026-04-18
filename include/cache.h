
#pragma once
#include <unordered_map>
#include <string>
#include <mutex>

struct CacheEntry {
    std::string data;
    bool dirty;
};

class PageCache {
public:
    std::unordered_map<std::string, CacheEntry> cache;
    std::mutex m;
    void write(const std::string&, const std::string&);
    std::string read(const std::string&);
    void flush();
};

extern PageCache cache;
