
#pragma once
#include <map>
#include <string>

class LSM {
public:
    std::map<std::string, std::string> memtable;
    void put(const std::string&, const std::string&);
    std::string get(const std::string&);
    void flush();
};

extern LSM lsm;
