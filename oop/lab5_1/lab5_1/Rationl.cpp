#include "Rationl.h"

CRational::CRational() :
	m_numerator(0),
	m_denominator(1)
{
}

CRational::CRational(int value) :
	m_numerator(value),
	m_denominator(1)
{
}

int GetLeastCommonMultiplier(int a, int b)
{
	return a * b / GreatestCommonDivisor(a, b);
}

int GreatestCommonDivisor(int a, int b)
{
	if (a < 0)
	{
		a *= -1;
	}
	if (b < 0)
	{
		b *= -1;
	}

	while (a > 0 && b > 0)
	{
		if (a > b)
			a %= b;

		else
			b %= a;
	}

	return a + b;
}

void CRational::Normalize()
{
	int divisor = GreatestCommonDivisor(m_numerator, m_denominator);

	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}

	m_numerator /= divisor;
	m_denominator /= divisor;
}

CRational::CRational(int numerator, int denominator) :
	m_numerator(numerator),
	m_denominator(denominator)
{
	if (m_denominator == 0)
	{
		m_denominator = 1;
		m_numerator = 0;
	}
	else
	{
		Normalize();
	}
		
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}

CRational const CRational::operator+() const
{
	return CRational(m_numerator, m_denominator);
}

CRational const CRational::operator-() const
{
	return CRational(m_numerator*(-1), m_denominator);
}

CRational& CRational::operator+=(const CRational& number)
{
	*this = *this + number;
	return *this;
}

CRational& CRational::operator-=(const CRational& number)
{
	*this = *this - number;
	return *this;
}

CRational& CRational::operator*=(const CRational& number)
{
	*this = *this * number;
	return *this;
}

CRational& CRational::operator/=(const CRational& number)
{
	*this = *this / number;
	return *this;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int intPart = m_numerator/ m_denominator;
	return std::pair<int, CRational>(intPart, CRational(m_numerator - (intPart * m_denominator), m_denominator));
}

CRational operator+(const CRational& number1, const CRational& number2)
{
	//перепутаны местами множители +
	int multiplier = GetLeastCommonMultiplier(number1.GetDenominator(), number2.GetDenominator());
	return CRational(number1.GetNumerator() * (multiplier / number1.GetDenominator()) + number2.GetNumerator() * (multiplier / number2.GetDenominator()),
		multiplier);
}

CRational operator-(const CRational& number1, const CRational& number2)
{
	//перепутаны местами множители +
	int multiplier = GetLeastCommonMultiplier(number1.GetDenominator(), number2.GetDenominator());
	return CRational(number1.GetNumerator() * (multiplier / number1.GetDenominator()) - number2.GetNumerator() * (multiplier / number2.GetDenominator()),
		multiplier);
}

CRational operator*(const CRational& number1, const CRational& number2)
{
	return CRational(number1.GetNumerator() * number2.GetNumerator(), number1.GetDenominator() * number2.GetDenominator());
}

CRational operator/(const CRational& number1, const CRational& number2)
{
	return CRational(number1.GetNumerator() * number2.GetDenominator(), number1.GetDenominator() * number2.GetNumerator());
}

bool operator==(const CRational& number1, const CRational& number2)
{
	return (number1.ToDouble() == number2.ToDouble());
}

bool operator!=(const CRational& number1, const CRational& number2)
{
	return (number1.ToDouble() != number2.ToDouble());
}

bool operator<(const CRational& number1, const CRational& number2)
{
	return (number1.ToDouble() < number2.ToDouble());
}

bool operator>(const CRational& number1, const CRational& number2)
{
	return (number1.ToDouble() > number2.ToDouble());
}

bool operator<=(const CRational& number1, const CRational& number2)
{
	return (number1.ToDouble() <= number2.ToDouble());
}

bool operator>=(const CRational& number1, const CRational& number2)
{
	return (number1.ToDouble() >= number2.ToDouble());
}

std::istream& operator>>(std::istream& inStream, CRational& number)
{
	int numerator;
	int denominator;
	if (inStream >> numerator && inStream.get() == '/' && inStream >> denominator)
	{
		number = CRational(numerator, denominator);
	}
	else
	{
		inStream.setstate(std::ios_base::failbit);
	}
	return inStream;
}

std::ostream& operator <<(std::ostream& outStream, const CRational& number)
{
	outStream << number.GetNumerator() << "/" << number.GetDenominator();
	return outStream;
}
