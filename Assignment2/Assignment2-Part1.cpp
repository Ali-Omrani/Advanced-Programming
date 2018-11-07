#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void to_lowercase (string& first_input, int index=0)
{
  if (index == first_input.length())
  	return;
  first_input[index]=tolower(first_input[index]);
  to_lowercase(first_input,index+1);
}
int min_size (string first_input, string second_input)
{
	if (first_input.length() < second_input.length())
		return first_input.length();
	return second_input.length();
}
int check_length (string first_input, string second_input,int index)
{
	int min_size_of_inputs=min_size(first_input,second_input);

	if (index>=min_size_of_inputs && index >= first_input.length() && index < second_input.length())
		return 1;
	else if (index>=min_size_of_inputs && index >= second_input.length() && index < first_input.length() )
		return -1;
	else if (index>min_size_of_inputs && first_input.length()==second_input.length())
		return 0;
	else 
		return 2;
}
int comprator (string first_input, string second_input,int index=0)
{
		int result;
		to_lowercase (first_input);
		to_lowercase (second_input);
		result=check_length(first_input,second_input,index);
		if (result==2)
		{	
			if (first_input[index]<second_input[index])
				return 1;
			else if (first_input[index]>second_input[index])
				return -1;
			else if (first_input[index]==second_input[index])
				return comprator(first_input,second_input,index+1); 
		}
		else
			return result;

}

int main()
{
	string first_input , second_input;
	while (cin >> first_input)
	{
	cin >> second_input;
	cout << comprator (first_input,second_input)<<endl;
	}
	return 0;
}