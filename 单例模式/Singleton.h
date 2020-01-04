#pragma once
/**
 * 懒汉式单例模式, 非线程安全版本
 */

#include <iostream>
#include <thread>

using namespace std;

class Singleton
{
private:
	static Singleton* instance;
private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton* getInstance() 
        {
		if(instance == NULL) 
			instance = new Singleton();
		return instance;
	}
};

// init static member
Singleton* Singleton::instance = NULL;
