#pragma once
#include <vector>
#include <string>
#include "Product.h"

// Функция принимающая имя и находящая его среди вектора
int get_product_index_by_name(std::string answer, std::vector<Product>& massive_products);

// Функция для вывода данных о продуктах (выбор сотировки + выбор полноты информации)
void get_data_products(std::vector<Product>& massive_products);

// Находит все продукты в конкретном магазине
void get_products_in_store(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores);

// Добавить новый продукт в вектор
void add_new_product(std::vector<Product>& massive_products);

// Несколько способов поиска индекса продукта в массиве
int get_index_product(std::vector<Product>& massive_products);