#include "Product.h"
#include "data_all_stores.h"
#include "cin_int.h"
#include "cities.h"


// Конструктор
Product::Product(std::string name, std::string main_info, double mass)
{
	this->name = name;
	this->main_info = main_info;
	this->mass = mass;
}

// Определяет существует ли вообще данный магазин в списке магазинов товара и если да то выдаёт его номер в массиве
int Product::place_store_vector(int num_store, std::vector<std::string>& all_name_stores)
{
	for (int i = 0; i < Stores.size(); i++)
	{
		if (Stores[i] == all_name_stores[num_store])
		{
			return i;
		}
	}
	return -1;
}

// Обменивает все данные магазинов
void Product::swap_data_stores(int first_index, int second_index)
{
	std::swap(Stores[first_index], Stores[second_index]);
	std::swap(Stores_base_price[first_index], Stores_base_price[second_index]);
	std::swap(Stores_num_products[first_index], Stores_num_products[second_index]);
}

// Устанавливает данные магазинов второго индекса данным магазина первого индекса
void Product::set_data_stores(int first_index, int second_index)
{
	Stores[first_index] = Stores[second_index];
	Stores_base_price[first_index] = Stores_base_price[second_index];
	Stores_num_products[first_index] = Stores_num_products[second_index];
}

// Сортирует магазины по алфавиту (сортировка расчёской)
void Product::sort_by_name()
{
	const double factor = 1.247;
	int amountstores = Stores.size();
	int step = amountstores - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < amountstores; i++)
		{
			if (Stores[i] > Stores[i + step])
			{
				swap_data_stores(i, i + step);
			}
		}
		step /= factor;
	}

	for (int i = 0; i + 1 < amountstores; i++) 
	{
		if (Stores[i] > Stores[i + 1])
		{
			swap_data_stores(i, i + 1);
		}
	}
}

/*Сортирует магазины по цене(сортировка расчёской) (не используется так как для бинарного поиска при поиске магазинов нужно чтобы они были 
отсортированы по алфавиту, а если данную функцию реализовать здесь, то будут заменятся порядки магазинов, а это сведёт на нет всю пользу
бинарного поиска, потому что придётся проводить перед ней сортировку по алфавиту, и получается что бинарный поиск будет выполнятся за
O(n * log n) + O (log n) = O (n * log n), а обычный поиск за O(n), а значит мы должны сортировку проводить только по велению пользователя
и при этом не менять всё в изначальной структуре)*/ 
//void Product::sort_by_price()
//{
//	const double factor = 1.247;
//	int amountstores = Stores_price.size();
//	int step = amountstores - 1;
//
//	while (step >= 1) // Расчёска почти сортирует массив
//	{
//		for (int i = 0; i + step < amountstores; i++)
//		{
//			if (Stores_price[i] > Stores_price[i + step])
//			{
//				swapdatastores(i, i + step);
//			}
//		}
//		step /= factor;
//	}
//
//	for (int i = 0; i + 1 < amountstores; i++) // Проход пузырьковой для закрепления
//	{
//		if (Stores_price[i] > Stores_price[i + 1])
//		{
//			swapdatastores(i, i + 1);
//		}
//	}
//}

