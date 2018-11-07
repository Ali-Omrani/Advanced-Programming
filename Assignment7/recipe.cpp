#include "recipe.h"
using namespace std;

ingredient::ingredient(string _name, int _amount) : name(_name) , amount(_amount) {}

recipe::recipe(string _name, vector<ingredient> _ingredients) : name(_name) , ingredients(_ingredients) {}

bool ingredient_comprator (const ingredient& l, const ingredient& r) {return l.name < r.name;}

vector <ingredient> recipe::get_ingredients() {return ingredients;}

string recipe::get_name() {return name;}

void recipe::print_recipe()
{
	sort(ingredients.begin(),ingredients.end(),ingredient_comprator);
	cout << "\t" << name  << endl;
	cout << "\t";
	for (int i=0;i<ingredients.size();i++)
	{
		cout << ingredients[i].name << ": " << ingredients[i].amount;
		if (i==ingredients.size()-1)
			cout << endl;
		else 
			cout << ", ";
	}
}
