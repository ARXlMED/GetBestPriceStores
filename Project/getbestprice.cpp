#include "getbestprice.h"
#include "products_func.h"
#include "cities.h"
#include <string>
#include "Stack.h"

// Функция для поиска выгодных товаров в интернет магазинах (использует алгоритм итеративной быстрой сортировки)
void get_best_price(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities)
{
	int index = get_index_product(massive_products);
	Product product = massive_products[index];

	if (product.Stores.size() <= 1) return;
	stack<std::pair<int, int>> stack_borders;
	stack_borders.push({ 0, product.Stores.size() - 1 });
	while (!stack_borders.empty())
	{
		auto [left, right] = stack_borders.top_pop();
		// Переключаемся на сортировку выбором при малом количестве элементов (где мы изначально просчиываем все значения и храним их чтобы не вызывать постоянно функцию получения цены)
		if (right - left < 16)
		{
			std::vector<double> values;
			for (int i = left; i <= right; i++)
			{
				values.push_back(product.get_full_price(i, all_name_stores, all_coef_stores, massive_cities, now_city));
			}
			for (int i = left; i < right; i++)
			{
				int min_index = i;
				for (int j = i + 1; j <= right; j++)
				{
					if (values[min_index] > values[j])
					{
						min_index = j;
					}
				}
				product.swap_data_stores(min_index, i);
				std::swap(values[min_index], values[i]);
			}
			continue;
		}

		int p = partition(product, left, right, all_name_stores, all_coef_stores, massive_cities);

		if (p - left < right - p - 1)
		{
			if (left < p) stack_borders.push({ left, p });
			if (p + 1 < right) stack_borders.push({ p + 1, right });
		}
		else
		{
			if (p + 1 < right) stack_borders.push({ p + 1, right });
			if (left < p) stack_borders.push({ left, p });
		}
	}

	product.print_all_data();
}

// Определяет границу где разделяется массив на две части, до элемента возвращаемого идут элементы меньше некоторого pivot, а после больше pivot 
int partition(Product& product, int left, int right, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities)
{
	int pivot_index = left + (right - left) / 2;
	double pivot_price = product.Stores_base_price[pivot_index] + get_addict_price(product, pivot_index, all_name_stores, all_coef_stores, massive_cities);
	int i = left - 1;
	int j = right + 1;
	while (true)
	{
		do
		{
			i++;
		} while (product.get_full_price(i, all_name_stores, all_coef_stores, massive_cities, now_city) < pivot_price);

		do
		{
			j--;
		} while (product.get_full_price(j, all_name_stores, all_coef_stores, massive_cities, now_city) > pivot_price);

		if (i >= j) return j;

		product.swap_data_stores(i, j);
	}
}
