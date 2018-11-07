#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	ifstream in ("recips.txt");
	string hashtag;
	string name;
	string item;
	bool is_item=true;
	while (getline(in,hashtag,' '))
	{
		if (hashtag == "#")
		{
			
			getline (in,name);
			cout << name << endl;
			
			getline (in,item);
			stringstream mystream(item);
			string temp;
			while(mystream >> temp)
			{
				if(is_item)
				{
					temp = temp.substr(1,temp.size()-2);
					is_item=false;
				}		
				else if(!mystream.eof())
				{
					temp = temp.substr(0,temp.size()-2);
					is_item=true;
				}
				else 
				{
					is_item=true;
					temp = temp.substr(0,temp.size()-1);
				}
					cout << temp << endl;
			}		
		}
	}
}