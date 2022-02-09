#pragma once
#include <vector>

// isElementOf

// int
bool isElementOf(std::vector<int>& v, int e) {
	if (!(std::find(v.begin(), v.end(), e) != v.end())) {
		return false;
	}
}

// double
bool isElementOf(std::vector<double>& v, double e) {
	if (!(std::find(v.begin(), v.end(), e) != v.end())) {
		return false;
	}
	return true;
}

// char
bool isElementOf(std::vector<char>& v, char e) {
	if (!(std::find(v.begin(), v.end(), e) != v.end())) {
		return false;
	}
	return true;
}

// const int
bool isElementOf(const std::vector<int>& v, int e) {
	if (!(std::find(v.begin(), v.end(), e) != v.end())) {
		return false;
	}
}

// const double
bool isElementOf(const std::vector<double>& v, double e) {
	if (!(std::find(v.begin(), v.end(), e) != v.end())) {
		return false;
	}
	return true;
}

// const char
bool isElementOf(const std::vector<char>& v, char e) {
	if (!(std::find(v.begin(), v.end(), e) != v.end())) {
		return false;
	}
	return true;
}
