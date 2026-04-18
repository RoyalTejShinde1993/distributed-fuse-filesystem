#include <iostream>
#include "raft.h"
#include "rpc.h"
RaftNode raft;

void RaftNode::start(){}

void RaftNode::replicate(const std::string& cmd){
    log.push_back({term,cmd});
    for(auto &p:peers){
        send_rpc("127.0.0.1",stoi(p),"APPEND|"+cmd);
    }
}
