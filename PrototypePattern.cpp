#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Prototype Design Pattern - creational design pattern

// concept is to copy an existing object instead of creating new one.
// the existing object ascts as prototype and contains state of abject.
// when object creation time is consuming and costly operation so we create 
// objects from the existing objects.

class Car
{
	private:
		string model;
		string color;
	
	public:
		Car(string m, string c):
		model(std::move(m)),
		color(std::move(c)){};
		
		void setColor(string color)
		{
			color = std::move(color);
		}
		
		virtual std::unique_ptr<Car> clone() = 0;
};

class RaceCar:public Car
{
	private:
		int speed;
		
	public:
		RaceCar(string m, string c, int spd):
		Car(std::move(m), std::move(c)), speed(spd){};
		
		std::unique_ptr<Car> clone() override
		{
			return std::make_unique<RaceCar>(*this);
		}
};

int main() {
	// your code goes here
	
	auto prototype = std::make_unique<RaceCar>("Car", " ", 100);
	auto redCar = prototype->clone();
	redCar->setColor("red");
	
	auto blueCar = prototype->clone();
	redCar->setColor("blue");
	
	
	return 0;
}
