#include "data_all_stores.h"
#include <fstream>
#include <iostream>
#include "interface.h"
#include "cin_int.h"

// Загрузить все данные о названиях магазинах и коэффициентах доставки в них
void load_all_stores(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores)
{
	std::string line;
	std::ifstream in("All_stores.txt");
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::string name;
			int koef;
			in >> name >> koef;
			all_name_stores.push_back(name);
			all_coef_stores.push_back(koef);
		}
	}
	in.close();
}

// Выгрузить в файл все данные о названиях магазинах и коэффициентах доставки в них
void upload_all_stores(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores)
{
	std::ofstream out("All_stores.txt");
	if (out.is_open())
	{
		for (int i = 0; i < all_name_stores.size(); i++)
		{
			out << all_name_stores[i] << " " << all_coef_stores[i] << "\n";
		}
	}
	out.close();
}

// Добавить новый магазин и его коэффициент доставки в переменные
void new_store(std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores)
{
	std::string name_store;
	int koef;
	std::cout << "Введите название нового магазина: \n";
	clear_console();
	std::getline(std::cin, name_store);
	std::cout << "Введите коэффициент доставки для нового магазина: \n";
	koef = cin_int();
	all_name_stores.push_back(name_store);
	all_coef_stores.push_back(koef);
}