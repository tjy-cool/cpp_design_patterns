#include <iostream>
using namespace std;
#include "Compter.h"

Compture::Compture()
{
    m_pCpu = new CPU();
    m_pMemory = new Memory();
    m_pDist = new Disk();
}
Compture::~Compture()
{
    if (m_pCpu)
    {
        delete m_pCpu;
        m_pCpu = NULL;
    }
    if (m_pMemory)
    {
        delete m_pMemory;
        m_pMemory = NULL;
    }
    if (m_pDist)
    {
        delete m_pDist;
        m_pDist = NULL;
    }
}

void Compture::startUp()
{
    m_pCpu->startUp();
    m_pMemory->startUp();
    m_pDist->startUp();
}

void Compture::shutDown()
{
    m_pDist->shutDown();
    m_pMemory->shutDown();
    m_pCpu->shutDown();
}
