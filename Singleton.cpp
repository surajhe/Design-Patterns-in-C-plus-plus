#include <iostream>
using namespace std;


class Singleton
{
  private :
    Singleton();
    static Singleton* obj;
  
  public :
      static Singleton &GetInstance()
      {
        if(!obj)
        {         
            obj = new Singleton();
        }
        
        return *obj;
      }
};

Singleton* Singleton:: obj = nullptr;
