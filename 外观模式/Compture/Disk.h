#pragma once

#include "IBase.h"

class Disk : public IBase
{
public:
    void startUp();
    void shutDown();
};
