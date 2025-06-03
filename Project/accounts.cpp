#include "accounts.h"

#include "enter_secret.h"
#include "check_rus_let.h"
#include "cities.h"
#include "hash.h"

#include <iostream>
#include <fstream>

// �������� ���������� �� � �������� ����� ����� � ������ ������� ��� ������������ � ������ �������
int authorizathion(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities)
{
	try
	{
		unsigned int hash, place_in_massive;
		std::string login, password;
		std::cout << "������� ��� �����: \n";
		std::cin >> login;
		std::cout << "������� ��� ������: \n";
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
		std::cout << "������";
		return 0;
	}
}

// ����������� ������ �������� � ��������� � ������ � � ����
void registration(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, map<std::string, double>& massive_cities, std::string file_name)
{
	while (true)
	{
		std::ofstream out(file_name, std::ios::app);
		std::ifstream in(file_name);
		std::string login, password1, password2;
		unsigned int hash, place_in_massive;
		bool status = false;
		std::cout << "������� ����� (����� ������������ ������ ��������� �����, ����� � ����������� �������): \n";
		std::cin >> login;
		if (check_rus_let(login) == true)
		{
			std::cout << "� ������ ���������� ������� ����� \n";
			continue;
		}
		std::cout << "������� ������ (����� ������������ ������ ��������� �����, ����� � ����������� �������; ����� ������ ������ �������� ������� �� 6 ��������): \n";
		password1 = enter_secret();
		if (check_rus_let(password1) == true)
		{
			std::cout << "� ������ ���������� ������� ����� \n";
			continue;
		}
		else if (password1.length() < 6)
		{
			std::cout << "������ ������ ��� ������ ���� \n";
			continue;
		}
		std::cout << "������� ������ ��� ���: \n";
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
							std::cout << "������� � ������ ������� ��� ����������. \n";
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
				std::cout << "������� ����� � ������� �� ���������� ��� ��������� ������ � ���� � ���������: \n";
				std::cin >> city;
				if (massive_cities.check_presense_key(city))
				{
					now_city = city;
				}
				else
				{
					std::cout << "������ ������ ��� � ������ ������� ��������� ��� �������� (������ ����������� �����)\n";
					now_city = "�����";
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
			std::cout << "������ �� ��������� \n";
		}
	}
}

// ��������� � ������� ���� ������ ��� �������� � ������
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