/**
 * 懒汉式单例模式, 无需c++11支持，Linux版本，线程安全版本
 */

#pragma once

#include <iostream>
#include <thread>
#include <string>
// #include <pthread.h>

using namespace std;

class LazySingleton
{
public:
    static LazySingleton* getInstance();
	static void print(string msg)
	{
		cout << msg << endl;
	}
private:
    class gc;	// 自动垃圾回收类

    LazySingleton() { /* print("lz"); */ };	// 构造
	~LazySingleton() { /* print("~lz"); */};	// 析构
    LazySingleton(const LazySingleton&);	// 拷贝
    LazySingleton& operator=(const LazySingleton&);	// 赋值

    static LazySingleton* m_pInstance;		// 单例
    static pthread_mutex_t m_mutex;			// 锁资源

	static gc gc_;
};

// 自动垃圾回收类
class LazySingleton::gc
{
    public:
	gc() { /* print("gc"); */ }
	~gc()
	{
		if(NULL != m_pInstance)
		{
			//print("~gc");
			// 其他的资源销毁，必须要在析构单例前

			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
};

pthread_mutex_t LazySingleton::m_mutex = PTHREAD_MUTEX_INITIALIZER;
LazySingleton* LazySingleton::m_pInstance = NULL;
LazySingleton::gc LazySingleton::gc_;

LazySingleton* LazySingleton::getInstance()
{
    if(NULL == m_pInstance)
    {
        pthread_mutex_lock(&m_mutex);
        if(NULL == m_pInstance)
        {
            m_pInstance = new LazySingleton();
        }
        pthread_mutex_unlock(&m_mutex);
    }
    return m_pInstance;
}

