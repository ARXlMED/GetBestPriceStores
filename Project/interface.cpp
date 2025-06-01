#include "interface.h"
#include <limits>
#include <iostream>
#include "accounts.h"
#include "cin_int.h"
#include "products_file.h"
#include "data_all_stores.h"
#include <cstdlib>

// Получить дескриптор консоли (все данные оттуда)
HANDLE get_handle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

// Изменить размер консоли
void change_size_console(int size_console) //Задаёт размер консоли 0 стандартное, 1 среднее, 2 большое, 3 полноэкранный
{
    if (size_console >= 0 && size_console <= 2)
    {
        SHORT width = 150, height = 40;


        switch (size_console)
        {
        case 0:
            width = 120, height = 30;
            break;
        case 1:
            width = 150, height = 40;
            break;
        case 2:
            width = 200, height = 60;
            break;
        }



        HANDLE hConsole = get_handle();

        // Размер буфера экрана (ширина x высота)
        COORD bufferSize = { width, height };

        if (!SetConsoleScreenBufferSize(hConsole, bufferSize))
        {
            std::cout << "Не удалось задать размер буфера";
        }

        // Размер окна консоли (ширина x высота)
        SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 }; // (left, top, right, bottom)

        if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
        {
            std::cout << "Не удалось задать размер консоли";
        }
    }

    if (size_console == 3)
    {
        HWND hwnd = GetConsoleWindow();
        ShowWindow(hwnd, SW_MAXIMIZE);
    }
}

// Почистить консоль
void clear_console()
{
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

// Начальное главное меню где предлагается зарегаться или авторизоваться или зайти в качестве гостя
int main_menu_registrathion(int now_size, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities, map<std::string, double>& massive_cities, std::string file_name)
{
    std::cout <<
        "=============================================================================================================================================================================================================================================\n"
        "|                                                                              Добро пожаловать в сервис по подбору выгодных товаров в интернет магазинах                                                                                   |\n"
        "=============================================================================================================================================================================================================================================\n"
        "Вы можете зарегистрироваться или войти, если у вас уже есть аккаунт, а также можно войти в качестве гостя \n" <<
        "1. Зарегистрироваться\n2. Авторизироваться\n3. Войти в качестве гостя\n";

    int user_status = 0;
    int answer = cin_int();

    switch (answer)
    {
    case 1:
    {
        registrathion(now_size, massive_logins, massive_hashes, massive_cities, file_name);
        user_status = 1;
        break;
    }
    case 2:
    {
        user_status = authorizathion(now_size, massive_logins, massive_hashes, massive_account_cities);
        break;
    }
    case 3:
    {
        user_status = 0;
        break;
    }
    default:
        user_status = 0;
        break;
    }
    return user_status;
}

// Главное меню зависящее от статуса пользователя где происходит выбор действий
void main_menu(int user_status)
{
    std::cout <<
        "============================================================================================>---------------------------------------------------<============================================================================================\n"
        "|                                                                                           |    Поиск выгодных товаров в интернет магазинах    |                                                                                           |\n"
        "============================================================================================>---------------------------------------------------<============================================================================================\n";
    if (user_status == 2)
    {
        std::cout << "Панель админа\n\n"
            "Работа с товарами:\n"
            "1. Просмотр лучшей цены для товара (без учёта доставки)\n"
            "2. Просмотр лучшей цены для товара (с учётом доставки в ваш город)\n"
            "3. Добавление нового товара\n"
            "4. Просмотр списка товаров\n\n"
            "Работа с магазинами:\n"
            "5. Просмотр списка товаров у конкретного магазина\n"
            "6. Добавить новый магазин для товара или изменить цену для уже существующего\n"
            "7. Добавить новый магазин в глобальный список магазинов\n\n"
            "Работа с файлами:\n"
            "8. Выгрузить данные в файлы\n"
            "9. Загрузить все данные из файлов\n\n"
            "Доставка и её стоимость:\n"
            "10. Выбрать город проживания\n"
            "11. Просмотреть цену доставки за килограмм товара в ваш город\n"
            "12. Добавить новый город \n\n"
            "Дебаг информации:\n"
            "13. Просмотреть логины, хэши и города аккаунтов\n\n"
            "Удаление информации:\n"
            "14. Удалить товар\n"
            "15. Удалить магазин в товаре\n\n"
            "16. Выйти\n";
    }
    else if (user_status == 1)
    {
        std::cout << "Панель пользователя\n\n"
            "1. Просмотр лучшей цены для товара (без учёта доставки)\n"
            "2. Просмотр лучшей цены для товара (с учётом доставки в ваш город)\n"
            "3. Просмотр списка товаров\n"
            "4. Просмотр списка товаров у конкретного магазина\n"
            "5. Выбрать город проживания\n"
            "6. Просмотреть цену доставки за килограмм товара в ваш город\n"
            "7. Выйти\n";
    }
    else
    {
        std::cout << "Панель гостя\n\n"
            "1. Просмотр лучшей цены для товара (без учёта доставки)\n"
            "2. Просмотр списка товаров\n"
            "3. Просмотр списка товаров у конкретного магазина\n"
            "4. Выйти\n\n"
            "Для просмотра дополнительной информации по стоимости доставки требуется войти в ваш аккаунт или зарегистрироваться\n"
            "5. Авторизоваться\n"
            "6. Зарегистрироваться\n";
    }
}

// Выход из приложения без возможности сохранения измененной конфигурации
void exit_without_save()
{
    std::string answ1;
    std::cout << "Хотите ли вы действительно выйти? (1 - да, 2 - нет) \n";
    std::cin >> answ1;
    if (answ1 == "1")
    {
        exit(0);
    }
}

// Выход из приложения с предложением сохранить конфигурацию
void exit_with_save(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_product, std::string file_all_stores)
{
    int answ1, answ2;
    std::cout << "Хотите ли вы действительно выйти? (1 - да, 2 - нет) \n";
    answ1 = cin_int();
    if (answ1 == 1)
    {
        std::cout << "Хотите ли вы сохранить внесённые вами изменения в файлы? (1 - да, 2 - нет) \n";
        answ2 = cin_int();
        if (answ2 == 1)
        {
            upload_products(massive_products, file_product);
            upload_all_stores(all_name_stores, all_coef_stores, file_all_stores);
        }
        exit(0);
    }
}