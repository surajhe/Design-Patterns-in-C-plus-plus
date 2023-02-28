#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Proxy design pattern
// It is used to control and manage access to an object.
// 1. Real subject implementing the subject interface
// 2. Proxy subject implementing the subject interface and control access to the realsubject then delegates calls to it.
//    Client will be using proxy class, proxy then delegates calls to realsubject class.

//   some of the applications of proxy pattern is
//
//1) provide user authentication to an action defined in a class ;
//   users can define a proxy class and define the user validation logic there , then delegates call to
//   real class if authentication succeeds.

//2) If I want to make action in a class thread safe (if client needs thread safety) .
//   Define a proxy class and write the thread safety logic in that class and delegate the
//   call to real object .client will be using the proxy class.

class Box
{
   public:
        virtual void open() = 0;
};

class SimpleBox:public Box
        {
        public:
            void open() override
            {
                cout << "Box is opened" << endl;
            }
};

class ProxyBox:public Box{
private:
    string username;
    string password;
    SimpleBox box;

public:
    ProxyBox(string uname, string pass):username(uname), password(pass){};

    void open()
    {
        if(isAuthenticate())
        {
            box.open();
        }
    }

    bool isAuthenticate()
    {
        bool auth = false;
        // auth = authentication logic
        return auth;
    }
};

int main()
{
    Box *box = new ProxyBox("suraj", "123@");
    box->open();
    //delete box;

    return 0;
}
