
#include "rpc.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include <iostream>

bool send_rpc(const std::string& host,int port,const std::string& msg){
    int sock=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in server{};
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=inet_addr(host.c_str());

    if(connect(sock,(sockaddr*)&server,sizeof(server))<0) return false;
    send(sock,msg.c_str(),msg.size(),0);
    close(sock);
    return true;
}

void start_server(int port){
    int s=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in addr{};
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=INADDR_ANY;

    bind(s,(sockaddr*)&addr,sizeof(addr));
    listen(s,10);

    std::thread([&](){
        while(true){
            int c=accept(s,NULL,NULL);
            char buf[1024]={0};
            read(c,buf,1024);
            std::cout<<"RPC:"<<buf<<std::endl;
            close(c);
        }
    }).detach();
}
