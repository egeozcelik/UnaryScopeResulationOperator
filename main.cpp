#include <iostream>
using namespace std;


//1.Usage
int X = 10;

//2.Usage
class A
{
public:
    void func();
};


void A :: func()
{
    cout<< "function called"<< endl;
}

//3.Usage
class Test
{
    static int x;
public:
    static int y;

    // Local parameter 'a' hides class member
    // 'a', but we can access it using ::
    void func(int x)
    {
        // We can access class's static variable
        // even if there is a local variable
        cout << "Value of static x is " << Test::x<<endl;

        cout << "\nValue of local x is " << x<<endl;
    }
};
int Test::x = 1;
int Test::y = 2;


//4.Usage
class X
{
    protected :int x = 10;
public :
   Xfunction()
    {
        x = 10;
    }
};
class Y
{
    protected: int x = 20;
public :
    Yfunction()
    {
        x = 20;
    }

};
class Z : public X, public Y
{
public:
    void func()
    {
        cout<< "X's x is:"<< X::x<<endl;
        cout << "Y's x is:"<< Y::x<<endl;
    }
};

//5.Usage
class outsideClass
{

public :
    int x;
    class insideClass
    {
    public:
        int x;
        static int y;

    };
};
int outsideClass::insideClass::y=5;
int main()
{
    //1.Usage
    //access with :: outside of func when there is a local variable with same name
    int X = 5;
    cout<<"Global X:" << ::X << endl;
    cout <<"Local X:" << X << endl;
    cout<<endl;



    //2.Usage
    //define a function outside a class
    A a;
    a.func();
    cout<<endl;


    //3.Usage
    // :: can be used to access static
    // members when there is a local variable with same name
    Test obj;
    int x = 3;
    obj.func(x);
    cout<< "\nTest::y = "<<Test::y;
    cout<<endl;

    //4.Usage
    //for the multiple inheritance
    Z z;
    z.func();
    cout<<endl;

    //5.Usage
    //If a class exists inside another class we can use
    //the nesting class to refer the nested class using
    //the scope resolution operator

     outsideClass class1;
     outsideClass::insideClass B;
     cout<<endl;
    return 0;
}
