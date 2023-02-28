#include <iostream>

using namespace std;

// Adapter design Pattern

// Adapter design pattern convert the interface of class into another interface that
// client expects. Adapter lets classess work together that couldn't otherwise because
// of incompatible interface.

// How to use an adapter :-
// The client makes request to 

class Bird
{
	public:
		virtual void fly() = 0;
		virtual void makeSound() = 0;
};

class Sparrow:public Bird
{
	public:
		void fly() override
		{
			cout << "Flying ...." <<endl;
		}
		
		void makeSound() override
		{
			cout << "Chirping.... " <<endl;
		}
};

class ToyDuck
{
	public:
		virtual void squake() = 0;
};

class PlasticToyduck : public ToyDuck
{
	public:
		void squake() override
		{
			cout << "squeak...." <<endl;
		}
	
};

class BirdAdapter:public ToyDuck
{
	private:
		Bird *_bird;
	public:
		BirdAdapter(Bird *bird):_bird(bird){};
		
	void squake() override
	{
		_bird->makeSound();
	}
};

int main() {
	// your code goes here
	Sparrow *sparow = new Sparrow();
	ToyDuck *birdAdapter = new BirdAdapter(sparow);
	
	PlasticToyduck toyDuck;
	
	std::cout << "Sparrow..." << std::endl;
    sparow->fly();
    sparow->makeSound();
    
    std::cout << "ToyDuck..." << std::endl;
    toyDuck.squake();
	
	cout << "Bird Adapter" <<endl;
	birdAdapter->squake();
	
	
	
	return 0;
}
