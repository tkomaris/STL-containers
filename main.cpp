#include <iostream>
#include <stack>
#include <vector>
#include <map>

#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"

void test_stack_with_ints(void)
{
	ft::stack<int> my_stack;
	ft::stack<int> my_stack2;
	std::stack<int> original_stack;
	std::stack<int> original_stack2;

	std::cout << "empty : " << my_stack.empty() << " " << original_stack.empty() << std::endl;
	
	std::cout << "\npush_back'1'" << std::endl;
	my_stack.push(1);
	original_stack.push(1);
	std::cout << "empty : " << my_stack.empty() << " " << original_stack.empty() << std::endl;
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	
	std::cout << "\npush_back '2'" << std::endl;
	my_stack.push(2);
	original_stack.push(2);
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\npush_back '4'" << std::endl;
	my_stack.push(4);
	original_stack.push(4);
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	
	std::cout << "\npush_back '42' to both stacks" << std::endl;
	my_stack.push(42);
	my_stack2.push(42);
	original_stack.push(42);
	original_stack2.push(42);
	std::cout << "1st == 2d: " << (int)(my_stack == my_stack2) << " " << (int)(original_stack == original_stack2) << std::endl;
	std::cout << "1st != 2nd : " << (int)(my_stack != my_stack2) << " " << (int)(original_stack != original_stack2) << std::endl;
	std::cout << "1st < 2d : " << (int)(my_stack < my_stack2) << " " << (int)(original_stack < original_stack2) << std::endl;
	std::cout << "1st > 2d : " << (int)(my_stack > my_stack2) << " " << (int)(original_stack > original_stack2) << std::endl;
	std::cout << "1st <= 2d : " << (int)(my_stack <= my_stack2) << " " << (int)(original_stack <= original_stack2) << std::endl;
	std::cout << "1st >= 2d : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
	
	std::cout << "\npush_back '24' only to the first stack" << std::endl;
	my_stack.push(24);
	original_stack.push(24);
	std::cout << "1st == 2nd : " << (int)(my_stack == my_stack2) << " " << (int)(original_stack == original_stack2) << std::endl;
	std::cout << "1st != 2nd : " << (int)(my_stack != my_stack2) << " " << (int)(original_stack != original_stack2) << std::endl;
	std::cout << "1st > 2d : " << (int)(my_stack > my_stack2) << " " << (int)(original_stack > original_stack2) << std::endl;
	std::cout << "1st < 2d : " << (int)(my_stack < my_stack2) << " " << (int)(original_stack < original_stack2) << std::endl;
	std::cout << "1st >= 2d : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
	std::cout << "1st <= 2d : " << (int)(my_stack <= my_stack2) << " " << (int)(original_stack <= original_stack2) << std::endl;

	std::cout << "\npush_back '2' only to the second stack" << std::endl;
	my_stack2.push(2);
	original_stack2.push(2);
	std::cout << "== : " << (int)(my_stack == my_stack2) << " " << (int)(original_stack == original_stack2) << std::endl;
	std::cout << "!= : " << (int)(my_stack != my_stack2) << " " << (int)(original_stack != original_stack2) << std::endl;
	std::cout << "<= : " << (int)(my_stack <= my_stack2) << " " << (int)(original_stack <= original_stack2) << std::endl;
	std::cout << ">= : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
	std::cout << ">= : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
	std::cout << ">  : " << (int)(my_stack > my_stack2) << " " << (int)(original_stack > original_stack2) << std::endl;
	std::cout << "<  : " << (int)(my_stack < my_stack2) << " " << (int)(original_stack < original_stack2) << std::endl;
}

