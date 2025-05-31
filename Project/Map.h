#pragma once
#include "hash.h"
#include <vector>

template <class Key, class Value>
struct map
{
	// Размер хеш-таблицы
	static constexpr int size_hash_table = 1543;

	// Хеш-таблица
	std::vector<Value> hash_table = std::vector<Value>(size_hash_table);

	// Добавить значение
	void add_value(Key key, Value value)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);
		hash_table[index] = value;
	}
	
	// Проверить если ли такое значение в хэш таблице
	bool check_value(Key key, Value value)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);
		if (value == hash_table[index])
		{
			return true;
		}
		return false;
	}

	// Проверить имеется ли какая то информация по данному ключу
	bool check_presense_key(Key key)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);

		return hash_table[index] != Value{};
	}

	// Получить значение по ключу
	Value get_value(Key key)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);
		return hash_table[index];
	}
};