#pragma once


#include "httplib.h"

void getHello(httplib::Response& response, const std::string& request);
void getEmployeeList(httplib::Response& response, const std::string& request);
void getEmployeeProfile(httplib::Response& response,  const std::string& request); 
    