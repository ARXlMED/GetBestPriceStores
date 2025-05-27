#include "cin_int.h"
#include <iostream>
#include <limits>

// ���� ������ ����� ����� ������� ����� ������ int answ = cin_int();
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
			std::cout << "������: ������ ���� �� �������� ������ \n";
		}
		else
		{
			valid = true;
		}
	}
	
	return answer;
}

// ���� ������ ����� ����� ������� ����� ������ cin_int(answ);
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
			std::cout << "������: ������ ���� �� �������� ������ \n";
		}
		else
		{
			valid = true;
		}
	}
}

// ���� �������� ����� ����� ������� ����� ������ int answ = cin_int();
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
			std::cout << "������: ������ ���� �� �������� ������ � ��������� ������ \n";
		}
		else
		{
			valid = true;
		}
	}
	return answer;
}

// ���� �������� ����� ����� ������� ����� ������ cin_int(answ);
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
			std::cout << "������: ������ ���� �� �������� ������ � ��������� ������ \n";
		}
		else
		{
			valid = true;
		}
	}
}