#include "registrathion.h"

#include <fstream>
#include "check_rus_let.h"
#include "enter_secret.h"
#include "hash.h"
#include "cities.h"

// ����������� ������ �������� � ��������� � ������ � � ����
void registrathion(int size_massive, std::vector<list<std::string>> &massive_logins, std::vector<list<int>> &massive_hashes, map<std::string, double>& massive_cities)
{
	while (true)
	{
		std::ofstream out("Accounts.txt", std::ios::app);
		std::ifstream in("Accounts.txt");
		std::string login, password1, password2;
		int hash, place_in_massive;
		bool status = false; // ��������������� ���������� ��� ������ �� �������� �����
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