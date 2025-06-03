#pragma once
#include <vector>
#include <string>
#include "Product.h"

// ������� ����������� ��� � ��������� ��� ����� �������
int get_product_index_by_name(std::string answer, std::vector<Product>& massive_products);

// ������� ��� ������ ������ � ��������� (����� ��������� + ����� ������� ����������)
void get_data_products(std::vector<Product>& massive_products);

// ������� ��� �������� � ���������� ��������
void get_products_in_store(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores);

// �������� ����� ������� � ������
void add_new_product(std::vector<Product>& massive_products);

// ��������� �������� ������ ������� �������� � �������
int get_index_product(std::vector<Product>& massive_products);