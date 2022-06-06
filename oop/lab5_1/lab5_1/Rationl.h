#include <iostream>

class CRational
{
public:
	CRational();
	CRational(int value);

	// Конструирует рациональное число, равное numerator/denominator
	// Рациональное число должно храниться в нормализованном виде:
	//	знаменатель положительный (числитель может быть отрицательным)
	//	числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
	// Если знаменатель равен нулю, должно сконструироваться рациональное число, равное нулю,
	// либо должно быть выброшено исключение std::invalid_argument.
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
	//void, а не bool +
	void Normalize();

};

//возвращать по значению, а не константу +
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

//есть в стандартной библиотеке
int GetLeastCommonMultiplier(int a, int b);
int GreatestCommonDivisor(int a, int b);