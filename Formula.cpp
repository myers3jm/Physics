#include "Formula.h"
#include "Utilities/utilities.h"

std::vector<char> Formula::getVariables() {
	return variables;
}
void Formula::setVariables(std::vector<char> _variables) {
	variables = _variables;
}
std::string Formula::getEquation() {
	return equation;
}
void Formula::setEquation(std::string _equation) {
	equation = _equation;
}
std::vector<char> Formula::getExpression() {
	return expression;
}
void Formula::setExpression(std::vector<char> _expression) {
	expression = _expression;
}

bool Formula::evaluate(std::vector<char>& _expression, char& result) {
	// Load contents of equation to expression vector
	for (char c : Formula::equation) {
		_expression.push_back(c);
	}

	// Check format of expression

	// Balanced parentheses
	std::vector<char> v;
	for (char c : _expression) {
		if (c == '(') {
			v.push_back(c);
		}
		else if (c == ')') {
			if (v.empty()) {
				return false;
			}
			else {
				if (v.back() == '(' && c == ')') {
					v.pop_back();
				}
				else {
					return false;
				}
			}
		}
	}
	if (!v.empty()) {
		return false;
	}

	// Check to see if any undeclared variables are present
	for (char c : _expression) {
		if (!(isElementOf(_expression, c))) {
			return false;
		}
	}

	// Solve the expression
	
	// Store constants for the expected characters
	const std::vector<char> NUMBERS = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	const std::vector<char> ARITHMETIC_OPERATORS = { '+', '-', '*', '/' };

	// Create vector to store characters from the expression
	std::vector<char> stack;

	// Parentheses first
	for (int i = 0; i < sizeof(_expression); i++) {
		// Spaces
		if (_expression[i] == ' ') {
			continue;
		}
		// Push to stack if number
		if (isElementOf(NUMBERS, _expression[i])) {
			stack.push_back(_expression[i]);
		}
		// If arithmetic operator and next character not a parenthese
		else if (isElementOf(ARITHMETIC_OPERATORS, _expression[i]) && _expression[i + 1] != '(' && _expression[i + 1] != ')') {
			// Get operands of current operator and remove from respective vectors
			char a = stack.back();
			stack.pop_back();
			char b = _expression[i + 1];
			_expression.erase(_expression.begin() + (i + 1));
			// Operator cases
			if (_expression[i] == '+') {
				int sum = static_cast<int>(a) + static_cast<int>(b); // TODO: Add possibility for floating point values
				stack.push_back(sum); // ONLY WORKS FOR SUMS UNDER 10
			}
		}
		
	}
	result = stack.back();
	return true;




}