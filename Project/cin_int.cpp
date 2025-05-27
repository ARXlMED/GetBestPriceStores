#include "cin_int.h"
#include <iostream>
#include <limits>

// Ввод целого числа через консоль через формат int answ = cin_int();
int cin_int()
{
	int answer;
	bool valid = false;
	while (!valid)
	{
		std::cin >> answer;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: данный ввод не является числом \n";
		}
		else
		{
			valid = true;
		}
	}
	
	return answer;
}

// Ввод целого числа через консоль через формат cin_int(answ);
void cin_int(int& answer)
{
	bool valid = false;
	while (!valid)
	{
		std::cin >> answer;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: данный ввод не является числом \n";
		}
		else
		{
			valid = true;
		}
	}
}

// Ввод дробного числа через консоль через формат int answ = cin_int();
double cin_double()
{
	double answer;
	bool valid = false;
	while (!valid)
	{
		std::cin >> answer;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: данный ввод не является числом с плавающей точкой \n";
		}
		else
		{
			valid = true;
		}
	}
	return answer;
}

// Ввод дробного числа через консоль через формат cin_int(answ);
void cin_double(double& answer)
{
	bool valid = false;
	while (!valid)
	{
		std::cin >> answer;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: данный ввод не является числом с плавающей точкой \n";
		}
		else
		{
			valid = true;
		}
	}
}