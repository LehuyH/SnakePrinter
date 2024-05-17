# SnakePrinter
The easiest way to print a matrix in snake form in C++

## Quickstart
```c++
#include "Snaker.hpp"

using namespace std;

int main()
{

	const int ROWS = 4;
	const int COLS = 4;

		int myArray[ROWS][COLS] = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	{13, 14, 15, 16}
};


	SnakePrinter printer(myArray,ROWS,COLS);
	printer.print();


	return EXIT_SUCCESS;
}```
