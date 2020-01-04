#pragma once

#include "IReader.h"
#include <string>
#include <list>
using namespace std;

class IReader;

// 发布者基类，目标subject
class INews
{
public:
    INews() { };
    ~INews() { };

    // 添加观察者
    virtual void addReader(IReader* oneReader) = 0;

    // 删除观察者
    virtual void delReader(IReader* oneReader) = 0;

    // 发布新闻
    virtual void releaseNews(std::string newStr) = 0;
};

// 发布消息具体类. 具体目标ConcreteSubject
class AppNews : public INews
{
public:
    void addReader(IReader* oneReader) override;
    void delReader(IReader* oneReader) override;
    void releaseNews(std::string newStr) override;

private:
    list<IReader*> m_ListReader;
};

void AppNews::addReader(IReader* oneReader)
{
    m_ListReader.push_back(oneReader);
}

void AppNews::delReader(IReader* oneReader)
{
    if (!m_ListReader.empty())
    {
        m_ListReader.remove(oneReader);
    }
}

void AppNews::releaseNews(std::string newStr) 
{
    list<IReader*>::iterator it = m_ListReader.begin();
    for( ; it != m_ListReader.end(); it++)
    {
        (*it)->update(newStr);
    }
}
