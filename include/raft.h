
#pragma once
#include <vector>
#include <string>

struct LogEntry {
    int term;
    std::string command;
};

class RaftNode {
public:
    int id;
    int term = 0;
    std::vector<std::string> peers;
    std::vector<LogEntry> log;

    void start();
    void replicate(const std::string& cmd);
};

extern RaftNode raft;
