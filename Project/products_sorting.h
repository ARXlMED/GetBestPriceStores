#pragma once
#include "Product.h"
#include <vector>

// Сортировка по именам продуктов (из-за того что вначале в имени указывается компания сортирует по компаниям, а потом по именам) (быстрая сортировка)
void sort_by_name(std::vector<Product>& massive_products);

// Определяет границу где разделяется массив на две части, до элемента возвращаемого идут элементы меньше некоторого pivot, а после больше pivot 
int partition(std::vector<Product>& massive_products, int low, int high);

// Рекурсивные вызовы быстрой сортировки
void quick_sort(std::vector<Product>& massive_products, int low, int high);

//------------------------------------------------------------------------------------------------------------------------------------------------------
// Сортирует по цене, минимальная цена идёт вначале (сортировка слиянием)
void sort_by_min_price(std::vector<Product>& massive_products);

// Сортирует между собой два массива от left до middle и от midddle + 1 до right
void merge(std::vector<Product>& massive_products, int left, int middle, int right);

// Рекурсивные вызовы сортировки слиянием
void merge_sort(std::vector<Product>& massive_products, int left, int right);

//------------------------------------------------------------------------------------------------------------------------------------------------------
// Сортирует по цене, максимальная цена идёт вначале (сортировка вставками)
void sort_by_max_price(std::vector<Product>& massive_products);

// Сортировка вставками
void insertion_sort(std::vector<Product>& massive_products);

//------------------------------------------------------------------------------------------------------------------------------------------------------
// Сортировка по количеству товаров в магазинах
void sort_by_count(std::vector<Product>& massive_products);
