#pragma once

#include <vector>
#include <math.h>
#include <string>

// A class for storing a formula from a string
class Formula
{
private:
	std::vector<char> variables;
	std::string equation;
	std::vector<char> expression;
public:
	// Default constructor
	Formula() : variables(), equation() {
	}

	// No variables constructor
	Formula(std::string _equation) : equation(_equation) {
		for (char c : _equation) {
			expression.push_back(c);
		}
	}

	// Full constructor
	Formula(std::vector<char> _variables, std::string _equation) : variables(_variables), equation(_equation) {
		for (char c : _equation) {
			expression.push_back(c);
		}
	}

	// Evaluation
	/* Returns true if the expression is successfully evaluated
	*/
	bool evaluate(std::vector<char>& _expression, char& result);

	// Encapsulation
	std::vector<char> getVariables();
	void setVariables(std::vector<char> _variables);
	std::string getEquation();
	void setEquation(std::string _equation);
	std::vector<char> getExpression();
	void setExpression(std::vector<char> _expression);

};

