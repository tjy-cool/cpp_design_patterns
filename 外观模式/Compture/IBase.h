#pragma once

// 接口类
class IBase
{
public:
    virtual ~IBase() {};
    virtual void startUp() = 0;
    virtual void shutDown() = 0;
};