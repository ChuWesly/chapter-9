/*Exercise 2 of chapter 9*/

#include "../../std_lib_facilities.h"

class Name_pairs {
	vector<string> name;
	vector<double> age;
public:
	Name_pairs() :
		name{"test"} {};
	void print();
	void read_names(istream& input);
	void read_ages(istream& input);
};

void Name_pairs::read_names(istream& input) {
	string n;
	while (input >> n) {
		
		name.push_back(n);
	}
}

void Name_pairs::read_ages(istream& input) {
	double n;
	while (input >> n) {
		age.push_back(n);
	}
}

void Name_pairs::print() {
	for (string i : name) {
		cout << i << '\n';
	}
}

int main() {
	Name_pairs test{};
	istream& input = cin;
	test.read_names(input);
	test.print();

}