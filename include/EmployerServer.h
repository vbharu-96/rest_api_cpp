#pragma once

#include "httplib.h"

class EmployerServer {
    public:
    EmployerServer(const std::uint32_t& port);
    EmployerServer(const std::string& ip, const std::uint32_t& port);
    ~EmployerServer();
    EmployerServer(const EmployerServer& ) = delete;
    EmployerServer(EmployerServer &&) = delete;

    EmployerServer operator=(const EmployerServer& ) = delete;
    EmployerServer operator=(EmployerServer&&) = delete;

    void start();


    private:
      httplib::Server server;
      //Router router;
      std::uint32_t port;
      std::string ip;
};