#include <iostream>
#include "cache.h"
#include <fstream>
PageCache cache;

void PageCache::write(const std::string& p,const std::string& d){
    std::lock_guard<std::mutex> g(m);
    cache[p]={d,true};
}

std::string PageCache::read(const std::string& p){
    std::lock_guard<std::mutex> g(m);
    if(cache.count(p)) return cache[p].data;
    return "";
}

void PageCache::flush(){
    std::lock_guard<std::mutex> g(m);
    for(auto &it:cache){
        if(it.second.dirty){
            std::ofstream("data"+it.first)<<it.second.data;
            it.second.dirty=false;
        }
    }
}
