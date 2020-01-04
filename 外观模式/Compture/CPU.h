#pragma once

#include "IBase.h"

class CPU : public IBase
{
public:
    void startUp();
    void shutDown();
};
