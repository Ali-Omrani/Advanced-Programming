#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream out;
	out.open ("testin.txt" , out );
	out << "this is just a simple test" << endl;
	out << "second line of testin over here!" << endl;
	out.close();
	fstream new_out ("testin.txt");
	new_out << "new_out: ridi baba! " << endl;
	new_out.close();
	
	
	
	return 0;
	
}