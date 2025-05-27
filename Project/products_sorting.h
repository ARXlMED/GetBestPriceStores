#pragma once
#include "Product.h"
#include <vector>

// ���������� �� ������ ��������� (��-�� ���� ��� ������� � ����� ����������� �������� ��������� �� ���������, � ����� �� ������)
void sort_by_name(std::vector<Product>& massive_products);

// ��������� �� ����, ����������� ���� ��� �������
void sort_by_min_price(std::vector<Product>& massive_products);

// ��������� �� ����, ������������ ���� ��� �������
void sort_by_max_price(std::vector<Product>& massive_products);

// ���������� �� ���������� ������� � ���������
void sort_by_count(std::vector<Product>& massive_products);
