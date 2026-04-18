
#pragma once
#include <string>

bool send_rpc(const std::string& host, int port, const std::string& msg);
void start_server(int port);
