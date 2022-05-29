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