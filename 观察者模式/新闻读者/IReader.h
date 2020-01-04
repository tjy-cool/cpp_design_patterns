#pragma once

#include <string>

using namespace std;

// 订阅者基类，观察者Oberver
class IReader
{
public:
    IReader(string name) : m_strName(name) { };
    ~IReader() { };

    // 观察者收到消息后的动作，由用户自己实现
    virtual void update(string strMsg) = 0;

protected:
    string m_strName;
};

// 具体订阅者，具体观察者ConcreteObserver
class TrueReader : public IReader
{
public:
    TrueReader(string name);

    void update(string strMsg) override;
};

TrueReader::TrueReader(std::string name) :IReader(name){

}

void TrueReader::update(std::string str) {
	printf("%s 看到新闻：%s\n", m_strName.c_str(), str.c_str());
}
