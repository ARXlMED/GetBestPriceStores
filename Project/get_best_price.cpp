#include "get_best_price.h"
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
	std::vector<double> values;
	for (int i = 0; i <= product.Stores.size() - 1; i++)
	{
		values.push_back(product.get_full_price(i, all_name_stores, all_coef_stores, massive_cities, now_city));
	}
	stack<std::pair<int, int>> stack_borders;
	stack_borders.push({ 0, product.Stores.size() - 1 });
	while (!stack_borders.empty())
	{
		auto [left, right] = stack_borders.top_pop();
		// Переключаемся на сортировку вставками при малом количестве элементов
		if (right - left < 8)
		{
			for (int i = left + 1; i <= right; i++)
			{
				for (int j = i; j > left && values[j - 1] > values[j]; j--)
				{
					product.swap_data_stores(j - 1, j);
					std::swap(values[j - 1], values[j]);
				}
			}
			continue;
		}

		int p = partition(product, values, left, right, all_name_stores, all_coef_stores, massive_cities);

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

	product.print_all_data(values);
}

// Определяет границу где разделяется массив на две части, до элемента возвращаемого идут элементы меньше некоторого pivot, а после больше pivot 
int partition(Product& product, std::vector<double>& values, int left, int right, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, map<std::string, double>* massive_cities)
{
	int pivot_index = left + (right - left) / 2;
	double pivot_price = values[pivot_index];
	int i = left - 1;
	int j = right + 1;
	while (true)
	{
		do
		{
			i++;
		} while (values[i] < pivot_price);

		do
		{
			j--;
		} while (values[j] > pivot_price);

		if (i >= j) return j;

		product.swap_data_stores(i, j);
		std::swap(values[i], values[j]);
	}
}
