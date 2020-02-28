#ifndef __RECURSE__H
#include "RecursiveSolver.h"
#endif // !__RECURSE__H


RecursiveSolver::RecursiveSolver() {
	_arr = std::vector<std::vector<unsigned int>>();
}

RecursiveSolver::RecursiveSolver(const unsigned int* data, int arrayLen, int width) {
	_arr = std::vector<std::vector<unsigned int>>();
	unsigned int rows = arrayLen / width;

	for (unsigned int i = 0; i < rows; i++) {
		std::vector<unsigned int> _tmpVec = std::vector<unsigned int>();
		for (unsigned int y = 0; y < width; y++)
		{
			_tmpVec.push_back(*data++);
		}
		_arr.push_back(_tmpVec);
	}
}

unsigned int RecursiveSolver::sum(unsigned int lowerBound, unsigned int upperBound, int row, int col) {
	unsigned int val = _arr[row][col];

	if (val != 0 && val > lowerBound && val < upperBound)
	{
		_arr[row][col] = 0;
		return val + sum(lowerBound, upperBound, row - 1, col) + sum(lowerBound, upperBound, row + 1, col)
			+ sum(lowerBound, upperBound, row, col - 1) + sum(lowerBound, upperBound, row, col + 1);
	}
	return 0;
}

unsigned int RecursiveSolver::count(unsigned int lowerBound, unsigned int upperBound) {
	int count = 0;
	for (int i = 0; i < _arr[0].size(); i++) {
		for (int y = 0; y < _arr.size(); y++) {
			if (sum(lowerBound, upperBound, i, y)) count++;
		}
	}
	return count;
}

/*

{ 0,0,0,0,0,0,0,0,0,0
,0,3,6,4,0,0,0,0,0,0
,0,1,0,10,0,0,0,2,5,0
,0,0,0,0,9,0,0,10,6,0
,0,0,0,0,3,0,0,0,2,0
,0,0,0,0,5,0,0,0,0,0
,0,0,0,0,4,10,0,0,0,0
,0,12,16,0,0,0,0,0,0,0
,0,0,0,0,0,0,13,14,0,0
,0,0,0,0,0,0,16,0,0,0 }
*/