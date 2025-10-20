#include<Handler.h>
#include<HandlerFunctions.h>

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

void Handler::init()
{
    entityToHandlerMap.emplace("GET/EmployeeList", getEmployeeList);
    entityToHandlerMap.emplace("GET/EmployeeProfile", getEmployeeProfile);
}