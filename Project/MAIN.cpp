#include <iostream>
#include <string>

#include "List.h"
#include "Product.h"
#include "Map.h"

#include "cin_int.h"
#include "accounts.h"
#include "debug.h"
#include "interface.h"
#include "data_all_stores.h"
#include "products_file.h"
#include "products_func.h"
#include "cities.h"
#include "get_best_price.h"


int main()
{
	// Установка кодировки для русского и изменение размера консоли на полноэкранный режим
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	change_size_console(3);
	
	// Размер векторов для хешей
	const int now_size = 1543;
	
	// Объявляем вектора где будут хранится все логины, хеши и города у аккаунтов
	std::vector<list<std::string>> massive_logins(now_size);
	std::vector<list<unsigned int>> massive_hashes(now_size);
	std::vector<list<std::string>> massive_account_cities(now_size);

	// Объявляем вектора где будут хранится все данные про города
	std::vector<std::string> all_name_stores;
	std::vector<int> all_coef_stores;

	// Все имена файлов использующихся для подгрузки данных
	std::string file_products = "Products.txt";
	std::string file_accounts = "Accounts.txt";
	std::string file_cities = "Cities.txt";
	std::string file_all_stores = "All_stores.txt";
	
	// Подгрузка всех данных из файлов
	std::vector<Product> massive_products = load_products(file_products);
	map<std::string, double> massive_cities = load_all_cities(file_cities); 
	load_data_accounts(now_size, massive_logins, massive_hashes, massive_account_cities, file_accounts);
	load_all_stores(all_name_stores, all_coef_stores, file_all_stores);

	// Регистрация или авторизация
	int user_status = main_menu_authorizathion(now_size, massive_logins, massive_hashes, massive_account_cities, massive_cities, file_accounts);

	// Главное меню админа/пользователя/гостя
	while (true)
	{
		try
		{
			// Вызвать главное меню, где показываются функции доступные текущему пользователю
			main_menu(user_status);

			int answer = cin_int();

			// Поиск лучшей цены для товара без учёта доставки
			if (answer == 1)
			{
				get_best_price(massive_products, all_name_stores, all_coef_stores);
			}
			// Поиск лучшей цены для товара с учётом доставки
			else if (answer == 2 && user_status > 0)
			{
				get_best_price(massive_products, all_name_stores, all_coef_stores, &massive_cities);
			}
			// Просмотр списка товаров
			else if ((answer == 2 && user_status == 0) || (answer == 3 && user_status == 1) || (answer == 4 && user_status == 2))
			{
				get_data_products(massive_products);
			}
			// Просмотр списка товаров у конкретного магазина
			else if ((answer == 3 && user_status == 0) || (answer == 4 && user_status == 1) || (answer == 5 && user_status == 2))
			{
				get_products_in_store(massive_products, all_name_stores);
			}
			// Выход из программы (без возможности сохранения конфигурации в файл)
			else if ((answer == 4 && user_status == 0) || (answer == 7 && user_status == 1))
			{
				exit_without_save();
			}
			// Выбрать другой город проживания
			else if ((answer == 5 && user_status == 1) || (answer == 10 && user_status == 2))
			{
				change_now_city(massive_cities);
			}
			// Просмотреть цену доставки за килограмм товара в ваш город
			else if ((answer == 6 && user_status == 1) || (answer == 11 && user_status == 2))
			{
				std::cout << "Цена доставки за 1 кг товара до вашего города составляет: " << massive_cities.get_value(now_city) / 100 << " BYN" << "\n";
			}
			// Авторизоваться (то есть сменить user_status)
			else if (answer == 5 && user_status == 0)
			{
				user_status = authorizathion(now_size, massive_logins, massive_hashes, massive_account_cities);
			}
			// Зарегистрироваться (то есть сменить user_status)
			else if (answer == 6 && user_status == 0)
			{
				registration(now_size, massive_logins, massive_hashes, massive_cities, file_accounts);
				user_status = 1;
			}
			// Функции только для администратора
			else if (user_status == 2)
			{
				switch (answer)
				{
				// Добавление нового товара
				case 3:
				{
					add_new_product(massive_products);
					break;
				}
				// Добавить новый магазин для товара или изменить цену для уже существующего
				case 6:
				{
					int index = get_index_product(massive_products);
					if (index == -1 || index > massive_products.size() - 1)
					{
						std::cout << "Данного товара не существует";
					}
					else
					{
						massive_products[index].change_price(all_name_stores);
						massive_products[index].sort_by_name();
					}
					break;
				}
				// Добавить новый магазин в глобальный список магазинов
				case 7:
				{
					new_store(all_name_stores, all_coef_stores);
					break;
				}
				// Выгрузить данные в файлы
				case 8:
				{
					upload_products(massive_products, file_products);
					upload_all_stores(all_name_stores, all_coef_stores, file_all_stores);
					break;
				}
				// Загрузить все данные из файлов
				case 9:
				{
					massive_products = load_products(file_products);
					massive_cities = load_all_cities(file_cities);
					load_all_stores(all_name_stores, all_coef_stores, file_all_stores);
					break;
				}
				// Добавить новый город
				case 12:
				{
					new_city(massive_cities, file_cities);
					break;
				}
				// Просмотреть логины, хеши и города аккаунтов
				case 13:
				{
					debug_accounts(now_size, massive_logins, massive_hashes, massive_account_cities);
					break;
				}
				// Удалить товар
				case 14:
				{
					int index = get_index_product(massive_products);

					if (index == -1 || index > massive_products.size() - 1)
					{
						std::cout << "Данного товара не существует";
					}
					else
					{
						massive_products.erase(massive_products.begin() + index);
					}
					break;
				}
				// Удалить магазин в товаре
				case 15:
				{
					int index = get_index_product(massive_products);

					if (index == -1 || index > massive_products.size() - 1)
					{
						std::cout << "Данного товара не существует";
					}
					else
					{
						massive_products[index].delete_store();
					}
					break;
				}
				// Выйти из программы (предложиться сохранить конфигурацию)
				case 16:
				{
					exit_with_save(massive_products, all_name_stores, all_coef_stores, file_products, file_all_stores);
					break;
				}
				default:
					break;
				}
			}
			else
			{
				std::cout << "Неккоректный ввод\n";
			}
		}
		catch (const std::exception& e) 
		{
			std::cout << "Произошла ошибка: " << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Произошла неизвестная ошибка \n";
		}
	}

	return 0;
}
