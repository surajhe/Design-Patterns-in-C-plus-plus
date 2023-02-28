#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Strategy Design Pattern
// Behavioral design pattern that enables selecting an algorithm at runtime.
// instead of implementing a single algorithm directly, code receives run-time instructions
// and strategy decides which algorithm to use

// deferring the decision about which code to use until runtime allows the calling code
// to be more flexible and reusable.

// A class that performs validation on incoming data may use the strategy pattern to select
// a validation algorithm depending on the type of data, source of data, user choice.

class SortStrategy
{
public:
    virtual void Sort(vector<int>& vec) = 0;
    virtual ~SortStrategy();
};

class BubbleSort:public SortStrategy
{
public:
    void Sort(vector<int>& vec) override;
};

class QuickSort:public SortStrategy
{
public:
    void Sort(vector<int>& vec) override;
};

int main()
{
    std::unique_ptr<SortStrategy>  sort_obj;
    //SortStrategy *sort_obj = nullptr;
    vector<int> V{5,3,6,7,8,1,2};

    int choice;
    cout << "1) Bubble Sort \n 2) QuickSort\n 3) Exit" << endl;
    cin >> choice;

    if(choice == 1)
    {
        sort_obj = std::move(std::make_unique<BubbleSort>());
    }
    else if(choice == 2)
    {
        sort_obj = std::move(std::make_unique<QuickSort>());
    }

    if(sort_obj != NULL)
    {
        sort_obj->Sort(V);
    }

    return 0;
}
