#include <iostream>
using namespace std;

// 三个懒汉式版本
#include "Singleton.h"
#include "LazySingleton.h"
#include "NewLazySingleton.h"

// 饿汉式版本
#include "EagerSingleton.h"

int main(int argc, char* argv[])
{
    /***************** 非线程安全版本的懒汉式单例模式 *******************/
    cout << "test singleton" << endl;
    Singleton* p1 = Singleton::getInstance();
    cout << p1 << endl;

    /***************** 线程安全版本的懒汉式单例模式 *******************/
    cout << "test lazy_singleton" << endl;
    LazySingleton* lazy1 = LazySingleton::getInstance();
    cout << lazy1 << endl;

    LazySingleton* lazy2 = LazySingleton::getInstance();
    cout << lazy2 << endl;

    /***************** 线程安全版本的懒汉式单例模式 2 *******************/
    cout << NewLazySingleton::getInstance().getValue() << endl;
    cout << NZ.getValue() << endl;

    /***************** 线程安全版本的饿汉式单例模式 *******************/
    cout << EagerSingleton::getInstance().getValue() << endl;
    cout << ES.getValue() << endl;
    return 0;
}