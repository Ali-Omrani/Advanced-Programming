#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	ifstream in ("warehouse.txt");
	string hashtag;
	string date;
	string item;
	bool is_item=true;
	while (getline(in,hashtag,' '))
	{
		if (hashtag == "#")
		{
			for (int i=1;i<=2;i++)	
			{
				getline (in,date,'-');
				cout << date << endl;
				
			}
			getline (in,date);
			cout << date << endl;
			
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