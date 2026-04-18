
#include "wal.h"
#include <fstream>
WAL wal;

void WAL::append(const std::string& e){
    std::ofstream("logs/wal.log",std::ios::app)<<e<<"\n";
}

std::vector<std::string> WAL::recover(){
    std::ifstream in("logs/wal.log");
    std::vector<std::string> v; std::string l;
    while(getline(in,l)) v.push_back(l);
    return v;
}
