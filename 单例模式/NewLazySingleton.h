/**
 * 懒汉式单例模式, 需c++11支持，跨平台版本，线程安全版本
 */

#pragma once

// version 1.2
class NewLazySingleton
{
private:
	NewLazySingleton() { };
	~NewLazySingleton() { };
	NewLazySingleton(const NewLazySingleton&);
	NewLazySingleton& operator=(const NewLazySingleton&);
public:
	static NewLazySingleton& getInstance() 
    {
		static NewLazySingleton instance;
		return instance;
	}

    int getValue()
    {
        return 1;
    }
};

#define NZ (NewLazySingleton::getInstance())
