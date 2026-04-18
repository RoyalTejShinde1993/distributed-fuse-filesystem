
#pragma once
#include <string>
#include <vector>

class WAL {
public:
    void append(const std::string&);
    std::vector<std::string> recover();
};

extern WAL wal;
