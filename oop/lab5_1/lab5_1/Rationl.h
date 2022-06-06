#include <iostream>

class CRational
{
public:
	CRational();
	CRational(int value);

	// ������������ ������������ �����, ������ numerator/denominator
	// ������������ ����� ������ ��������� � ��������������� ����:
	//	����������� ������������� (��������� ����� ���� �������������)
	//	��������� � ����������� �� ����� ����� ��������� (6/8 => 3/4 � �.�.)
	// ���� ����������� ����� ����, ������ ����������������� ������������ �����, ������ ����,
	// ���� ������ ���� ��������� ���������� std::invalid_argument.
	CRational(int numerator, int denominator);
	
	int GetNumerator()const;
	int GetDenominator()const;
	double ToDouble()const;

	CRational const operator + () const;
	CRational const operator - () const;
	CRational& operator+=(const CRational& number);
	CRational& operator-=(const CRational& number);
	CRational& operator*=(const CRational& number);
	CRational& operator/=(const CRational& number);

	std::pair<int, CRational> ToCompoundFraction()const;

private:
	int m_numerator;
	int m_denominator;
	//void, � �� bool +
	void Normalize();

};

//���������� �� ��������, � �� ��������� +
CRational operator+(const CRational& number1, const CRational& number2);
CRational operator-(const CRational& number1, const CRational& number2);

CRational operator*(const CRational& number1, const CRational& number2);
CRational operator/(const CRational& number1, const CRational& number2);

bool operator==(const CRational& number1, const CRational& number2);
bool operator!=(const CRational& number1, const CRational& number2);

bool operator<(const CRational& number1, const CRational& number2);
bool operator>(const CRational& number1, const CRational& number2);

bool operator<=(const CRational& number1, const CRational& number2);
bool operator>=(const CRational& number1, const CRational& number2);


std::istream& operator >>(std::istream& inStream, CRational& number);
std::ostream& operator <<(std::ostream& outStream, const CRational& number);

//���� � ����������� ����������
int GetLeastCommonMultiplier(int a, int b);
int GreatestCommonDivisor(int a, int b);