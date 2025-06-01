#include "interface.h"
#include <limits>
#include <iostream>
#include "accounts.h"
#include "cin_int.h"
#include "products_file.h"
#include "data_all_stores.h"
#include <cstdlib>

// �������� ���������� ������� (��� ������ ������)
HANDLE get_handle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

// �������� ������ �������
void change_size_console(int size_console) //����� ������ ������� 0 �����������, 1 �������, 2 �������, 3 �������������
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

        // ������ ������ ������ (������ x ������)
        COORD bufferSize = { width, height };

        if (!SetConsoleScreenBufferSize(hConsole, bufferSize))
        {
            std::cout << "�� ������� ������ ������ ������";
        }

        // ������ ���� ������� (������ x ������)
        SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 }; // (left, top, right, bottom)

        if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
        {
            std::cout << "�� ������� ������ ������ �������";
        }
    }

    if (size_console == 3)
    {
        HWND hwnd = GetConsoleWindow();
        ShowWindow(hwnd, SW_MAXIMIZE);
    }
}

// ��������� �������
void clear_console()
{
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

// ��������� ������� ���� ��� ������������ ���������� ��� �������������� ��� ����� � �������� �����
int main_menu_registrathion(int now_size, std::vector<list<std::string>>& massive_logins, std::vector<list<int>>& massive_hashes, std::vector<list<std::string>>& massive_account_cities, map<std::string, double>& massive_cities, std::string file_name)
{
    std::cout <<
        "=============================================================================================================================================================================================================================================\n"
        "|                                                                              ����� ���������� � ������ �� ������� �������� ������� � �������� ���������                                                                                   |\n"
        "=============================================================================================================================================================================================================================================\n"
        "�� ������ ������������������ ��� �����, ���� � ��� ��� ���� �������, � ����� ����� ����� � �������� ����� \n" <<
        "1. ������������������\n2. ����������������\n3. ����� � �������� �����\n";

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

// ������� ���� ��������� �� ������� ������������ ��� ���������� ����� ��������
void main_menu(int user_status)
{
    std::cout <<
        "============================================================================================>---------------------------------------------------<============================================================================================\n"
        "|                                                                                           |    ����� �������� ������� � �������� ���������    |                                                                                           |\n"
        "============================================================================================>---------------------------------------------------<============================================================================================\n";
    if (user_status == 2)
    {
        std::cout << "������ ������\n\n"
            "������ � ��������:\n"
            "1. �������� ������ ���� ��� ������ (��� ����� ��������)\n"
            "2. �������� ������ ���� ��� ������ (� ������ �������� � ��� �����)\n"
            "3. ���������� ������ ������\n"
            "4. �������� ������ �������\n\n"
            "������ � ����������:\n"
            "5. �������� ������ ������� � ����������� ��������\n"
            "6. �������� ����� ������� ��� ������ ��� �������� ���� ��� ��� �������������\n"
            "7. �������� ����� ������� � ���������� ������ ���������\n\n"
            "������ � �������:\n"
            "8. ��������� ������ � �����\n"
            "9. ��������� ��� ������ �� ������\n\n"
            "�������� � � ���������:\n"
            "10. ������� ����� ����������\n"
            "11. ����������� ���� �������� �� ��������� ������ � ��� �����\n"
            "12. �������� ����� ����� \n\n"
            "����� ����������:\n"
            "13. ����������� ������, ���� � ������ ���������\n\n"
            "�������� ����������:\n"
            "14. ������� �����\n"
            "15. ������� ������� � ������\n\n"
            "16. �����\n";
    }
    else if (user_status == 1)
    {
        std::cout << "������ ������������\n\n"
            "1. �������� ������ ���� ��� ������ (��� ����� ��������)\n"
            "2. �������� ������ ���� ��� ������ (� ������ �������� � ��� �����)\n"
            "3. �������� ������ �������\n"
            "4. �������� ������ ������� � ����������� ��������\n"
            "5. ������� ����� ����������\n"
            "6. ����������� ���� �������� �� ��������� ������ � ��� �����\n"
            "7. �����\n";
    }
    else
    {
        std::cout << "������ �����\n\n"
            "1. �������� ������ ���� ��� ������ (��� ����� ��������)\n"
            "2. �������� ������ �������\n"
            "3. �������� ������ ������� � ����������� ��������\n"
            "4. �����\n\n"
            "��� ��������� �������������� ���������� �� ��������� �������� ��������� ����� � ��� ������� ��� ������������������\n"
            "5. ��������������\n"
            "6. ������������������\n";
    }
}

// ����� �� ���������� ��� ����������� ���������� ���������� ������������
void exit_without_save()
{
    std::string answ1;
    std::cout << "������ �� �� ������������� �����? (1 - ��, 2 - ���) \n";
    std::cin >> answ1;
    if (answ1 == "1")
    {
        exit(0);
    }
}

// ����� �� ���������� � ������������ ��������� ������������
void exit_with_save(std::vector<Product>& massive_products, std::vector<std::string>& all_name_stores, std::vector<int>& all_coef_stores, std::string file_product, std::string file_all_stores)
{
    int answ1, answ2;
    std::cout << "������ �� �� ������������� �����? (1 - ��, 2 - ���) \n";
    answ1 = cin_int();
    if (answ1 == 1)
    {
        std::cout << "������ �� �� ��������� �������� ���� ��������� � �����? (1 - ��, 2 - ���) \n";
        answ2 = cin_int();
        if (answ2 == 1)
        {
            upload_products(massive_products, file_product);
            upload_all_stores(all_name_stores, all_coef_stores, file_all_stores);
        }
        exit(0);
    }
}