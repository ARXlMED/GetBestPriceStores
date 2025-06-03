#include "products_file.h"
#include <fstream>
#include <sstream>
#include <string>

// Загружает все данные из файла
std::vector<Product> load_products(std::string file_name)
{
	std::vector<Product> massive_products;
	std::ifstream in(file_name);
	if (in.is_open())
	{
		std::string line;
		while (std::getline(in, line))
		{
			Product product;

			std::string name_store;
			double price_store;
			int num_products;

			size_t devide_pos1, devide_pos2, devide_pos3;
			devide_pos1 = line.find(';');
			if (devide_pos1 == std::string::npos) continue;
			devide_pos2 = line.find(';', devide_pos1 + 1);
			if (devide_pos2 == std::string::npos) continue;
			devide_pos3 = line.find(';', devide_pos2 + 1);
			if (devide_pos3 == std::string::npos) continue;

			product.name = line.substr(0, devide_pos1);

			std::istringstream iss_mass(line.substr(devide_pos1 + 1, devide_pos2 - devide_pos1 - 1));
			iss_mass >> product.mass;

			std::istringstream iss_stores(line.substr(devide_pos2 + 1, devide_pos3 - devide_pos2 - 1));
			while (iss_stores >> name_store >> price_store >> num_products)
			{
				product.Stores.push_back(name_store);
				product.Stores_base_price.push_back(price_store);
				product.Stores_num_products.push_back(num_products);
			}

			product.main_info = line.substr(devide_pos3 + 1);

			product.min_price = product.get_min_price();
			product.sum_count = product.get_sum_count();

			product.sort_by_name();

			massive_products.push_back(product);
		}
	}
	in.close();
	return massive_products;
}

// Выгружает все данные структруры в файл (требует права администратора)
void upload_products(std::vector<Product>& massive_products, std::string file_name)
{
	std::ofstream out(file_name);
	if (out.is_open())
	{
		for (int i = 0; i < massive_products.size(); i++)
		{
			out << massive_products[i].name << ";" << massive_products[i].mass << ";";
			for (int j = 0; j < massive_products[i].Stores.size(); j++)
			{
				out << massive_products[i].Stores[j] << " " << massive_products[i].Stores_base_price[j] << " " << massive_products[i].Stores_num_products[j] << " ";
			}
			out << ";" << massive_products[i].main_info << "\n";
		}
	}
	out.close();
}