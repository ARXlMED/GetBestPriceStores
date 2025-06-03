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

// �������� �� ������� ���� (�� ������������)
bool presence_in_hashes(std::string answer, std::vector<list<int>> massive_hashes)
{
	int hash = gethash(answer);
	int index = getindex(hash, massive_hashes.size());
	for (int i = 0; i < massive_hashes[index].get_size(); i++)
	{
		if (massive_hashes[index][i] == hash)
		{
			return true;
		}
	}
	return false;
}