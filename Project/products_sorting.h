#pragma once
#include "Product.h"
#include <vector>

// Сортировка по именам продуктов (из-за того что вначале в имени указывается компания сортирует по компаниям, а потом по именам)
void sort_by_name(std::vector<Product>& massive_products);

// Сортирует по цене, минимальная цена идёт вначале
void sort_by_min_price(std::vector<Product>& massive_products);

// Сортирует по цене, максимальная цена идёт вначале
void sort_by_max_price(std::vector<Product>& massive_products);

// Сортировка по количеству товаров в магазинах
void sort_by_count(std::vector<Product>& massive_products);
