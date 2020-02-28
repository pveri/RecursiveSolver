#include <iostream>
#include "RecursiveSolver.h"
using namespace std;

int main(char* argsv) {
	 const unsigned int* data = new unsigned int[100]
										{ 0,0,0,0,0,0,0,0,0,0
										 ,0,3,6,4,0,0,0,0,0,0
										 ,0,1,0,10,0,0,0,2,5,0
										 ,0,0,0,0,9,0,0,10,6,0
										 ,0,0,0,0,3,0,0,0,2,0
										 ,0,0,0,0,5,0,0,0,0,0
										 ,0,0,0,0,4,10,0,0,0,0
										 ,0,12,16,0,0,0,0,0,0,0
										 ,0,0,0,0,0,0,13,14,0,0
										 ,0,0,0,0,0,0,16,0,0,0 
										};

	 RecursiveSolver r = RecursiveSolver(
		 data, 100, 10
	 );

	 cout << r.count(2, 9) << endl;
	return 0;
}