#include "accounts.h"

#include "enter_secret.h"
#include "check_rus_let.h"
#include "cities.h"
#include "hash.h"

#include <iostream>
#include <fstream>

// Проверка существует ли в массивах такой логин и пароль который ввёл пользователь в данной функции
int authorizathion(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities)
{
	try
	{
		unsigned int hash, place_in_massive;
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

// Регистрация нового аккаунта с выгрузкой в массив и в файл
void registration(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, map<std::string, double>& massive_cities, std::string file_name)
{
	while (true)
	{
		std::ofstream out(file_name, std::ios::app);
		std::ifstream in(file_name);
		std::string login, password1, password2;
		unsigned int hash, place_in_massive;
		bool status = false;
		std::cout << "Введите логин (можно использовать только латинские буквы, цифры и специальные символы): \n";
		std::cin >> login;
		if (check_rus_let(login) == true)
		{
			std::cout << "В логине обнаружены русские буквы \n";
			continue;
		}
		std::cout << "Введите пароль (можно использовать только латинские буквы, цифры и специальные символы; также пароль должен состоять минимум из 6 символов): \n";
		password1 = enter_secret();
		if (check_rus_let(password1) == true)
		{
			std::cout << "В пароле обнаружены русские буквы \n";
			continue;
		}
		else if (password1.length() < 6)
		{
			std::cout << "Пароль меньше чем должен быть \n";
			continue;
		}
		std::cout << "Введите пароль ещё раз: \n";
		password2 = enter_secret();
		if (password1 == password2)
		{
			hash = gethash(password1);
			place_in_massive = getindex(hash, size_massive);
			if (out.is_open())
			{
				if (in.is_open())
				{
					for (int i = 0; i < massive_hashes[place_in_massive].get_size(); i++)
					{
						if (login == massive_logins[place_in_massive][i])
						{
							std::cout << "Профиль с данным логином уже существует. \n";
							status = true;
							break;
						}
					}
					in.close();
				}
				if (status == true)
				{
					out.close();
					continue;
				}

				std::string city;
				std::cout << "Введите город в котором вы проживаете для получения данных о цене с доставкой: \n";
				std::cin >> city;
				if (massive_cities.check_presense_key(city))
				{
					now_city = city;
				}
				else
				{
					std::cout << "Вашего города нет в списке городов доступных для доставки (выбран стандартный Минск)\n";
					now_city = "Минск";
				}

				out << login << " " << hash << " " << city << std::endl;
				out.close();
				massive_logins[place_in_massive].push_back(login);
				massive_hashes[place_in_massive].push_back(hash);
				return;
			}
		}
		else
		{
			std::cout << "Пароли не совпадают \n";
		}
	}
}

// Подгрузка в массивы всех данных про аккаунты с файлов
void load_data_accounts(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities, std::string file_name)
{
	std::ifstream in(file_name);
	unsigned int place_in_massive, hash;
	std::string login, city;
	if (in.is_open())
	{
		while (in >> login >> hash >> city)
		{
			place_in_massive = getindex(hash, size_massive);
			massive_logins[place_in_massive].push_back(login);
			massive_hashes[place_in_massive].push_back(hash);
			massive_account_cities[place_in_massive].push_back(city);
		}
	}
	in.close();
}