#pragma once
#include "hash.h"
#include <vector>

template <class Key, class Value>
class map
{
private:
	static constexpr int size_hash_table = 1543;
	std::vector<Value> hash_table = std::vector<Value>(size_hash_table);
	
public:

	void add_value(Key key, Value value)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);
		hash_table[index] = value;
	}
	
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

	bool check_presense_key(Key key)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);

		return hash_table[index] != Value{};
	}

	Value get_value(Key key)
	{
		int hash, index;
		hash = gethash(key);
		index = getindex(hash, size_hash_table);
		return hash_table[index];
	}
};