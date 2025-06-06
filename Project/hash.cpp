#include "hash.h"

// ������� ���������� FNV-1a ���� ��� ������
unsigned int gethash(std::string text)
{
	unsigned int hash = 2166136261u;
	const unsigned int prime = 16777619u;
	
	for (char c : text)
	{
		hash ^= static_cast<unsigned int>(c);
		hash *= prime;
	}

	return hash;
}

// � ����������� �� ������� ������� �������� ����� � ������� ���� ����� ��������� ��� ��� ����� �� ������ ������ ����� ����� ��� ������� � ��� ����� ���� ����� ��������� 
unsigned int getindex(unsigned int hash, int lenmassive)
{
	return hash % lenmassive;
}
