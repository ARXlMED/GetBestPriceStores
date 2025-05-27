#pragma once
#include <iostream>
#include <vector>

struct Product // ����� ���������� � ��������� �� ����� ��������
{
//private:
	std::string name;
	std::string main_info;
	double mass = 0;
	std::vector<std::string> Stores;
	std::vector<double> Stores_base_price;
	std::vector<int> Stores_num_products;

	Product() = default;

	// �����������
	Product(std::string name, std::string main_info, double mass);

	// ���������� ���������� �� ������ ������ ������� � ������ ��������� ������ � ���� �� �� ����� ��� ����� � �������
	int place_store_vector(int user_status, int num_store, std::vector<std::string>& all_name_stores);

	// ����������� ��� ������ ��������� �� ������������
	void swapdatastores(int first_index, int second_index);

	// ��������� �������� �� �������� (���������� ���������)
	void sort_by_name();

	// ��������� �������� �� ���� (���������� ���������) (���������� ��������� � cpp)
	//void sort_by_price();

	// �� �������� �������� ������� ������ �������� � ������� ����������� ������ (�������� ��� ��������������� ������� �� ��������)
	int binary_search_store(int index_store, std::vector<std::string>& all_name_stores);

	// �������� ��� ������������ ���� � �������� ��� ��������� ����� � ����� ��������� (������� ����� ��������������)
	void change_price(int user_status, std::vector<std::string>& all_name_stores);
	
	// �������� ������� ���������� � ������ (������� ����� ��������������)
	void change_main_info(int user_status);

	// ������� � ������� �������� � �� ����
	void print_price(int user_status);

	// ������� ���� � ������ ������ "Products.txt" (������� ����� ��������������)
	void delete_file(int user_status);

	// ������� ������ �� ������������� ��������
	void delete_store();

	// ������� ����������� ���������� � ������ (���)
	void print_data();

	// ������� ��� ���������� � ������
	void print_all_data();

	// ����� ����� ����������� ����
	double get_min_price();

	// ��������� ��� ���������� ������ � �������� � �����
	int get_sum_count();

	// ����� ����������� �� �������� � �������� ������ �� ��� ������� � ������� ������
	int get_koef_by_store(int index, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores);
};