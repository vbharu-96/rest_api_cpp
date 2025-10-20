#include<iostream>
#include"EmployerServer.h"


EmployerServer::EmployerServer(const std::uint32_t& port):ip("0.0.0.0"),port(port) {
}

EmployerServer::EmployerServer(const std::string& ip, const std::uint32_t& port):ip(ip),port(port) {
}

EmployerServer::~EmployerServer()
{
    std::cout<<"Server stopped"<<std::endl;
}

void EmployerServer::start()
{
    std::cout<<"Starting server ......"<<std::endl;
    server.set_pre_routing_handler([](const auto& req, auto& res) {
  if (req.path == "/hello") {
    res.set_content("world", "text/html");
    return httplib::Server::HandlerResponse::Handled;
  }
  return httplib::Server::HandlerResponse::Unhandled;
});
    server.listen(ip, port);
}