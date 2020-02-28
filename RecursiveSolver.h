#pragma once
#include <iostream>
#include <vector>

class RecursiveSolver {
public:
	RecursiveSolver();
	RecursiveSolver(const unsigned int* data, int arrayLen, int width);
	unsigned int sum(unsigned int lowerBound, unsigned int upperBound, int row, int col);
	unsigned int count(unsigned int lowerBound, unsigned int upperBound);
private:
	std::vector<std::vector<unsigned int>> _arr;
};
