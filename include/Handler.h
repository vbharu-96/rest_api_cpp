#pragma once


#include "httplib.h"
#include "unordered_map"
#include "memory"

class Handler 
{
    public:
    using HandlerFn = void(*)(httplib::Response& response, const std::string& filter);
    static Handler* getInstance();
    void handle(const httplib::Request& req, httplib::Response& res);
    ~Handler() {};

    private:
    Handler();
    void init();

    private:
    static Handler* m_instance;
    std::unordered_map<std::string, HandlerFn> entityToHandlerMap;
};