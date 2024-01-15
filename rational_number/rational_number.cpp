#include <iostream>
#include <sstream>
#include"rational_number.h"

inline std::ostream& operator<<(std::ostream& ostrm, const rational_number& rhs)
{
	return rhs.write_to(ostrm);
}
inline  std::istream& operator>>(std::istream& istrm, rational_number& rhs)
{
	return rhs.read_from(istrm);
}
rational_number::rational_number(const int numerator)
	:num(numerator)
	, den(1)
{
}
rational_number::rational_number(const int numerator, const int denomirator)
	: num(numerator)
{
	if (denomirator != 0)
	{
		den = denomirator;
	}
	else
	{
		setlocale(LC_ALL, "ru");
		std::cout << "Знаменатель не может быть равен нулю";
	}
	reduction();
}
rational_number& rational_number::operator=(const rational_number& rhs)
{
	num = rhs.num;
	den = rhs.den;
	reduction();
	return *this;
}
rational_number& rational_number::operator=(const int rhs)
{
	return operator=(rational_number(rhs));
}
rational_number& rational_number::operator+=(const rational_number& rhs)
{
	num = num * rhs.den + rhs.num * den;
	den *= rhs.den;
	reduction();
	return *this;
}
rational_number& rational_number::operator+=(const int rhs)
{
	return operator+=(rational_number(rhs));
}
rational_number& rational_number::operator-=(const rational_number& rhs)
{
	num = num * rhs.den - rhs.num * den;
	den *= rhs.den;
	reduction();
	return *this;
}
rational_number& rational_number::operator-=(const int rhs)
{
	return operator-=(rational_number(rhs));
}
rational_number& rational_number::operator*=(const rational_number& rhs)
{
	num *= rhs.num;
	den *= rhs.den;
	reduction();
	return *this;
}
rational_number& rational_number::operator*=(const int rhs)
{
	return operator*=(rational_number(rhs));
}
rational_number& rational_number::operator/=(const rational_number& rhs)
{
	num *= rhs.den;
	den *= rhs.num;
	reduction();
	return *this;
}
rational_number& rational_number::operator/=(const int rhs)
{
	return operator/=(rational_number(rhs));
}
rational_number operator+(const rational_number& lhs, const rational_number& rhs)
{
	rational_number sum(lhs);
	sum += rhs;
	return sum;
}
rational_number operator-(const rational_number& lhs, const rational_number& rhs)
{
	rational_number diff(lhs);
	diff -= rhs;
	return diff;
}
rational_number operator*(const rational_number& lhs, const rational_number& rhs)
{
	rational_number prod(lhs);
	prod *= rhs;
	return prod;
}
rational_number operator/(const rational_number& lhs, const rational_number& rhs)
{
	rational_number quot(lhs);
	quot /= rhs;
	return quot;
}
void rational_number::reduction()
{
	if ((num != 0) && (den != 0))
	{
		int k = num % den;
		int div = 1;
		if (k != 0)
		{
			int n = num;
			int d = den;
			while (k != 0)
			{
				n = d; d = k;
				k = n % d;
			}
			div = d;
		}
		num /= div;
		den /= div;
	}
}
std::ostream& rational_number::write_to(std::ostream& ostrm) const
{
	ostrm << left_brace << num << separator << den << right_brace;
	return ostrm;
}
std::istream& rational_number::read_from(std::istream& istrm)
{
	char LeftBrace(0);
	char RightBrace(0);
	char slash(0);
	int numerator(0);
	int denomirator(0);
	istrm >> LeftBrace >> numerator >> slash >> denomirator >> RightBrace;
	if (istrm.good())
	{
		if ((rational_number::left_brace == LeftBrace) && (rational_number::separator == slash) && (rational_number::right_brace))
		{
			num = numerator;
			den = denomirator;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
bool test_parse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	rational_number z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success:    " << str << "->" << z << endl;
	}
	else
	{
		cout << "Read error:      " << str << "->" << z << endl;
	}
	return istrm.good();
}

