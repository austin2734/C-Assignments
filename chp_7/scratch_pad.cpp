#include<iostream>
using namespace std;

class Package
{
private:
	int value{};
public:
	Package()
		{ value = 7; cout << value << endl;}
	Package(int v)
		{ value = v; cout << value << endl;}
	~Package()
		{ cout << "Good-bye world :(" << endl;}
	int getValue() {
		return value; // does not return anything as obj was deconstructed.
	}
};

int main(){

	Package obj1(4);
	Package obj2;

	cout << obj1.getValue();

	string word = "Hello";
	cout << "Word Lenght: " << word.size();


}