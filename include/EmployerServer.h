#pargam once

#include "httplib.h"

class EmployeeServer {
    public:

    private:
      httplib::Server server;
      Router router;
      constexpr std::uint32_t Port = 8080;
      constexpr std::string ip {"0.0.0.0"};
};