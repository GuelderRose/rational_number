#pragma once
#include<iostream>
#include<sstream>

class rational_number
{
public:
	rational_number() {};
	explicit rational_number(const int numerator);
	rational_number(const int numerator, const int denomirator);

	bool operator==(const rational_number& rhs) { return (num == rhs.num) && (den == rhs.den); };
	bool operator!=(const rational_number& rhs) { return !(operator==(rhs)); };
	rational_number& operator=(const rational_number& rhs);
	rational_number& operator=(const int rhs);
	rational_number& operator+=(const rational_number& rhs);
	rational_number& operator+=(const int rhs);
	rational_number& operator-=(const rational_number& rhs);
	rational_number& operator-=(const int rhs);
	rational_number& operator*=(const rational_number& rhs);
	rational_number& operator*=(const int rhs);
	rational_number& operator/=(const rational_number& rhs);
	rational_number& operator/=(const int rhs);
	void reduction();
	std::ostream& write_to(std::ostream& ostrm) const;
	std::istream& read_from(std::istream& istrm);
	static const char left_brace{ '{' };
	static const char separator{ '/' };
	static const char right_brace{ '}' };
private:
	int num{ 0 };
	int den{ 1 };
};
inline std::ostream& operator<<(std::ostream& ostrm, const rational_number& rhs);
inline  std::istream& operator>>(std::istream& istrm, rational_number& rhs);
rational_number operator+(const rational_number& lhs, const rational_number& rhs);
rational_number operator-(const rational_number& lhs, const rational_number& rhs);
rational_number operator*(const rational_number& lhs, const rational_number& rhs);
rational_number operator/(const rational_number& lhs, const rational_number& rhs);
bool test_parse(const std::string& str);

