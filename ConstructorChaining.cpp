#include <iostream>
using namespace std;

// base class
class Animal {

   public:
   
   	int age;
	string color;
   
	Animal(int a, string c):age(a), color(c)
	{
		
	}
   

	
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// derived class
class Dog : public Animal {
 
   public:
	Dog(int a, string s):Animal(a,s)
	{
	}
   
    void bark() {
        cout << "I can bark!" << endl;
    }
};

class Tiger : public Animal {
 
   public:
   
   	Tiger(int a, string s):Animal(a,s)
	{
	}
   
    void roar() {
        cout << "I can roar!" << endl;
    }
};

int main() {
    // Create object of the Dog class
    Dog dog1(4, "white");
   // dog1.age = 4;

    dog1.eat();
    dog1.sleep();

    dog1.bark();
    
    cout << dog1.age << "  " << dog1.color << endl;
    
    // Create object of the Tiger class
    Tiger tiger1(15, "yellow");

    tiger1.eat();
    tiger1.sleep();

    tiger1.roar();
    
    // Animal *a = new Dog();
    // a->eat();

    return 0;
}
