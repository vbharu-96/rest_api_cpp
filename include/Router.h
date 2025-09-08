#pragma once

class Router 
{
    public:
    Router() {};
    ~Router() {};
    using Handler = void (*)(std::string ,httplib::Response);
    private:
    std::vector<std::string> entityList;
    std::unordered_map<std::string, Handler> entityToHandlerMap;
};