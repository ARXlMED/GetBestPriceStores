#pragma once
#include <string>
#include <vector>
#include "List.h"

// Функция вычисления FNV-1a хэша для строки
unsigned int gethash(std::string text);

// В зависимости от размера массива получает место в массиве куда нужно загрузить хэш или какие то другие данные чтобы через хэш таблицу к ним можно было потом обратится 
unsigned int getindex(unsigned int hash, int lenmassive);

// Проверка на наличие хэша (не используется)
bool presence_in_hashes(std::string answer, std::vector<list<int>> massive_hashes);