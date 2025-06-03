#include "products_func.h"
#include "products_sorting.h"
#include "cin_int.h"
#include "interface.h"

// Функция принимающая имя и находящая его среди вектора
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

// Функция для вывода данных о продуктах (выбор сотировки + выбор полноты информации)
void get_data_products(std::vector<Product>& massive_products)
{
	std::cout << "Введите вид сортировки который вы хотите использовать: \n"
		"1. Сортировка по товарам по именам\n"
		"2. Сортировка по товарам с минимальной ценой\n"
		"3. Сортировка по товарам с максимальной ценой\n"
		"4. Сортировка по популярным товарам (сортировка по количеству товаров в магазинах)\n";
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
	std::cout << "Введите режим отображения информации о товарах: \n"
		"1. Полный\n"
		"2. Неполный (только имена)\n";
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

// Находит все продукты в конкретном магазине
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
	std::cout << "Введите номер магазина для которого вы хотите узнать продукты: ";
	index_store = cin_int();
	index_store--;
	if (index_store < 0 || index_store > all_name_stores.size() - 1)
	{
		std::cout << "Такого магазина не существует \n";
		return;
	}
	else
	{
		for (int i = 0; i < massive_products.size(); i++)
		{
			// Бинарный поиск названия магазина который возвращает индекс магазина в массиве товара (index_store_product)
			int index_store_product = massive_products[i].binary_search_store(index_store, all_name_stores);
			if (index_store_product != -1)
			{
				std::cout << massive_products[i].name << ": " << massive_products[i].Stores_base_price[index_store_product] << " " << massive_products[i].Stores_num_products[index_store_product] << std::endl;
			}
		}
	}
}

// Добавить новый продукт в вектор
void add_new_product(std::vector<Product>& massive_products)
{
	std::string name, info;
	double mass;
	std::cout << "Введите имя вашего товара: \n";
	clear_console();
	std::getline(std::cin, name);
	std::cout << "Введите массу вашего товара в кг (через точку): \n";
	mass = cin_double();
	std::cout << "Введите описание для вашего товара: \n";
	clear_console();
	std::getline(std::cin, info);
	Product product(name, info, mass);
	massive_products.push_back(product);
}

// Несколько способов поиска индекса продукта в массиве
int get_index_product(std::vector<Product>& massive_products)
{
	int index;
	std::string answ;
	while (true)
	{
		std::cout << "Выберерите способ ввода поиска товара:\n1. По индексу в общем списке\n2. По названию\n";
		std::cin >> answ;
		if (answ == "1")
		{
			for (int i = 0; i < massive_products.size(); i++)
			{
				std::cout << i + 1 << ". ";
				massive_products[i].print_data();
			}
			std::cout << "Введите индекс требуемого товара:\n";
			index = cin_int();
			index--;
			if (index >= 0 && index < massive_products.size()) break;
			else std::cout << "Вы ввели недействительный индекс\n";
		}
		else
		{
			std::string name;
			std::cout << "Введите название товара \n";
			clear_console();
			std::getline(std::cin, name);
			index = get_product_index_by_name(name, massive_products);
			if (index != -1) break;
			else std::cout << "Данный товар не найден\n";
		}
	}
	return index;
}