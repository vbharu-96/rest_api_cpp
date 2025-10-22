#include<Handler.h>
#include<HandlerFunctions.h>
#include "regex"

#include<iostream>

Handler* Handler::m_instance = nullptr;

Handler::Handler()
{
    init();
}

Handler* Handler::getInstance(){
    if(m_instance == nullptr)
    {
        m_instance = new Handler();
    }
    return m_instance;
}

std::string getAbsoluteReq(const auto& path, const auto& method)
{
    return std::regex_replace(method + path, std::regex("vkthrk/") , "" );
}

void Handler::handle(const httplib::Request& request, httplib::Response& response)
{
    std::cout<<"request path : "<<request.path<<std::endl;
    std::cout<<"request method : "<<request.method<<std::endl;
    std::cout<<getAbsoluteReq(request.path,request.method)<<std::endl;
    auto handlerMap = entityToHandlerMap.find(getAbsoluteReq(request.path,request.method));
    if(handlerMap != entityToHandlerMap.end())
    {
        handlerMap->second(response, request.body);
    }
}

void Handler::init()
{
    entityToHandlerMap.emplace("GET/hello", getHello);
    entityToHandlerMap.emplace("GET/EmployeeList", getEmployeeList);
    entityToHandlerMap.emplace("GET/EmployeeProfile", getEmployeeProfile);
}