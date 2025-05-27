#include "authorizathion.h"

#include "enter_secret.h"
#include "hash.h"
#include <iostream>
#include "cities.h"

// Проверка существует ли в массивах такой логин и пароль который ввёл пользователь в данной функции
int authorizathion(int size_massive, std::vector<list<std::string>> &massive_logins, std::vector<list<int>> &massive_hashes, std::vector<list<std::string>>& massive_account_cities)
{
	try
	{
		int hash, place_in_massive;
		std::string login, password;
		std::cout << "Введите ваш логин: \n";
		std::cin >> login;
		std::cout << "Введите ваш пароль: \n";
		password = enter_secret();

		hash = gethash(password);
		place_in_massive = getindex(hash, size_massive);

		if (login == "admin" && hash == 652229939)
		{
			return 2;
		}

		for (int i = 0; i < massive_logins[place_in_massive].get_size(); i++)
		{
			if (massive_hashes[place_in_massive][i] == hash && massive_logins[place_in_massive][i] == login)
			{
				now_city = massive_account_cities[place_in_massive][i];
				return 1;
			}
		}
		return 0;
	}
	catch (...)
	{
		std::cout << "Ошибка";
		return 0;
	}
}