void test_stack_with_strings(void)
{
	ft::stack<std::string> my_stack;
	ft::stack<std::string> my_stack2;
	std::stack<std::string> original_stack;
	std::stack<std::string> original_stack2;

	std::cout << "empty : " << my_stack.empty() << " " << original_stack.empty() << std::endl;
	std::cout << "\npush_back \"My\"" << std::endl;
	my_stack.push("My");
	original_stack.push("My");
	std::cout << "empty : " << my_stack.empty() << " " << original_stack.empty() << std::endl;
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	
	std::cout << "\npush_back \"name\"" << std::endl;
	my_stack.push("name");
	original_stack.push("name");
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	
	std::cout << "\npush_back \"is\"" << std::endl;
	my_stack.push("is");
	original_stack.push("is");
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\npush_back \"Tatiana\"" << std::endl;
	my_stack.push("Tatiana");
	original_stack.push("Tatiana");
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;

	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	std::cout << "top : " << my_stack.top() << " " << original_stack.top() << std::endl;
	
	std::cout << "\ncalling pop()" << std::endl;
	my_stack.pop();
	original_stack.pop();
	std::cout << "size : " << my_stack.size() << " " << original_stack.size() << std::endl;
	
	std::cout << "\npush_back \"orange\"" << std::endl;
	my_stack.push("orange");
	my_stack2.push("orange");
	original_stack.push("orange");
	original_stack2.push("orange");
	std::cout << "== : " << (int)(my_stack == my_stack2) << " " << (int)(original_stack == original_stack2) << std::endl;
	std::cout << "!= : " << (int)(my_stack != my_stack2) << " " << (int)(original_stack != original_stack2) << std::endl;
	std::cout << "<  : " << (int)(my_stack < my_stack2) << " " << (int)(original_stack < original_stack2) << std::endl;
	std::cout << ">  : " << (int)(my_stack > my_stack2) << " " << (int)(original_stack > original_stack2) << std::endl;
	std::cout << "<= : " << (int)(my_stack <= my_stack2) << " " << (int)(original_stack <= original_stack2) << std::endl;
	std::cout << ">= : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
	
	std::cout << "\npushing \"banana\" only to the first stack" << std::endl;
	my_stack.push("banana");
	original_stack.push("banana");
	std::cout << "== : " << (int)(my_stack == my_stack2) << " " << (int)(original_stack == original_stack2) << std::endl;
	std::cout << "!= : " << (int)(my_stack != my_stack2) << " " << (int)(original_stack != original_stack2) << std::endl;
	std::cout << "<  : " << (int)(my_stack < my_stack2) << " " << (int)(original_stack < original_stack2) << std::endl;
	std::cout << ">  : " << (int)(my_stack > my_stack2) << " " << (int)(original_stack > original_stack2) << std::endl;
	std::cout << "<= : " << (int)(my_stack <= my_stack2) << " " << (int)(original_stack <= original_stack2) << std::endl;
	std::cout << ">= : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
	
	std::cout << "\npushing \"lemon\" only to the second stack" << std::endl;
	my_stack2.push("lemon");
	original_stack2.push("lemon");
	std::cout << "== : " << (int)(my_stack == my_stack2) << " " << (int)(original_stack == original_stack2) << std::endl;
	std::cout << "!= : " << (int)(my_stack != my_stack2) << " " << (int)(original_stack != original_stack2) << std::endl;
	std::cout << "<  : " << (int)(my_stack < my_stack2) << " " << (int)(original_stack < original_stack2) << std::endl;
	std::cout << ">  : " << (int)(my_stack > my_stack2) << " " << (int)(original_stack > original_stack2) << std::endl;
	std::cout << "<= : " << (int)(my_stack <= my_stack2) << " " << (int)(original_stack <= original_stack2) << std::endl;
	std::cout << ">= : " << (int)(my_stack >= my_stack2) << " " << (int)(original_stack >= original_stack2) << std::endl;
}

