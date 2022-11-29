#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
	private : 
			 
		Singleton();
		static Singleton* obj;
		
	public :
		
		static Singleton GetInstance()
		{
			if(!obj)
			{
				mutex _mutex;
				lock_guard<mutex> _lock(_mutex);
				if(!obj)
				{
					obj = new Singleton();	
				}
			}
			return *obj;
		}
};

Singleton* Singleton:: obj = nullptr;

int main() {
	// your code goes here
	return 0;
}
