#include<iostream>
#include"EmployerServer.h"
#include "Handler.h"


EmployerServer::EmployerServer(const std::uint32_t& port):ip("localhost"),port(port),server("build/cert/cert.pem", "build/cert/key.pem") {
}

EmployerServer::EmployerServer(const std::string& ip, const std::uint32_t& port):ip(ip),port(port),server("build/cert/cert.pem", "build/cert/key.pem") {
}

EmployerServer::~EmployerServer()
{
    std::cout<<"Server stopped"<<std::endl;
}

void EmployerServer::start()
{
    std::cout<<"Starting server ......"<<std::endl;
    Handler* handler= Handler::getInstance();
    server.set_pre_routing_handler([&handler](const auto& req, auto& res) {
      std::cout<<"request : "<<req.path<<std::endl;
      if(req.path.find("/vkthrk") != std::string::npos)
      {
       handler->handle(req, res);
       return httplib::Server::HandlerResponse::Handled;
      }
      return httplib::Server::HandlerResponse::Unhandled;
    });
    server.listen(ip, port);
}