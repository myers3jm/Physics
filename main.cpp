#include "Formula.h"
#include "Body.h"
#include "Vector3.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
	//std::vector<char> variables = { 'x', 'y' };

	Formula formula = Formula("2 + 3");
	std::vector<char> expression = formula.getExpression();
	char result;
	formula.evaluate(expression, result);
	std::cout << result;

}