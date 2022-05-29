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
	bool Normolize();

	int GetNumerator()const;
	int GetDenominator()const;
	double ToDouble()const;

	CRational operator + ();
	CRational operator - ();

private:
	int m_numerator;
	int m_denominator;
};

CRational operator+(CRational number1, CRational number2);