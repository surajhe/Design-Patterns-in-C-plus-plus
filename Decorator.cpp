
// Please create a class diagram and code for a Coffee Maker with the following set of requirements.

// There is a class called CoffeeRequest which contains 
// Every pizza has a name and a description.
// We need to get the cost and description of constituents of the pizza.
// There are 4 base pizzas on which toppings can be added later, if needed by the customer. These pizzas, along with their costs, are:
// Farmhouse - Rs. 150
// Margherita - Rs. 200
// Pepperoni - Rs. 180
// BBQChicken - Rs. 200
// There are 4 types of toppings that are supported. A customer may want to add any quantity of them (Eg: They may want to add Olives twice). The toppings, along with their costs, are:
// Olive - Rs. 20
// Tomato - Rs. 30
// Cheese - Rs. 80
// Paneer - Rs. 60

// Your class diagram, when implemented, should be able to successfully compile and run for following code:

// Pizza p = new Paneer(new Cheese(new Tomato(new BBQChicken())));
// System.out.printLn(p.getCost()); // should output 370
// System.out.printLn(p.getDescription()); // should output BBChicken +            Tomato + Cheese + Paneer


// Please create your class diagrams on draw.io, push the code to Github and submit the assignment by filling this form.


// It allows adding new behaviors to objects dynamically by placing them inside special wrapper object, called decorators.
// Decorators provide flexible alternatives to subclassing for extending functionality.


#include <iostream>
using namespace std;


class Pizza
{
	public :
		virtual int cost() = 0;
		virtual string description() = 0;
		
		virtual ~Pizza()
		{
			
		}
};

class Farmhouse : public Pizza
{
	public:
		virtual int cost()
		{
			return 150;
		}
		
		virtual string description()
		{
			return "Farmhouse";
		}
	
};

class Margherita : public Pizza
{
	public:
		virtual int cost()
		{
			return 200;
		}
		
		virtual string description()
		{
			return "Margherita";
		}
	
};

class Pepperoni : public Pizza
{
	public:
		virtual int cost()
		{
			return 180;
		}
		
		virtual string description()
		{
			return "Pepperoni";
		}
	
};

class BBQChicken : public Pizza
{
	public:
		virtual int cost()
		{
			return 200;
		}
		
		virtual string description()
		{
			return "BBQChicken";
		}
	
};

class ToppingDecorator : public Pizza
{
	
	
};

class cheezeTopping : public ToppingDecorator
{
	Pizza& m_pizza;
	
	public:
		cheezeTopping(Pizza& pizza):m_pizza(pizza)
		{
		}
		
		virtual int cost()
		{
			return m_pizza.cost() + 80;
		}
		
		virtual string description()
		{
			return m_pizza.description() + "  Cheeze";
		}
		
};

class OliveTopping : public ToppingDecorator
{
	Pizza& m_pizza;
	
	public:
		OliveTopping(Pizza& pizza):m_pizza(pizza)
		{
		}
		
		virtual int cost()
		{
			return m_pizza.cost() + 20;
		}
		
		virtual string description()
		{
			return m_pizza.description() + "  Olive";
		}
};

class TomatoTopping : public ToppingDecorator
{
	Pizza& m_pizza;
	
	public:
		TomatoTopping(Pizza& pizza):m_pizza(pizza)
		{
		}
		
		virtual int cost()
		{
			return m_pizza.cost() + 30;
		}
		
		virtual string description()
		{
			return m_pizza.description() + "  Tomato";
		}
};

class PaneerTopping : public ToppingDecorator
{
	Pizza& m_pizza;
	
	public:
		PaneerTopping(Pizza& pizza):m_pizza(pizza)
		{
		}
		
		virtual int cost()
		{
			return m_pizza.cost() + 60;
		}
		
		virtual string description()
		{
			return m_pizza.description() + "  Paneer";
		}
};




int main() {
	// your code goes here
	
	// Pizza *p = new PaneerTopping(*(new cheezeTopping(*(new TomatoTopping(*(new BBQChicken()))))));
	// cout << p->cost() << endl;
	// cout << p->description();
	
	Pizza* p = new BBQChicken();
	cout << p->cost() << endl;
	cout << p->description() << endl;
	
	Pizza* tomatoTopping = new TomatoTopping(*p);
	cout << tomatoTopping->cost() << endl;
	cout << tomatoTopping->description() << endl;
	
	Pizza* chezeTopping = new cheezeTopping(*tomatoTopping);
	cout << chezeTopping->cost() << endl;
	cout << chezeTopping->description() << endl;
	
	Pizza* paneerTopping = new PaneerTopping(*chezeTopping);
	cout << paneerTopping->cost() << endl;
	cout << paneerTopping->description() << endl;
	
	return 0;
} 
