#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Observer design pattern
// it is used to notify objects if some changes happens in another objects.
// It is also known as publish-subscribe pattern.
// In this pattern observers need to subscribed/registered to subject and if some changes 
// happens in subject then it notifies to observers.
// Example - one to many dependency between objects.
// suppose i am writting file monitoring application where i need to notify Listeners when 
// some file changes happens in a directory.
// File changes can be Adding a file, removing a file, updating a file, accessing a file.



#include<iostream>
#include <bits\stdc++.h>

using namespace std;

class IObserver
{
public:
    virtual void update(int value) = 0;
};

class observer1:public IObserver
{
public:
    void update(int value) override
    {
        cout << "value updated" <<endl;
    }
};

class observer2:public IObserver
{
public:
    void update(int value) override
    {
        cout << "value updated" <<endl;
    }
};

class Subject
{
private:
    int value;
    std::list<std::shared_ptr<IObserver>> observerList;
public:
    void valueChanged(int val)
    {
        value = val;
        notifyAll();
    }
    void addObserver(std::shared_ptr<IObserver> obj)
    {
        observerList.push_back(obj);
    }

    void removeObserver(std::shared_ptr<IObserver> obj)
    {
        observerList.remove(obj);
    }

    void notifyAll()
    {
        for(auto i:observerList)
        {
            i->update(value);
        }
    }

};


int main()
{
    std::unique_ptr<Subject> subject = std::make_unique<Subject>();

    std::shared_ptr<observer1> ob1 = std::make_shared<observer1>();
    std::shared_ptr<observer2> ob2 = std::make_shared<observer2>();

    subject->addObserver(ob1);
    subject->addObserver(ob2);

    subject->valueChanged(3);

    return 0;
}
