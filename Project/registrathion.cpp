#include "registrathion.h"

#include <fstream>
#include "check_rus_let.h"
#include "enter_secret.h"
#include "hash.h"
#include "cities.h"

// Регистрация нового аккаунта с выгрузкой в массив и в файл
void registrathion(int size_massive, std::vector<list<std::string>> &massive_logins, std::vector<list<int>> &massive_hashes, map<std::string, double>& massive_cities)
{
	while (true)
	{
		std::ofstream out("Accounts.txt", std::ios::app);
		std::ifstream in("Accounts.txt");
		std::string login, password1, password2;
		int hash, place_in_massive;
		bool status = false; // Вспомогательная переменная для выхода из двойного цикла
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