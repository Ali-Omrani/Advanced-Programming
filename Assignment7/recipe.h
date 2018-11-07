#ifndef _RECIPE_
#define _RECIPE_
#include <iostream>
#include <vector>
#include <algorithm>

struct ingredient
{
	ingredient(std::string _name, int amount);
	std::string name;
	int amount;
};
bool ingredient_comprator (const ingredient& l, const ingredient& r);
class recipe
{
public:
	recipe(std::string _name, std::vector <ingredient> _ingredients);
	std::vector <ingredient> get_ingredients();
	std::string get_name();
	void print_recipe();
private:
	std::string name;
	std::vector <ingredient> ingredients;
};

#endif