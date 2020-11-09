#include "../../std_lib_facilities.h"

enum class Month {
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};
Month operator++(Month& m) // prefix increment operator
{
	m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1); // “wrap around”
	return m;
}

class Date {
public:
	class Invalid {};
	Date();
	Date(int year, Month month, int day);
	int day() const { return d; } // const member: can’t modify the object
	Month month() const { return m; } // const member: can’t modify the object
	int year() const { return y; } // const member: can’t modify the object
	void add_day(int n); // non-const member: can modify the object
	void add_month(int n); // non-const member: can modify the object
	void add_year(int n); // non-const member: can modify the object
private:
	int y; // year
	Month m;
	int d; // day of month
	bool is_valid();
};

void Date::add_day(int n) {
	int mm = n / 31;
	d += n;
	if (d > 31) {
		d %= 31;
		++mm;
	}
	add_month(mm);
}

void Date::add_month(int n) {
	int yy = n / 12;
	int mm = int(m)+ n;
	if (mm > 12) {
		mm %= 12;
		m = Month(mm);
	}
	add_year(yy);
}

void Date::add_year(int n) {
	y += n;
}

Date::Date() 
	:y{1978}, m{Month::Jan}, d{1} {}

Date::Date(int yy, Month mm, int dd)
	:y{yy}, m{mm}, d{dd} 
{
	if (!is_valid()) throw Invalid{}; // check for validity
}

bool Date::is_valid() // return true if date is valid
{	
	if (y < 1900 || 2100 < y) return false;
	if (int(m) < 1 || 12 < int(m)) return false;
	if (d < 1 || 31 < d) return false;
	else return true;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << int(m);
}
ostream& operator<<(ostream& os, Date date)
{
	return os << date.year() << "-" << date.month() << "-" << date.day();
}

int main() 
try {
	cout << "hello";
	Date birthday{ 1900, Month(12), 30 }; // OK
	//birthday.m = 14; // error: Date::m is private
	cout << birthday << '\n'; // we provided a way to read m
	//Month tt{ Month::Nov};
	//cout << int(tt) << '\n'; // moth read out
	//++tt;
	//Month& kk = tt;
	//++kk;
	birthday.add_month(25);
	cout << birthday << '\n'; // moth read out
}
catch (Date::Invalid) {
	error("invalid date"); // error() defined in §5.6.3
}