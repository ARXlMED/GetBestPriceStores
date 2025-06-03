#include "products_func.h"
#include "products_sorting.h"
#include "cin_int.h"
#include "interface.h"

// ������� ����������� ��� � ��������� ��� ����� �������
int get_product_index_by_name(std::string answer, std::vector<Product>& massive_products)
{
	for (int i = 0; i < massive_products.size(); i++)
	{
		if (massive_products[i].name == answer)
		{
			return i;
		}
	}
	return -1;
}

// ������� ��� ������ ������ � ��������� (����� ��������� + ����� ������� ����������)
void get_data_products(std::vector<Product>& massive_products)
{
	std::cout << "������� ��� ���������� ������� �� ������ ������������: \n"
		"1. ���������� �� ������� �� ������\n"
		"2. ���������� �� ������� � ����������� �����\n"
		"3. ���������� �� ������� � ������������ �����\n"
		"4. ���������� �� ���������� ������� (���������� �� ���������� ������� � ���������)\n";
	int status = cin_int();
	switch (status)
	{
	case 1:
		sort_by_name(massive_products);
		break;
	case 2:
		sort_by_min_price(massive_products);
		break;
	case 3:
		sort_by_max_price(massive_products);
		break;
	case 4:
		sort_by_count(massive_products);
		break;
	default:
		break;
	}
	std::cout << "������� ����� ����������� ���������� � �������: \n"
		"1. ������\n"
		"2. �������� (������ �����)\n";
	std::string status2;
	std::cin >> status2;
	if (status2 == "1")
	{
		for (int i = 0; i < massive_products.size(); i++)
		{
			massive_products[i].print_all_data();
			std::cout << "\n";
		}
	}
	else
	{
		for (int i = 0; i < massive_products.size(); i++)
		{
			massive_products[i].print_data();
			std::cout << "\n";
		}
	}
}

// ������� ��� �������� � ���������� ��������
void get_products_in_store(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores)
{
	for (int i = 0; i < all_name_stores.size(); i++)
	{
		std::cout << i + 1 << ". " << all_name_stores[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << "\n";
	int index_store;
	std::cout << "������� ����� �������� ��� �������� �� ������ ������ ��������: ";
	index_store = cin_int();
	index_store--;
	if (index_store < 0 || index_store > all_name_stores.size() - 1)
	{
		std::cout << "������ �������� �� ���������� \n";
		return;
	}
	else
	{
		for (int i = 0; i < massive_products.size(); i++)
		{
			// �������� ����� �������� �������� ������� ���������� ������ �������� � ������� ������ (index_store_product)
			int index_store_product = massive_products[i].binary_search_store(index_store, all_name_stores);
			if (index_store_product != -1)
			{
				std::cout << massive_products[i].name << ": " << massive_products[i].Stores_base_price[index_store_product] << " " << massive_products[i].Stores_num_products[index_store_product] << std::endl;
			}
		}
	}
}

// �������� ����� ������� � ������
void add_new_product(std::vector<Product>& massive_products)
{
	std::string name, info;
	double mass;
	std::cout << "������� ��� ������ ������: \n";
	clear_console();
	std::getline(std::cin, name);
	std::cout << "������� ����� ������ ������ � �� (����� �����): \n";
	mass = cin_double();
	std::cout << "������� �������� ��� ������ ������: \n";
	clear_console();
	std::getline(std::cin, info);
	Product product(name, info, mass);
	massive_products.push_back(product);
}

// ��������� �������� ������ ������� �������� � �������
int get_index_product(std::vector<Product>& massive_products)
{
	int index;
	std::string answ;
	while (true)
	{
		std::cout << "���������� ������ ����� ������ ������:\n1. �� ������� � ����� ������\n2. �� ��������\n";
		std::cin >> answ;
		if (answ == "1")
		{
			for (int i = 0; i < massive_products.size(); i++)
			{
				std::cout << i + 1 << ". ";
				massive_products[i].print_data();
			}
			std::cout << "������� ������ ���������� ������:\n";
			index = cin_int();
			index--;
			if (index >= 0 && index < massive_products.size()) break;
			else std::cout << "�� ����� ���������������� ������\n";
		}
		else
		{
			std::string name;
			std::cout << "������� �������� ������ \n";
			clear_console();
			std::getline(std::cin, name);
			index = get_product_index_by_name(name, massive_products);
			if (index != -1) break;
			else std::cout << "������ ����� �� ������\n";
		}
	}
	return index;
}