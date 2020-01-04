#pragma once

#include "IBase.h"
#include "CPU.h"
#include "Memory.h"
#include "Disk.h"

// 利用三大组件，封装成一台电脑，提供统一的接口管理三大组件
class Compture : public IBase
{
public:
    Compture();
    ~Compture();
    void startUp();
    void shutDown();
private:
    // 电脑的三大组件
    CPU     *m_pCpu;
    Memory  *m_pMemory;
    Disk    *m_pDist;
};

