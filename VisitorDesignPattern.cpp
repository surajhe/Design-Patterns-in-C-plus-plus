#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Visitor design pattern
// we can add new behaviour to existing object without modifying the existing code.
// It is a way of separating an algorithm from an object structure.

// method called visit() is implemented by the visitor and is called for every element 
// in the data structure.
// visitable classes providing Accept() methods that accept a visitor.

class ComponentA;
class ComponentB;
class ComponentC;

class Visitor
{
	public:
	virtual void visitComponentA(const ComponentA *elem) = 0;
	virtual void visitComponentB(const ComponentB *elem) = 0;
	virtual void visitComponentC(const ComponentC *elem) = 0;
};

class Component
{
	public:
	virtual void Accept(Visitor *visit) = 0;
	virtual ~Component(){};
};

class ComponentA: public Component
{
	public:
		virtual void Accept(Visitor *visit) 
		{
			visit->visitComponentA(this);
		}
		
	std::string componentAFunc()
	{
		return "ComponentA";
	}
	
};

class ComponentB: public Component
{
	public:
		virtual void Accept(Visitor *visit) 
		{
			visit->visitComponentB(this);
		}
		
		std::string componentBFunc()
		{
			return "ComponentB";
		}
	
};

class ComponentC: public Component
{
	public:
		virtual void Accept(Visitor *visit) 
		{
			visit->visitComponentC(this);
		}
		
	std::string componentCFunc()
	{
		return "ComponentC";
	}
	
};

class Visitor1:public Visitor
{
	public:
	void VisitComponentA(ComponentA *elem) 
	{
		cout << "Visited  " << elem->componentAFunc() <<endl;	
	}
	
	void VisitComponentB(ComponentB *elem) 
	{
		cout << "Visited  " << elem->componentBFunc() <<endl;	
	}
	
	void VisitComponentC(ComponentC *elem) 
	{
		cout << "Visited  " << elem->componentCFunc() <<endl;	 
	}
};

class Visitor2:public Visitor
{
	public:
	void VisitComponentA(ComponentA *elem) 
	{
		cout << "Visited  " << elem->componentAFunc() <<endl;	
	}
	
	void VisitComponentB(ComponentB *elem) 
	{
		cout << "Visited  " << elem->componentBFunc() <<endl;	
	}
	
	void VisitComponentC(ComponentC *elem) 
	{
		cout << "Visited  " << elem->componentCFunc() <<endl;	
	}
};


int main() {
	
	std::vector<Component*>components{new ComponentA, new ComponentB, new ComponentC};
	
	Visitor1 *v1 = new Visitor1();
	Visitor2 *v2 = new Visitor2();
	
	for(const Component* comp : components)
	{
		comp->Accept(v1);
	}
	
	for(const Component* comp : components)
	{
		comp->Accept(v2);
	}
	
	// your code goes here
	return 0;
}
