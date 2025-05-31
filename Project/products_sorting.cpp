#include "products_sorting.h"

// ���������� �� ������ ��������� (��-�� ���� ��� ������� � ����� ����������� �������� ��������� �� ���������, � ����� �� ������) (������� ����������)
void sort_by_name(std::vector<Product>& massive_products)
{
	quick_sort(massive_products, 0, massive_products.size() - 1);
}

// ���������� ������� ��� ����������� ������ �� ��� �����, �� �������� ������������� ���� �������� ������ ���������� pivot, � ����� ������ pivot 
int partition(std::vector<Product>& massive_products, int low, int high)
{
	int pivot_index = low + (high - low) / 2;
	Product pivot_product = massive_products[pivot_index];
	int i = low - 1;
	int j = high + 1;

	while (true)
	{
		do
		{
			i++;
		} 
		while (massive_products[i].name < pivot_product.name);

		do
		{
			j--;
		} 
		while (massive_products[j].name > pivot_product.name);

		if (i >= j) return j;

		std::swap(massive_products[i], massive_products[j]);
	}
}

// ����������� ������ ������� ����������
void quick_sort(std::vector<Product>& massive_products, int low, int high)
{
	if (low < high)
	{
		int devision = partition(massive_products, low, high);
		quick_sort(massive_products, low, devision);
		quick_sort(massive_products, devision + 1, high);
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
// ��������� �� ����, ����������� ���� ��� ������� (���������� ��������)
void sort_by_min_price(std::vector<Product>& massive_products)
{
	merge_sort(massive_products, 0, massive_products.size() - 1);
}

// ��������� ����� ����� ��� ������� �� left �� middle � �� midddle + 1 �� right
void merge(std::vector<Product>& massive_products, int left, int middle, int right)
{
	std::vector<Product> left_massive, right_massive;

	for (int i = left; i <= middle; i++)
	{
		left_massive.push_back(massive_products[i]);
	}

	for (int i = middle + 1; i <= right; i++)
	{
		right_massive.push_back(massive_products[i]);
	}

	int i = 0, j = 0, k = left;
	while (i < left_massive.size() && j < right_massive.size())
	{
		if (left_massive[i].min_price <= right_massive[j].min_price)
		{
			massive_products[k++] = left_massive[i++];
		}
		else
		{
			massive_products[k++] = right_massive[j++];
		}
	}

	while (i < left_massive.size()) massive_products[k++] = left_massive[i++];
	while (j < right_massive.size()) massive_products[k++] = right_massive[j++];
}

// ����������� ������ ���������� ��������
void merge_sort(std::vector<Product>& massive_products, int left, int right)
{
	if (left >= right) return;

	int middle = left + (right - left) / 2;
	merge_sort(massive_products, left, middle);
	merge_sort(massive_products, middle + 1, right);
	merge(massive_products, left, middle, right);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
// ��������� �� ����, ������������ ���� ��� ������� (���������� ���������)
void sort_by_max_price(std::vector<Product>& massive_products)
{
	insertion_sort(massive_products);
}

// ���������� ���������
void insertion_sort(std::vector<Product>& massive_products)
{
	for (int i = 1; i < massive_products.size(); i++)
	{
		Product key = massive_products[i];
		int j = i - 1;
		while (j >= 0 && key.min_price > massive_products[j].min_price)
		{
			massive_products[j] = massive_products[j + 1];
			j--;
		}
		massive_products[j + 1] = key;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
// ���������� �� ���������� ������� � ��������� (���������� �������)
void sort_by_count(std::vector<Product>& massive_products)
{
	selecthion_sort(massive_products);
}

// ���������� �������
void selecthion_sort(std::vector<Product>& massive_products)
{
	for (int i = 0; i < massive_products.size() - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < massive_products.size(); j++)
		{
			if (massive_products[min_index].sum_count > massive_products[j].sum_count)
			{
				min_index = j;
			}
		}
		std::swap(massive_products[i], massive_products[min_index]);
	}
}


//const double factor = 1.247;
//int amountstores = massive_products.size();
//int step = amountstores - 1;
//
//while (step >= 1) // �������� ����� ��������� ������
//{
//	for (int i = 0; i + step < amountstores; i++)
//	{
//		if (massive_products[i].get_min_price() < massive_products[i + step].get_min_price())
//		{
//			Product temp = massive_products[i];
//			massive_products[i] = massive_products[i + step];
//			massive_products[i + step] = temp;
//		}
//	}
//	step /= factor;
//}
//
//for (int i = 0; i + 1 < amountstores; i++) // ������ ����������� ��� �����������
//{
//	if (massive_products[i].get_min_price() < massive_products[i + step].get_min_price())
//	{
//		Product temp = massive_products[i];
//		massive_products[i] = massive_products[i + step];
//		massive_products[i + step] = temp;
//	}
//}
