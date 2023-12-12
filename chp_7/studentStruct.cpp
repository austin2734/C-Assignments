#include<iostream>
using namespace std;

struct Student
{
	int id{}, entry_year{};
	double gpa{};
};

int main()
{
	Student s1, s2;

	s1 = {1234, 2008, 3.41};
	s2 = {5678, 2010};

	cout << "Student1 ID: "  << s1.id << " entry year: " << s1.entry_year << " GPA: " << s1.gpa << endl;
	cout << "Student2 ID: " << s2.id << " entry year: " << s2.entry_year << " GPA: " << s2.gpa;
}
