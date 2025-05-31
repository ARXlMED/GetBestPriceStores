#pragma once
#include <string>
#include <vector>
#include "List.h"

// Функция преобразующая строку в хэш длины половины от int (только положительные значения int)
int gethash(std::string password);

// В зависимости от размера массива получает место в массиве куда нужно загрузить хэш или какие то другие данные чтобы через хэш таблицу к ним можно было потом обратится 
int getindex(int hash, int lenmassive);

// Проверка на наличие хэша (не используется)
bool presence_in_hashes(std::string answer, std::vector<list<int>> massive_hashes);