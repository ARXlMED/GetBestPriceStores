#pragma once
#include <vector>
#include "List.h"
#include "Map.h"

// �������� ���������� �� � �������� ����� ����� � ������ ������� ��� ������������ � ������ �������
int authorizathion(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities);

// ����������� ������ �������� � ��������� � ������ � � ����
void registrathion(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, map<std::string, double>& massive_cities);

// ��������� � ������� ���� ������ ��� �������� � ������
void load_data_accounts(int size_massive, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities);