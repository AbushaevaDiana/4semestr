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

int GreatestCommonDivisor(int a, int b)
{
	while (a > 0 && b > 0)

		if (a > b)
			a %= b;

		else
			b %= a;

	return a + b;
}

bool CRational::Normolize()
{
	if (m_denominator == 0)
	{
		m_numerator = 0;
		m_denominator = 1;

		return true;
	}

	int divisor = GreatestCommonDivisor(m_numerator, m_denominator);

	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}

	m_numerator /= divisor;
	m_denominator /= divisor;

	return true;

}

CRational::CRational(int numerator, int denominator) :
	m_numerator(numerator),
	m_denominator(denominator)
{
	Normolize();
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
	return m_numerator/m_denominator;
}

CRational CRational::operator+()
{
	return CRational(m_numerator, m_denominator);
}

CRational CRational::operator-()
{
	m_numerator *= -1;
	return CRational(m_numerator, m_denominator);
}

CRational operator+(CRational number1, CRational number2)
{

}