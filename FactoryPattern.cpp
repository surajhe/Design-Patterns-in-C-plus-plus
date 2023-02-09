// In factory pattern we create objects without exposing the creational logic to the client and client uses r=the same common interface to create q new type of bject.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class IVehicle
{
public:
    virtual void printVehicle() = 0;
};

class TwoWheeler:public IVehicle
{
public:
    void printVehicle() override
    {
        cout << "Vehicle is 2 wheeler" <<endl;
    }
};

class FourWheeler:public IVehicle
{
public:
    void printVehicle() override
    {
        cout << "Vehicle is 4 wheeler" <<endl;
    }
};

class Client
{
private:
    IVehicle* pVehicle;

public:
    Client(int wheels)
    {
        if(wheels == 2)
        {
            pVehicle = new TwoWheeler();
        }
        else if(wheels == 4)
        {
            pVehicle = new FourWheeler();
        }
        else
        {
            pVehicle = NULL;
        }
    }

    IVehicle* getVehicle()
    {
        return pVehicle;
    }

    ~Client()
    {
        if(pVehicle)
        {
            delete pVehicle;
            pVehicle = NULL;
        }
    }

};


int main()
{
    Client* pClient = new Client(4);
    IVehicle* vehicle = pClient->getVehicle();
    vehicle->printVehicle();
    return 0;
}
