#include "products_sorting.h"

// Сортировка по именам продуктов (из-за того что вначале в имени указывается компания сортирует по компаниям, а потом по именам)
void sort_by_name(std::vector<Product>& massive_products)
{
	const double factor = 1.247;
	int amountstores = massive_products.size();
	int step = amountstores - 1;

	while (step >= 1) // Расчёска почти сортирует массив
	{
		for (int i = 0; i + step < amountstores; i++)
		{
			if (massive_products[i].name > massive_products[i+step].name)
			{
				Product temp = massive_products[i];
				massive_products[i] = massive_products[i+step];
				massive_products[i+step] = temp;
			}
		}
		step /= factor;
	}

	for (int i = 0; i + 1 < amountstores; i++) // Проход пузырьковой для закрепления
	{
		if (massive_products[i].name > massive_products[i + step].name)
		{
			Product temp = massive_products[i];
			massive_products[i] = massive_products[i + step];
			massive_products[i + step] = temp;
		}
	}
}

// Сортирует по цене, минимальная цена идёт вначале
void sort_by_min_price(std::vector<Product>& massive_products)
{
	const double factor = 1.247;
	int amountstores = massive_products.size();
	int step = amountstores - 1;

	while (step >= 1) // Расчёска почти сортирует массив
	{
		for (int i = 0; i + step < amountstores; i++)
		{
			if (massive_products[i].get_min_price() > massive_products[i + step].get_min_price())
			{
				Product temp = massive_products[i];
				massive_products[i] = massive_products[i + step];
				massive_products[i + step] = temp;
			}
		}
		step /= factor;
	}

	for (int i = 0; i + 1 < amountstores; i++) // Проход пузырьковой для закрепления
	{
		if (massive_products[i].get_min_price() > massive_products[i + step].get_min_price())
		{
			Product temp = massive_products[i];
			massive_products[i] = massive_products[i + step];
			massive_products[i + step] = temp;
		}
	}
}

// Сортирует по цене, максимальная цена идёт вначале
void sort_by_max_price(std::vector<Product>& massive_products)
{
	const double factor = 1.247;
	int amountstores = massive_products.size();
	int step = amountstores - 1;

	while (step >= 1) // Расчёска почти сортирует массив
	{
		for (int i = 0; i + step < amountstores; i++)
		{
			if (massive_products[i].get_min_price() < massive_products[i + step].get_min_price())
			{
				Product temp = massive_products[i];
				massive_products[i] = massive_products[i + step];
				massive_products[i + step] = temp;
			}
		}
		step /= factor;
	}

	for (int i = 0; i + 1 < amountstores; i++) // Проход пузырьковой для закрепления
	{
		if (massive_products[i].get_min_price() < massive_products[i + step].get_min_price())
		{
			Product temp = massive_products[i];
			massive_products[i] = massive_products[i + step];
			massive_products[i + step] = temp;
		}
	}
}

// Сортировка по количеству товаров в магазинах
void sort_by_count(std::vector<Product>& massive_products)
{
	const double factor = 1.247;
	int amountstores = massive_products.size();
	int step = amountstores - 1;

	while (step >= 1) // Расчёска почти сортирует массив
	{
		for (int i = 0; i + step < amountstores; i++)
		{
			if (massive_products[i].get_sum_count() > massive_products[i + step].get_sum_count())
			{
				Product temp = massive_products[i];
				massive_products[i] = massive_products[i + step];
				massive_products[i + step] = temp;
			}
		}
		step /= factor;
	}

	for (int i = 0; i + 1 < amountstores; i++) // Проход пузырьковой для закрепления
	{
		if (massive_products[i].get_sum_count() > massive_products[i + step].get_sum_count())
		{
			Product temp = massive_products[i];
			massive_products[i] = massive_products[i + step];
			massive_products[i + step] = temp;
		}
	}
}

