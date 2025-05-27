#include "debug.h"

// Вывод всех аккаунтов содержащихся в массивах
void debug_accounts(int now_size, std::vector<list<std::string>> &massive_logins, std::vector<list<int>> &massive_hashes, std::vector<list<std::string>>& massive_account_cities)
{
	for (int i = 0; i < now_size; i++)
	{
		if (massive_logins[i].get_size() > 0)
		{
			std::cout << "Index " << i << ":\n";
			massive_logins[i].print();
			massive_hashes[i].print();
			massive_account_cities[i].print();
		}
	}
}

void debug_products(std::vector<Product> &massive_products)
{
	for (int i = 0; i < massive_products.size(); i++)
	{
		massive_products[i].print_data();
	}
}