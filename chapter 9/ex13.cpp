/*Design and implement a rational number class, Rational. A rational
number has two parts: a numerator and a denominator, for example, 5/6 
(five-sixths, also known as approximately .83333). Look up the definition
if you need to. Provide assignment, addition, subtraction, multiplication,
division, and equality operators. Also, provide a conversion to double.
Why would people want to use a Rational class?*/

#include "../../std_lib_facilities.h"

class rational {
	class Invalid { };
	int numerator;
	int denominator;
public:
	rational(int a, int b)
		:numerator{ a }, denominator{ b } {
		if (b == 0) throw Invalid{}; }
	int num() const { return numerator; };
	int dem() const { return denominator; };
	void printt() const;
	double rat2double() const;
};

void rational::printt() const{
	cout << numerator << "/" << denominator << '\n';
}

double rational::rat2double() const{
	double n = double(numerator) / double(denominator);
	return n;
}

bool operator==(const rational& a, const rational& b) {
	int aa = a.num() * b.dem();
	int bb = b.num() * a.dem();
	//cout << aa << bb << "its work" << (aa == bb)  << '\n';
	return (aa == bb);
}

bool operator !=(const rational& a, const rational& b) {
	return !(a == b);
}

int main() {
	cout << "hello" << '\n';
	rational half{ 1,3 };
	rational half4{ 3,6 };
	bool test{ half != half4 };
	if (test) {
		cout << half.rat2double() << '\n';
	}
	cout << test;
}