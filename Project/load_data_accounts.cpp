#include "load_data_accounts.h"
#include "hash.h"
#include <fstream>

// Подгрузка в массивы всех данных про аккаунты с файлов
void load_data_accounts(int size_massive, std::vector<list<std::string>> &massive_logins, std::vector<list<int>> &massive_hashes, std::vector<list<std::string>>& massive_account_cities)
{
	std::ifstream in("Accounts.txt");
	int place_in_massive, hash;
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