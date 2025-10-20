#pragma once


#include "httplib.h"

void getEmployeeList(httplib::Response& response, const std::string& filter = "");
void getEmployeeProfile(httplib::Response& response,  const std::string& filter); 
    