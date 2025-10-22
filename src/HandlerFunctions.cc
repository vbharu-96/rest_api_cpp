    #include "HandlerFunctions.h"

    void getHello(httplib::Response& response, const std::string& request)
    {
      response.set_content("Hello World!", "test/plain");
    }
    void getEmployeeList(httplib::Response& response, const std::string& request) {

    }

    void getEmployeeProfile(httplib::Response& response, const std::string& request) {

    }
    