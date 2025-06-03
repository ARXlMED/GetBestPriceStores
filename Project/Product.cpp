#include "Product.h"
#include "data_all_stores.h"
#include "cin_int.h"
#include "cities.h"


// �����������
Product::Product(std::string name, std::string main_info, double mass)
{
	this->name = name;
	this->main_info = main_info;
	this->mass = mass;
}

// ���������� ���������� �� ������ ������ ������� � ������ ��������� ������ � ���� �� �� ����� ��� ����� � �������
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

// ���������� ��� ������ ���������
void Product::swap_data_stores(int first_index, int second_index)
{
	std::swap(Stores[first_index], Stores[second_index]);
	std::swap(Stores_base_price[first_index], Stores_base_price[second_index]);
	std::swap(Stores_num_products[first_index], Stores_num_products[second_index]);
}

// ������������� ������ ��������� ������� ������� ������ �������� ������� �������
void Product::set_data_stores(int first_index, int second_index)
{
	Stores[first_index] = Stores[second_index];
	Stores_base_price[first_index] = Stores_base_price[second_index];
	Stores_num_products[first_index] = Stores_num_products[second_index];
}

// ��������� �������� �� �������� (���������� ���������)
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

/*��������� �������� �� ����(���������� ���������) (�� ������������ ��� ��� ��� ��������� ������ ��� ������ ��������� ����� ����� ��� ���� 
������������� �� ��������, � ���� ������ ������� ����������� �����, �� ����� ��������� ������� ���������, � ��� ����� �� ��� ��� ������
��������� ������, ������ ��� ������� ��������� ����� ��� ���������� �� ��������, � ���������� ��� �������� ����� ����� ���������� ��
O(n * log n) + O (log n) = O (n * log n), � ������� ����� �� O(n), � ������ �� ������ ���������� ��������� ������ �� ������� ������������
� ��� ���� �� ������ �� � ����������� ���������)*/ 
//void Product::sort_by_price()
//{
//	const double factor = 1.247;
//	int amountstores = Stores_price.size();
//	int step = amountstores - 1;
//
//	while (step >= 1) // �������� ����� ��������� ������
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
//	for (int i = 0; i + 1 < amountstores; i++) // ������ ����������� ��� �����������
//	{
//		if (Stores_price[i] > Stores_price[i + 1])
//		{
//			swapdatastores(i, i + 1);
//		}
//	}
//}

// �� �������� (������) �������� ������� ������ �������� � ������� ����������� ������ (�������� ��� ��������������� ������� �� ��������)
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

// �������� ��� ������������ ���� � �������� ��� ��������� ����� � ����� ��������� (������� ����� ��������������)
void Product::change_price(std::vector<std::string>& all_name_stores)
{
	std::cout << "����� ��� ����� ����������� ������ ������������ ��������� �������� (������) ��� ������ �� ��� �� ������ ���������� ����: \n";
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
		std::cout << "����� �������� �������� ������������ \n";
	}
	else
	{
		num_all_store--;
		int price, num_products;
		std::cout << "������� ���� � ������ ��������: \n";
		cin_int(price);
		std::cout << "������� ���������� ������� � ������ ��������: \n";
		cin_int(num_products);
		if (price > 0)
		{
			int num_store = place_store_vector(num_all_store, all_name_stores);
			if (num_store == -1) // ���� �������� �� ���������� � ������� ������ �� �������� ��� � ��������� ������ �������� ���� � ����������
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
			std::cout << "�� ����� ������������� ���� \n";
		}
	}
}

// �������� ������� ���������� � ������ (������� ����� ��������������)
void Product::change_main_info()
{
	std::cout << "������� ����� �������� ��� ������: \n";
	std::cin >> main_info;
}

// ������� � ������� �������� � �� ��������� ���� ��� ����� ��������
void Product::print_price()
{
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << Stores[i] << " ����: " << Stores_base_price[i] << " ���������� �� �������:" << Stores_num_products[i] << "\n";
	}
}

// ������� ���� � ������ ������ "Products.txt" (������� ����� ��������������)
void Product::delete_file()
{
	std::remove("Products.txt");
}

// ������� ������ �� ������������� ��������
void Product::delete_store()
{
	std::cout << "������� ������ �������� ��� ��������: ";
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

// ������� ����������� ���������� � ������ (���)
void Product::print_data()
{
	std::cout << name << "\n";
}

// ������� ��� ���������� � ������ � ������� �����
void Product::print_all_data()
{
	std::cout << name << "\n����� �����: " << mass << "\n�������� ������: " << main_info << "\n";
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << Stores[i] << ": " << Stores_base_price[i] << "BYN. " << "���������� ������: " << Stores_num_products[i] << "\n";
	}
}

// ������� ��� ���������� � ������ � ����� �� ��������
void Product::print_all_data(std::vector<double>& values)
{
	std::cout << name << "\n����� �����: " << mass << "\n�������� ������: " << main_info << "\n";
	for (int i = 0; i < Stores.size(); i++)
	{
		std::cout << Stores[i] << ": " << values[i] << "BYN. " << "���������� ������: " << Stores_num_products[i] << "\n";
	}
}

// ����� ����� ����������� ����
double Product::get_min_price()
{
	double min_price;
	if (Stores_base_price.empty()) {
		std::cout << "��� ��������� ������� ��� � ����������� ����";
		return 0;
	}
	min_price = Stores_base_price[0];
	for (int i = 1; i < Stores_base_price.size(); i++) if (min_price > Stores_base_price[i]) min_price = Stores_base_price[i];
	return min_price;
}

// ��������� ��� ���������� ������ � �������� � �����
int Product::get_sum_count()
{
	int count = 0;
	if (Stores_num_products.empty()) {
		std::cout << "��� ��������� ������� ��� � ����������� ����";
		return 0;
	}
	for (int i = 0; i < Stores_num_products.size(); i++) count += Stores_num_products[i];
	return count;
}

// ����� ����������� �� �������� � �������� ������ �� ��� ������� � ������� ������
int Product::get_koef_by_store(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores)
{
	int koef = 0;
	for (int i = 0; i < all_name_stores.size(); i++)
	{
		if (Stores[index] == all_name_stores[i]) return all_coef_stores[i];
	}
	return koef;
}

// ����� ������ ���� ��� ������� ������� �������� � ������
double Product::get_full_price(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities, std::string city)
{
	return Stores_base_price[index] + get_addict_price(*this, index, all_name_stores, all_coef_stores, massive_cities);
}