void	test_vector_with_strings(void)
{
	ft::vector<std::string> my_vector;
	ft::vector<std::string> my_vector2;
	std::vector<std::string> original_vector;
	std::vector<std::string> original_vector2;

	std::cout << "empty : " << my_vector.empty() << " " << original_vector.empty() << std::endl;

	std::cout << "\npush_back \"elephant\"" << std::endl;
	my_vector.push_back("elephant");
	original_vector.push_back("elephant");
	std::cout << "empty : " << my_vector.empty() << " " << original_vector.empty() << std::endl;
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\npush_back  \"monkey\"" << std::endl;
	my_vector.push_back("monkey");
	original_vector.push_back("monkey");
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\npushing back \"wolf\"" << std::endl;
	my_vector.push_back("wolf");
	original_vector.push_back("wolf");
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	std::cout << "implemented :" << " ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original :" << " ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\ninsert \"fish\" on the 2nd [1] position" << std::endl;
	my_vector.insert(my_vector.begin() + 1, "fish");
	original_vector.insert(original_vector.begin() + 1, "fish");
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\nerase the 3d [2] element" << std::endl;
	my_vector.erase(my_vector.begin() + 2);
	original_vector.erase(original_vector.begin() + 2);
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\npop_back()" << std::endl;
	my_vector.pop_back();
	original_vector.pop_back();
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\npop_back()" << std::endl;
	my_vector.pop_back();
	original_vector.pop_back();
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "\npop_back()" << std::endl;
	my_vector.pop_back();
	original_vector.pop_back();
	std::cout << "size : " << my_vector.size() << " " << original_vector.size() << std::endl;

	std::cout << "\npush_back \"cat\"" << std::endl;
	my_vector.push_back("cat");
	my_vector2.push_back("cat");
	original_vector.push_back("cat");
	original_vector2.push_back("cat");
	std::cout << "implemented : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "== : " << (int)(my_vector == my_vector2) << " " << (int)(original_vector == original_vector2) << std::endl;
	std::cout << "!= : " << (int)(my_vector != my_vector2) << " " << (int)(original_vector != original_vector2) << std::endl;
	std::cout << "<  : " << (int)(my_vector < my_vector2) << " " << (int)(original_vector < original_vector2) << std::endl;
	std::cout << ">  : " << (int)(my_vector > my_vector2) << " " << (int)(original_vector > original_vector2) << std::endl;
	std::cout << "<= : " << (int)(my_vector <= my_vector2) << " " << (int)(original_vector <= original_vector2) << std::endl;
	std::cout << ">= : " << (int)(my_vector >= my_vector2) << " " << (int)(original_vector >= original_vector2) << std::endl;

	std::cout << "\npushing back \"dog\" only to the 1st vector" << std::endl;
	my_vector.push_back("dog");
	original_vector.push_back("dog");
	std::cout << "implemented 1 : ";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "implemented 2 : ";
	for (size_t i = 0; i < my_vector2.size(); i++)
		std::cout << my_vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "original 1: ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original 2: ";
	for (size_t i = 0; i < original_vector2.size(); i++)
		std::cout << original_vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "== : " << (int)(my_vector == my_vector2) << " " << (int)(original_vector == original_vector2) << std::endl;
	std::cout << "!= : " << (int)(my_vector != my_vector2) << " " << (int)(original_vector != original_vector2) << std::endl;
	std::cout << ">  : " << (int)(my_vector > my_vector2) << " " << (int)(original_vector > original_vector2) << std::endl;
	std::cout << "<  : " << (int)(my_vector < my_vector2) << " " << (int)(original_vector < original_vector2) << std::endl;
	std::cout << ">= : " << (int)(my_vector >= my_vector2) << " " << (int)(original_vector >= original_vector2) << std::endl;
	std::cout << ">= : " << (int)(my_vector >= my_vector2) << " " << (int)(original_vector >= original_vector2) << std::endl;

	std::cout << "\npushing \"parrot\" only to the 2nd vector" << std::endl;
	my_vector2.push_back("parrot");
	original_vector2.push_back("parrot");
	std::cout << "implemented 1 :";
	for (size_t i = 0; i < my_vector.size(); i++)
		std::cout << my_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "implemented 2 : ";
	for (size_t i = 0; i < my_vector2.size(); i++)
		std::cout << my_vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "original 1 : ";
	for (size_t i = 0; i < original_vector.size(); i++)
		std::cout << original_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "original 2 : ";
	for (size_t i = 0; i < original_vector2.size(); i++)
		std::cout << original_vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "== : " << (int)(my_vector == my_vector2) << " " << (int)(original_vector == original_vector2) << std::endl;
	std::cout << "!= : " << (int)(my_vector != my_vector2) << " " << (int)(original_vector != original_vector2) << std::endl;
	std::cout << ">  : " << (int)(my_vector > my_vector2) << " " << (int)(original_vector > original_vector2) << std::endl;
	std::cout << "<  : " << (int)(my_vector < my_vector2) << " " << (int)(original_vector < original_vector2) << std::endl;
	std::cout << ">= : " << (int)(my_vector >= my_vector2) << " " << (int)(original_vector >= original_vector2) << std::endl;
	std::cout << ">= : " << (int)(my_vector >= my_vector2) << " " << (int)(original_vector >= original_vector2) << std::endl;
}

void	print_maps(ft::map<std::string, int> *my_map, std::map<std::string, int> *original_map)
{
	ft::map<std::string, int>::iterator my_it = my_map->begin();
	std::map<std::string, int>::iterator original_it = original_map->begin();

	my_it = my_map->begin();
	original_it = original_map->begin();
	std::cout << "implemented : ";
	while (my_it != my_map->end())
	{
		std::cout << "[" << (*my_it).first << ", " << (*my_it).second << "]" << " ";
		my_it++;
	}
	std::cout << std::endl;
	std::cout << "original : ";
	while (original_it != original_map->end())
	{
		std::cout << "[" << (*original_it).first << ", " << (*original_it).second << "]" << " ";
		original_it++;
	}
	std::cout << std::endl << std::endl;
}

