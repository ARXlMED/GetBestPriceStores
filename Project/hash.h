#pragma once
#include <string>
#include <vector>
#include "List.h"

int gethash(std::string password);

int getindex(int hash, int lenmassive);

bool presence_in_hashes(std::string answer, std::vector<list<int>> massive_hashes);