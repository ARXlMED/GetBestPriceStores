#pragma once
#include "Product.h"
#include <vector>

// ���������� �� ������ ��������� (��-�� ���� ��� ������� � ����� ����������� �������� ��������� �� ���������, � ����� �� ������) (������� ����������)
void sort_by_name(std::vector<Product>& massive_products);

// ���������� ������� ��� ����������� ������ �� ��� �����, �� �������� ������������� ���� �������� ������ ���������� pivot, � ����� ������ pivot 
int partition(std::vector<Product>& massive_products, int low, int high);

// ����������� ������ ������� ����������
void quick_sort(std::vector<Product>& massive_products, int low, int high);

//------------------------------------------------------------------------------------------------------------------------------------------------------
// ��������� �� ����, ����������� ���� ��� ������� (���������� ��������)
void sort_by_min_price(std::vector<Product>& massive_products);

// ��������� ����� ����� ��� ������� �� left �� middle � �� midddle + 1 �� right
void merge(std::vector<Product>& massive_products, int left, int middle, int right);

// ����������� ������ ���������� ��������
void merge_sort(std::vector<Product>& massive_products, int left, int right);

//------------------------------------------------------------------------------------------------------------------------------------------------------
// ��������� �� ����, ������������ ���� ��� ������� (���������� ���������)
void sort_by_max_price(std::vector<Product>& massive_products);

// ���������� ���������
void insertion_sort(std::vector<Product>& massive_products);

//------------------------------------------------------------------------------------------------------------------------------------------------------
// ���������� �� ���������� ������� � ���������
void sort_by_count(std::vector<Product>& massive_products);
