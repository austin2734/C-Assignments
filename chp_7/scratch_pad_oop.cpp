#include<iostream>
#include<cmath>
using namespace std;
class Circle
{
	private:
		double radius{};
		const double Pi = 3.14159265359;
	public:
		void setRadius(double r)
		{ radius = r; }
		double calcArea()
		{ return Pi * pow(radius,2); }

};

class Pizza
{
	private:
		double price{};
		Circle size;
	public:
		void setPrice(double p)
		{ price = p; }
		void setSize(double r)
		{ size.setRadius(r); }
		double costPerSquareIn()
		{ return price / size.calcArea();}
};

int main()
{

Circle myCircle;

myCircle.setRadius(4);
cout << "The area of my circle is: " << myCircle.calcArea() << endl << endl << endl;

Pizza myPizza;

myPizza.setPrice(20.00);
myPizza.setSize(6);
cout << "The cost per square inch for my pizza is: " << myPizza.costPerSquareIn();

}