/**
 * 饿汉式单例模式, 引用版本，建议
 */

#pragma once

class EagerSingleton
{
private:
	static EagerSingleton instance;
private:
	EagerSingleton() {};
	~EagerSingleton() {};
	EagerSingleton(const EagerSingleton&);
	EagerSingleton& operator=(const EagerSingleton&);
public:
	static EagerSingleton& getInstance() {
		return instance;
	}

    int getValue()
    {
        return 2;
    }
};

// initialize defaultly
EagerSingleton EagerSingleton::instance;

#define ES (EagerSingleton::getInstance())

