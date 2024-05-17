#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

template <typename T>
int getDigitCount(T e)
{
    return std::to_string(e).length();
}

template <>
int getDigitCount(std::string e)
{
    return (e).length();
}

template <typename T>
class SnakePrinter
{
private:
    T *array;
    int ROWS = 0;
    int COLS = 0;

public:
    SnakePrinter(T *array, int ROWS, int COLS)
    {
        this->array = array;
        this->ROWS = ROWS;
        this->COLS = COLS;
    }

    void print() const
    {
        if (ROWS == 0 && COLS == 0)
            return;

        int digitCount = getDigitCount(array[0][0]);

        for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
        {
            for (int colIndex = 0; colIndex < COLS; colIndex++)
            {
                int colDigitCount = getDigitCount(array[rowIndex][colIndex]);
                if (digitCount < colDigitCount)
                {
                    digitCount = colDigitCount;
                }
            }
        }

        for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
        {
            bool shouldBeReversed = rowIndex % 2;

            if (shouldBeReversed)
            {
                for (int colIndex = COLS - 1; colIndex >= 0; colIndex--)
                {
                    std::cout << std::setfill(' ') << std::setw(digitCount) << array[rowIndex][colIndex] << " ";
                }
            }
            else
            {
                for (int colIndex = 0; colIndex < COLS; colIndex++)
                {
                    std::cout << std::setfill(' ') << std::setw(digitCount) << array[rowIndex][colIndex] << " ";
                }
            }

            std::cout << std::endl;
        }
    }
};
