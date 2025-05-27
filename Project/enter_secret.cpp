#include "enter_secret.h"
#include <conio.h>
#include <iostream>

// Функция которая фактически скрывает вывод символа и вместо него выводит *
std::string enter_secret()
{
	std::string password;
	char ch;
	while (true)
	{
		ch = _getch();

		if (ch == 8)
		{
			if (!password.empty())
			{
				password.pop_back();
				std::cout << "\b \b";
			}
		}

		else if (ch == 13) //Enter
		{
			std::cout << std::endl;
			break;
		}

		else
		{
			password.push_back(ch);
			std::cout << '*';
		}
	}

	return password;
}