// По названию (номеру) магазина находит индекс элемента в массиве конкретного товара (работает при отсортированном массиве по алфавиту)
int Product::binary_search_store(int index_store, std::vector<std::string>& all_name_stores)
{
	std::string name_store = all_name_stores[index_store];
	int left = 0;
	int right = Stores.size() - 1;
	int middle;
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (name_store == Stores[middle])
		{
			return middle;
		}
		else if (name_store < Stores[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return -1;
} 

// Изменяет уже существующую цену в магазине или добавляет новую с новым магазином (требует права администратора)
void Product::change_price(std::vector<std::string>& all_name_stores)
{
	std::cout << "Далее вам будет представлен список существующих магазинов выберите (цифрой) для какого из них вы хотите установить цену: \n";
	for (int i = 0; i < all_name_stores.size(); i++)
	{
		std::cout << i + 1 << ". " << all_name_stores[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			std::cout << "\n";
		}
	}
	int num_all_store;
	cin_int(num_all_store);
	if (num_all_store < 1 || num_all_store > all_name_stores.size())
	{
		std::cout << "Номер магазина является неккоректным \n";
	}
	else
	{
		num_all_store--;
		int price, num_products;
		std::cout << "Введите цену в данном магазине: \n";
		cin_int(price);
		std::cout << "Введите количество товаров в данном магазине: \n";
		cin_int(num_products);
		if (price > 0)
		{
			int num_store = place_store_vector(num_all_store, all_name_stores);
			if (num_store == -1) // Если магазина не существует в текущем списке то добавить его в противном случае изменить цену и количество
			{
				Stores.push_back(all_name_stores[num_all_store]);
				Stores_base_price.push_back(price);
				Stores_num_products.push_back(num_products);
				sort_by_name();
			}
			else
			{
				Stores_base_price[num_store] = price;
				Stores_num_products[num_store] = num_products;
			}
		}
		else
		{
			std::cout << "Вы ввели отрицательную цену \n";
		}
	}
}

// Изменяет главную информацию о товаре (требует права администратора)
void Product::change_main_info()
{
	std::cout << "Введите новое описание для товара: \n";
	std::cin >> main_info;
}

// Выводит в консоль магазины и их начальные цены без учёта доставки
void Product::print_price()
{
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << Stores[i] << " Цена: " << Stores_base_price[i] << " Количество на складах:" << Stores_num_products[i] << "\n";
	}
}

// Удаляет файл в данном случае "Products.txt" (требует права администратора)
void Product::delete_file()
{
	std::remove("Products.txt");
}

// Удаляет данные по определенному магазину
void Product::delete_store()
{
	std::cout << "Введите индекс магазина для удаления: ";
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << i + 1 << ". " << Stores[i] << "\n";
	}
	int index;
	std::cin >> index;
	index--;
	Stores.erase(Stores.begin() + index);
	Stores_base_price.erase(Stores_base_price.begin() + index);
	Stores_num_products.erase(Stores_num_products.begin() + index);
}

// Выводит минимальную информацию о товаре (имя)
void Product::print_data()
{
	std::cout << name << "\n";
}

// Выводит всю информацию о товаре с базовой ценой
void Product::print_all_data()
{
	std::cout << name << "\nМасса равна: " << mass << "\nОписание товара: " << main_info << "\n";
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << Stores[i] << ": " << Stores_base_price[i] << "BYN. " << "Количество товара: " << Stores_num_products[i] << "\n";
	}
}

// Выводит всю информацию о товаре с ценой за доставку
void Product::print_all_data(std::vector<double>& values)
{
	std::cout << name << "\nМасса равна: " << mass << "\nОписание товара: " << main_info << "\n";
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << Stores[i] << ": " << values[i] << "BYN. " << "Количество товара: " << Stores_num_products[i] << "\n";
	}
}

// Выдаёт самую минимальную цену
double Product::get_min_price()
{
	double min_price;
	if (Stores_base_price.empty()) {
		std::cout << "Нет магазинов поэтому нет и минимальной цены";
		return 0;
	}
	min_price = Stores_base_price[0];
	for (int i = 1; i < Stores_base_price.size(); i++) if (min_price > Stores_base_price[i]) min_price = Stores_base_price[i];
	return min_price;
}

// Суммирует все количества товара в магазине и выдаёт
int Product::get_sum_count()
{
	int count = 0;
	if (Stores_num_products.empty()) {
		std::cout << "Нет магазинов поэтому нет и минимальной цены";
		return 0;
	}
	for (int i = 0; i < Stores_num_products.size(); i++) count += Stores_num_products[i];
	return count;
}

// Выдаёт коэффициент за доставку в магазине исходя из его индекса в массиве товара
int Product::get_koef_by_store(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores)
{
	int koef = 0;
	for (int i = 0; i < all_name_stores.size(); i++)
	{
		if (Stores[index] == all_name_stores[i]) return all_coef_stores[i];
	}
	return koef;
}

// Выдаёт полную цену для индекса данного магазина в товаре
double Product::get_full_price(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city)
{
	return Stores_base_price[index] + get_addict_price(*this, index, all_name_stores, all_coef_stores, massive_cities);
}
