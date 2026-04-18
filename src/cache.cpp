#include <iostream>
#include "cache.h"
#include <fstream>
PageCache cache;

void PageCache::write(const std::string& p,const std::string& d){
    std::lock_guard<std::mutex> g(m);
    std::cout << "[CACHE WRITE] " << p << std::endl;
    cache[p]={d,true};
}

std::string PageCache::read(const std::string& p){
    std::lock_guard<std::mutex> g(m);
    if(cache.count(p)) {
        std::cout << "[CACHE HIT] " << p << std::endl;
        return cache[p].data;
    }
    std::cout << "[CACHE MISS] " << p << std::endl;
    return "";
}

void PageCache::flush(){
    std::lock_guard<std::mutex> g(m);
    for(auto &it:cache){
        if(it.second.dirty){
            std::cout << "[CACHE FLUSH] " << it.first << std::endl;
            std::ofstream("data/" + it.first.substr(1)) << it.second.data;
            it.second.dirty=false;
        }
    }
}
