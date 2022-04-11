#include <string>
#include <vector>
#include <map>
#include <functional>
#include <optional>
#include <iomanip>
//#include "CalculatorException.h"


enum class Action {
	Plus,
	Sub,
	Div,
	Mult,
	None,
};

class Calculator
{
public:
	Calculator();
	bool AddVar(const std::string& name);
	bool LetVar(const std::string& name, double value);

	std::function<double()> CreateBinaryFunctionCallback(const std::string& operand1, const std::string& operand2, Action sign) const;

	std::function<double()> CreateUnaryFunctionCallback(const std::string& operand) const;

	void AddFunction(const std::string& name, std::function<double()> callback);

	double GetVarValue(const std::string& name) const;

	double CalculateFunction(const std::string& name) const;

	std::map<std::string, std::function<double()>> GetFunctionsMap() const;

	std::map<std::string, double> GetVarsMap() const;

	double GetExpressionValue(const std::string& expression) const;

private:
	std::map<std::string, double> m_varsMap;
	std::map<std::string, std::function<double()>> m_fnMap;
	mutable std::map<std::string, double> m_calculatedFnMap;

	double GetFuntionValue(const std::string& name) const;
	bool CheckExistName(const std::string& name) const;
	bool CheckExistVarName(const std::string& name) const;
	bool CheckExistFunctionName(const std::string& name) const;
	bool CheckValidName(const std::string& name) const;
	bool CheckIsDoubleValue(const std::string& expression) const;
};
