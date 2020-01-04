// 大话设计模式里面的例子：小王想追求小娟，但他不认识小娟。
// 但他的朋友小林认识小娟，所以他通过让小林帮忙送礼物的方式追求小娟。
// 这里的小林就是我们的代理！

#include <iostream>
#include <string>
using namespace std;

class Gril
{
public:
    Gril(string name = "");
    string getName()
    {
        return mName;
    }
private:
    string mName;
};

Gril::Gril(string name) 
    :mName(name)
{

}

class GiveGift
{
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

class Puisuit : public GiveGift
{
public:
    Puisuit(Gril mm): m_Gril(mm) {}

    virtual void GiveDolls()
    {
         cout<<"送"<<m_Gril.getName()<<"玩具！"<<endl;
    }
    virtual void GiveFlowers()
    {
        cout<<"送"<<m_Gril.getName()<<"鲜花！"<<endl;
    }

    virtual void GiveChocolate()
    {
        cout<<"送"<<m_Gril.getName()<<"巧克力！"<<endl;
    }
private:
    Gril m_Gril;
};

class Proxy : public GiveGift
{
public:
    Proxy(Gril mm)
    {
        mPuisuit = new Puisuit(mm);
    }

    virtual void GiveDolls()
    {
        mPuisuit->GiveDolls();
    }

    virtual void GiveFlowers()
    {
        mPuisuit->GiveFlowers();
    }

    virtual void GiveChocolate()
    {
        mPuisuit->GiveChocolate();
    }
private:
    Puisuit* mPuisuit;

};