void	test_map_with_strings(void)
{
	std::string result;
	ft::map<std::string, int>	my_map;
	std::map<std::string, int>	original_map;

	std::cout << "empty : " << my_map.empty() << " " << original_map.empty() << std::endl;
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;
	std::cout << "max_size : " << my_map.max_size() << " " << original_map.max_size() << std::endl;
	
	std::cout << "\ninserting \"forest, 1\"" << std::endl;
	my_map.insert(ft::make_pair("forest", 1));
	original_map.insert(std::make_pair("forest", 1));
	std::cout << "empty : " << my_map.empty() << " " << original_map.empty() << std::endl;
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;
	std::cout << "find forest : " << (*(my_map.find("forest"))).first << " " << (*(original_map.find("forest"))).first << std::endl;
	if (my_map.find("forest") == my_map.end())
		result = "END";
	else
		result = (*my_map.find("forest")).first;
	std::cout << "find : " << result;
	if (original_map.find("forest") == original_map.end())
		result = "END";
	else
		result = (*original_map.find("forest")).first;
	std::cout << " " << result << std::endl;
////// end
	
	std::cout << "\ninserting \"sea, 42\"" << std::endl;
	my_map.insert(ft::make_pair("sea", 42));
	original_map.insert(std::make_pair("sea", 42));
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;
	
	std::cout << "\ninserting \"sky, 26\"" << std::endl;
	my_map.insert(ft::make_pair("sky", 26));
	original_map.insert(std::make_pair("sky", 26));
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;
	
	std::cout << "\ninserting \"mountains, 4\"" << std::endl;
	my_map.insert(ft::make_pair("mountains", 4));
	original_map.insert(std::make_pair("mountains", 4));
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;
	
	print_maps(&my_map, &original_map);

	std::cout << "\n\"river\" with operator [] and assigning 101" << std::endl;
	my_map["river"] = 101;
	original_map["river"] = 101;
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;

	print_maps(&my_map, &original_map);

	std::cout << "\ncalling operator [\"river\"] and assigning 101" << std::endl;
	my_map["river"] = 101;
	original_map["river"] = 101;
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;

	print_maps(&my_map, &original_map);
	std::cout << "count forest : " << my_map.count("forest") << " " << original_map.count("forest") << std::endl;
	std::cout << "count river : " << my_map.count("river") << " " << original_map.count("river") << std::endl;
///
	ft::map<std::string, int>::iterator		my_it = my_map.begin();
	std::map<std::string, int>::iterator	original_it = original_map.begin();

	std::cout << "\nerasing the 3d element [2]" << std::endl;
	++++my_it;
	++++original_it;
	my_map.erase(my_it);
	original_map.erase(original_it);
	print_maps(&my_map, &original_map);
	std::cout << "size : " << my_map.size() << " " << original_map.size() << std::endl;	
	std::cout << "count forest : " << my_map.count("forest") << " " << original_map.count("forest") << std::endl;
	std::cout << "count river : " << my_map.count("river") << " " << original_map.count("river") << std::endl;
	std::cout << "count mountains : " << my_map.count("mountains") << " " << original_map.count("mountains") << std::endl;
	std::cout << "count sea : " << my_map.count("sea") << " " << original_map.count("sea") << std::endl;
	std::cout << "count sky : " << my_map.count("sky") << " " << original_map.count("sky") << std::endl;
	
	std::cout << "erasing the 1st [0] element" << std::endl;
	my_map.erase(my_map.begin());
	original_map.erase(original_map.begin());
	print_maps(&my_map, &original_map);
	std::cout << "count forest : " << my_map.count("forest") << " " << original_map.count("forest") << std::endl;
	std::cout << "count river : " << my_map.count("river") << " " << original_map.count("river") << std::endl;
	std::cout << "count mountains : " << my_map.count("mountains") << " " << original_map.count("mountains") << std::endl;
	std::cout << "count sea : " << my_map.count("sea") << " " << original_map.count("sea") << std::endl;
	std::cout << "count sky : " << my_map.count("sky") << " " << original_map.count("sky") << std::endl;

	std::cout << "erasing new 1st [0] element" << std::endl;
	my_map.erase(my_map.begin());
	original_map.erase(original_map.begin());
	print_maps(&my_map, &original_map);
	std::cout << "count forest : " << my_map.count("forest") << " " << original_map.count("forest") << std::endl;
	std::cout << "count river : " << my_map.count("river") << " " << original_map.count("river") << std::endl;
	std::cout << "count mountains : " << my_map.count("mountains") << " " << original_map.count("mountains") << std::endl;
	std::cout << "count sea : " << my_map.count("sea") << " " << original_map.count("sea") << std::endl;
	std::cout << "count sky : " << my_map.count("sky") << " " << original_map.count("sky") << std::endl;

	std::cout << "\ninserting at the beggining \"helloWorld, 123\"" << std::endl;
	my_map.insert(my_map.begin(), ft::make_pair("helloWorld", 123));
	original_map.insert(original_map.begin(), std::make_pair("helloWorld", 123));

	print_maps(&my_map, &original_map);
}

int	main(void)
{

	std::cout << "Rules of the game: implemented vs original stl" << std::endl;
	std::cout << "\n######### STACK TESTS #########" << std::endl;

	test_stack_with_ints();
	test_stack_with_strings();

	std::cout << "\n######### VECTOR TESTS #########" << std::endl;

	test_vector_with_strings();

	std::cout << "\n######### MAP TESTS #########" << std::endl;

	test_map_with_strings();
}
