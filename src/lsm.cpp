
#include "lsm.h"
#include <fstream>
LSM lsm;

void LSM::put(const std::string& k,const std::string& v){
    memtable[k]=v;
    if(memtable.size()>100) flush();
}

std::string LSM::get(const std::string& k){
    if(memtable.count(k)) return memtable[k];
    std::ifstream in("data/sstable.txt");
    std::string key,val;
    while(in>>key>>val){
        if(key==k) return val;
    }
    return "";
}

void LSM::flush(){
    std::ofstream out("data/sstable.txt",std::ios::app);
    for(auto &it:memtable){
        out<<it.first<<" "<<it.second<<"\n";
    }
    memtable.clear();
}
