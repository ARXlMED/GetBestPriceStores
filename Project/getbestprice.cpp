#include "getbestprice.h"
#include "products_func.h"
#include "cities.h"
#include "interface.h"
#include <string>
#include "Product.h"

// ������� ��� ������ �������� ������� � �������� ���������
void get_best_price(std::vector<Product>& products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities)
{
	int index = get_index_product(products);
	sort_by_price(products[index], all_name_stores, all_coef_stores, massive_cities);
}

// ��������� ������� �������� ������ �� ����, ������ �� �����, � �� � ������ � ������ ������� �� ��������,
// � �� �� ������ ����� �������� � ����������� � ������
void sort_by_price(Product product, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities)
{
	/*const double factor = 1.247;
	int amountstores = product.Stores.size();
	std::cout << amountstores << "\n";
	int step = amountstores - 1;*/

	// �����������, ���� ������ �� �����, �� ���� ���� �������������� ����� ��� ����� �������� 
	if (massive_cities == nullptr)
	{
		//while (step >= 1) // �������� ����� ��������� ������
		//{
		//	for (int i = 0; i + step < amountstores; i++)
		//	{
		//		if (product.Stores_base_price[i] > product.Stores_base_price[i + step])
		//		{
		//			product.swapdatastores(i, i + step);
		//		}
		//	}
		//	step /= factor;
		//}

		//for (int i = 0; i + 1 < amountstores; i++) // ������ ����������� ��� �����������
		//{
		//	if (product.Stores_base_price[i] > product.Stores_base_price[i + 1])
		//	{
		//		product.swapdatastores(i, i + 1);
		//	}
		//}

		//std::cout << "���� �� ����� � ��������� �� ������ � ������ (��� ����� ��������): \n";

		//for (int i = 0; i < amountstores; i++)
		//{
		//	std::cout << product.Stores[i] << ": " << product.Stores_base_price[i] << " BYN \n";
		//}
	}
	// �����������, ���� ������ �����, �� ���� ���� �������������� ����� � ������ �������� 
	else
	{
		double addict_price = get_addict_price(product, *massive_cities, now_city);

		//while (step >= 1) // �������� ����� ��������� ������
		//{
		//	for (int i = 0; i + step < amountstores; i++)
		//	{
		//		if (product.Stores_base_price[i] + addict_price * product.get_koef_by_store(i, all_name_stores, all_coef_stores) > product.Stores_base_price[i + step] + addict_price * product.get_koef_by_store(i + step, all_name_stores, all_coef_stores))
		//		{
		//			product.swapdatastores(i, i + step);
		//		}
		//	}
		//	step /= factor;
		//}

		//for (int i = 0; i + 1 < amountstores; i++) // ������ ����������� ��� �����������
		//{
		//	if (product.Stores_base_price[i] + addict_price * product.get_koef_by_store(i, all_name_stores, all_coef_stores) > product.Stores_base_price[i + 1] + addict_price * product.get_koef_by_store(i + 1, all_name_stores, all_coef_stores))
		//	{
		//		product.swapdatastores(i, i + 1);
		//	}
		//}

		//std::cout << "���� �� ����� � ��������� �� ������ � ������ (� ������ ��������): \n";

		//for (int i = 0; i < amountstores; i++)
		//{
		//	std::cout << product.Stores[i] << ": " << product.Stores_base_price[i] + addict_price * product.get_koef_by_store(i, all_name_stores, all_coef_stores) << " BYN \n";
		//}
	}
}