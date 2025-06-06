#include "hash.h"

// Функция вычисления FNV-1a хэша для строки
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

// В зависимости от размера массива получает место в массиве куда нужно загрузить хэш или какие то другие данные чтобы через хэш таблицу к ним можно было потом обратится 
unsigned int getindex(unsigned int hash, int lenmassive)
{
	return hash % lenmassive;
}
