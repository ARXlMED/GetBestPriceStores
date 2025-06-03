#pragma once
#include <string>
#include <vector>
#include "List.h"

// ������� ���������� FNV-1a ���� ��� ������
unsigned int gethash(std::string text);

// � ����������� �� ������� ������� �������� ����� � ������� ���� ����� ��������� ��� ��� ����� �� ������ ������ ����� ����� ��� ������� � ��� ����� ���� ����� ��������� 
unsigned int getindex(unsigned int hash, int lenmassive);

// �������� �� ������� ���� (�� ������������)
bool presence_in_hashes(std::string answer, std::vector<list<int>> massive_hashes);