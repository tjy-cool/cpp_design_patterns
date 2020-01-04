// 外观模式是为了解决类与类之间的依赖关系的
// 就像一个电脑里面有很多零件，但是用电脑的人只能看到机箱。
// 开机流程： cpu --> 内存 --> 磁盘
// 关机流程： 磁盘 --> 内存 --> cpu

#include <iostream>
#include "Compter.h"

using namespace std;


int main(int argc, char* argv[])
{
    Compture* c = new Compture();
    cout << "======= Compture startup ========" << endl;
    c->startUp();

    cout << endl;
    cout << "======= Compture shutDown ========" << endl;
    c->shutDown();

    return 0;
}