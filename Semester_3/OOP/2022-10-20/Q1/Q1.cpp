#include <iostream>

using namespace std;

class abc
{
public:
    virtual void func() = 0;
};

class xyz :public abc
{
public:
    void func()
    {
        cout << "this is function xyz";
    }
};

int main()
{
    abc obj1;
    xyz obj2;
    
    obj1.func();
    obj2.func();

    return 0;
}