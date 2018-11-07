#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char binary_to_char(vector <bool> binary_input,int index)
{
	char result;
	result=(char) (binary_input[0+index]*128+binary_input[1+index]*64+binary_input[2+index]*32+binary_input[3+index]*16+binary_input[4+index]*8+binary_input[5+index]*4+binary_input[6+index]*2+binary_input[7+index]);
	return result;
}
bool exclusive_or (bool a, bool b)
{
	if (a==b)
		return false;
	else
		return true;
}
vector <bool> to_64bit_input (vector <bool> binary_input,int block_num)
{
	int index=block_num*64;
	vector <bool> result;
	for (int i = 0; i < 64; i++)
		{
			if (binary_input.size()>index)
				result.push_back(binary_input[index+i]);
		}	
	
	while (result.size()<64)
		{
			result.push_back(0);
		}	
			
	return result;
}

vector <bool> final_32bit_swap (vector <bool> left_half,vector <bool> right_half)
{
	vector <bool> result;
	result.insert(result.end(),right_half.begin(),right_half.end());
	result.insert(result.end(),left_half.begin(),left_half.end());
	return result;
}

void print_string_from_binay_vector(vector <bool> binary_input,int x)
{
	int iteration_var=binary_input.size();
	int index=0;
	vector <char> result;
	while (iteration_var>0)
	{
		result.push_back(binary_to_char(binary_input,index));
		index+=8;
		iteration_var-=8;
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout<< result[i];
	}
	cout <<endl;
}

void print_vector_x_char_per_line (vector <bool> input,int x)
{
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i];
		if (i%x==(x-1))
			cout << endl;
	}
	
}
vector <bool> permutation_performer(vector<bool> binary_input,int permutation_table[],int size_of_table)
{
	
	vector<bool> result (size_of_table);
		for (int i = 0; i <size_of_table ; i++)
		{
			result[i]=binary_input[permutation_table[i]-1];
		}
	return result;  	
}

int char_to_decimal (char input)
{
	return (int)input;
}

vector <bool> decimal_to_x_bit_binary (int decimal,int x)
{
	vector <bool> binary;
	
	while (decimal)
	{
		binary.push_back(decimal%2);
		decimal/=2;	
	}
	while (x-binary.size()>0)
	{
		binary.push_back(0);		
	}
	reverse(binary.begin(),binary.end());

	return binary;
}

vector <char> string_to_char_vector (string input)
{
	vector <char> result;
	for (int i=0; i< input.length();i++)
		result.push_back(input[i]);
	return result;
}

vector <bool> stirng_to_binary_vector (string input)
{
	 vector <bool> result;
	 vector <char> splited_string=string_to_char_vector(input);
	 for (int i = 0; i < splited_string.size(); i++)
	 {
	 	vector <bool> binary_ascii=decimal_to_x_bit_binary(char_to_decimal(splited_string[i]),8);
	 	for (int j = 0; j < 8; j++)
	 	{
	 		result.push_back(binary_ascii[j]);
	 	}
	 }

	 return result;
}

void shift (vector <bool>& binary_input,int shiftnum)
{
	rotate(binary_input.begin(),binary_input.begin()+shiftnum,binary_input.end());
	
}
void devider (vector <bool> binary_input,vector <bool>& left_half,vector <bool>& right_half)
{
	for (int i = 0; i < binary_input.size(); i++)
	{
		if (i<binary_input.size()/2)
			left_half.push_back(binary_input[i]);
		else
			right_half.push_back(binary_input[i]);
	}

}

vector <bool> subkey_gen (vector <bool>& left_half,vector <bool>& right_half,int PC_2[],int shift_table_num,int left_shift_schedule[])
{
	vector <bool> subkey;
	vector <bool> result(48);
	
	
	shift(left_half,left_shift_schedule[shift_table_num]);	
	shift(right_half,left_shift_schedule[shift_table_num]);	

	subkey.insert(subkey.end(),left_half.begin(),left_half.end());
	subkey.insert(subkey.end(),right_half.begin(),right_half.end());
	
	result=permutation_performer(subkey,PC_2,48);
	
	return result;
}

void key_gen (string input_string,bool subkey_list[][48],int PC_1[],int PC_2[],int left_shift_schedule[])
{
	vector <bool> binary_input=stirng_to_binary_vector(input_string);

	vector <bool> permuted_key_56=permutation_performer(binary_input,PC_1,56);
	vector <bool> right_half;
	vector <bool> left_half;
	vector <bool> result;
	devider(permuted_key_56,left_half,right_half);
	for (int i = 0; i < 16; i++)
	{
		result=subkey_gen (left_half,right_half,PC_2,i,left_shift_schedule);
	//can be a function
		for (int j = 0; j < 48;j++ )
				{
					subkey_list[i][j]=result[j];
				}		
	}
}
void print_subkey_list (bool subkey_list[][48],int mode)
{	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			if (mode==1)
			cout << subkey_list[i][j];
			else
				cout << subkey_list[15-i][j];
		}
		cout << endl;
	}
}
vector<bool> sbox_performer (vector <bool> binary_input,int sbox_i[][16])
{
	int first_argument=0;
	int second_argument=0;
	vector <int> decimal;
	vector <bool> binary;
	vector <bool> result;
	for (int i = 0; i < binary_input.size(); i++)
	{
		if (i%6==0)
			first_argument=2*binary_input[i]+binary_input[i+5];
		else if (i%6==1)
			{
			second_argument=8*binary_input[i]+4*binary_input[i+1]+2*binary_input[i+2]+binary_input[i+3];	
			decimal.push_back(sbox_i[(i/6)*4+first_argument][second_argument]);
			}
	}
	
	for (int i = 0; i < decimal.size(); i++)
	{
		binary=decimal_to_x_bit_binary(decimal[i],4);
		
		for (int j=0 ; j < 4 ; j++)
		{
			result.push_back(binary[j]);
		}
	}

	return result;
}

vector <bool> encryption (vector <bool> input_block,int EP[],bool subkey_list[][48],int sbox_i[][16],int PF[],int inverse_IP[],int mode)
{
	
	vector <bool> result;	
	vector <bool> right_half(0);	
	vector <bool> left_half(0);
	vector <bool> right_half_result(32);	
	vector <bool> left_half_result;
	vector <bool> temp;
	devider(input_block,left_half,right_half);
			
	for (int i = 0; i < 16; i++)
	{
		print_vector_x_char_per_line(left_half,33);
		print_vector_x_char_per_line(right_half,32);		

		left_half_result=right_half;
		temp=permutation_performer(right_half,EP,48);
		for (int j = 0; j < 48; j++)
		{
				if (mode==1)
					temp[j]=temp[j]^subkey_list[i][j];
				else
					temp[j]=temp[j]^subkey_list[15-i][j];
		}
		right_half=sbox_performer(temp,sbox_i);
		right_half=permutation_performer(right_half,PF,32);		
		for (int k = 0; k < 32; k++)
		{
				right_half_result[k]=right_half[k]^left_half[k];
		}			
		left_half=left_half_result;
		right_half=right_half_result;
		
		
	}

	print_vector_x_char_per_line(left_half,33);
	print_vector_x_char_per_line(right_half,32);		
 			
 	result=final_32bit_swap(left_half,right_half);
 	result=permutation_performer(result,inverse_IP,64);
 	print_vector_x_char_per_line(result,64);
 	return result;
}

int main ()
{
	
	
	int IP [64]=
	{58, 50 ,42 ,34 ,26 ,18 ,10 ,2
	,60 ,52 ,44 ,36 ,28 ,20 ,12 ,4
	,62 ,54 ,46 ,38 ,30 ,22 ,14 ,6
	,64 ,56 ,48 ,40 ,32 ,24 ,16 ,8
	,57 ,49 ,41 ,33 ,25 ,17 ,9  ,1
	,59 ,51 ,43 ,35 ,27 ,19 ,11 ,3
	,61 ,53 ,45 ,37 ,29 ,21 ,13 ,5
	,63 ,55 ,47 ,39 ,31 ,23 ,15 ,7};

	int EP[48]=
	{32 ,1  ,2  ,3  ,4  ,5
	,4  ,5  ,6  ,7  ,8  ,9
	,8  ,9  ,10 ,11 ,12 ,13
	,12 ,13 ,14 ,15 ,16 ,17
	,16 ,17 ,18 ,19 ,20 ,21
	,20 ,21 ,22 ,23 ,24 ,25
	,24 ,25 ,26 ,27 ,28 ,29
	,28 ,29 ,30 ,31 ,32 ,1
	};
	
	int PC_1[56]=
	{57 ,49 ,41 ,33 ,25 ,17  ,9
	,1  ,58 ,50 ,42 ,34 ,26 ,18
	,10 ,2  ,59 ,51 ,43 ,35 ,27
	,19 ,11 ,3  ,60 ,52 ,44 ,36
	,63 ,55 ,47 ,39 ,31 ,23 ,15
	,7  ,62 ,54 ,46 ,38 ,30 ,22
	,14 ,6  ,61 ,53 ,45 ,37 ,29
	,21 ,13 ,5  ,28 ,20 ,12  ,4
	};
	
	int PC_2 [48]=
	{14 ,17 ,11 ,24 ,1  ,5  ,3  ,28
	,15 ,6  ,21 ,10 ,23 ,19 ,12 ,4
	,26 ,8  ,16 ,7  ,27 ,20 ,13 ,2
	,41 ,52 ,31 ,37 ,47 ,55 ,30 ,40
	,51 ,45 ,33 ,48 ,44 ,49 ,39 ,56
	,34 ,53 ,46 ,42 ,50 ,36 ,29 ,32
	};

	int left_shift_schedule [16]=
	{1 ,1 ,2 ,2 ,2 ,2 ,2 ,2 
	,1 ,2 ,2 ,2 ,2 ,2 ,2 ,1
	};
	
	int sbox_i[32][16]=
	{14 ,4 ,13 ,1 ,2 ,15 ,11 ,8 ,3 ,10 ,6 ,12 ,5 ,9 ,0 ,7
	,0 ,15 ,7 ,4 ,14 ,2 ,13 ,1 ,10 ,6 ,12 ,11 ,9 ,5 ,3 ,8
	,4 ,1 ,14 ,8 ,13 ,6 ,2 ,11 ,15 ,12 ,9 ,7 ,3 ,10 ,5 ,0
	,15 ,12 ,8 ,2 ,4 ,9 ,1 ,7 ,5 ,11 ,3 ,14 ,10 ,0 ,6 ,13
	
	,15 ,1 ,8 ,14 ,6 ,11 ,3 ,4 ,9 ,7 ,2 ,13 ,12 ,0 ,5 ,10
	,3 ,13 ,4 ,7 ,15 ,2 ,8 ,14 ,12 ,0 ,1 ,10 ,6 ,9 ,11 ,5
	,0 ,14 ,7 ,11 ,10 ,4 ,13 ,1 ,5 ,8 ,12 ,6 ,9 ,3 ,2 ,15
	,13 ,8 ,10 ,1 ,3 ,15 ,4 ,2 ,11 ,6 ,7 ,12 ,0 ,5 ,14 ,9
	
	,10 ,0 ,9 ,14 ,6 ,3 ,15 ,5 ,1 ,13 ,12 ,7 ,11 ,4 ,2 ,8
	,13 ,7 ,0 ,9 ,3 ,4 ,6 ,10 ,2 ,8 ,5 ,14 ,12 ,11 ,15 ,1
	,13 ,6 ,4 ,9 ,8 ,15 ,3 ,0 ,11 ,1 ,2 ,12 ,5 ,10 ,14 ,7
	,1 ,10 ,13 ,0 ,6 ,9 ,8 ,7 ,4 ,15 ,14 ,3 ,11 ,5 ,2 ,12

	,7 ,13 ,14 ,3 ,0 ,6 ,9 ,10 ,1 ,2 ,8 ,5 ,11 ,12 ,4 ,15
	,13 ,8 ,11 ,5 ,6 ,15 ,0 ,3 ,4 ,7 ,2 ,12 ,1 ,10 ,14 ,9
	,10 ,6 ,9 ,0 ,12 ,11 ,7 ,13 ,15 ,1 ,3 ,14 ,5 ,2 ,8 ,4
	,3 ,15 ,0 ,6 ,10 ,1 ,13 ,8 ,9 ,4 ,5 ,11 ,12 ,7 ,2 ,14
	
	,2 ,12 ,4 ,1 ,7 ,10 ,11 ,6 ,8 ,5 ,3 ,15 ,13 ,0 ,14 ,9
	,14 ,11 ,2 ,12 ,4 ,7 ,13 ,1 ,5 ,0 ,15 ,10 ,3 ,9 ,8 ,6
	,4 ,2 ,1 ,11 ,10 ,13 ,7 ,8 ,15 ,9 ,12 ,5 ,6 ,3 ,0 ,14
	,11 ,8 ,12 ,7 ,1 ,14 ,2 ,13 ,6 ,15 ,0 ,9 ,10 ,4 ,5 ,3

	,12 ,1 ,10 ,15 ,9 ,2 ,6 ,8 ,0 ,13 ,3 ,4 ,14 ,7 ,5 ,11
	,10 ,15 ,4 ,2 ,7 ,12 ,9 ,5 ,6 ,1 ,13 ,14 ,0 ,11 ,3 ,8
	,9 ,14 ,15 ,5 ,2 ,8 ,12 ,3 ,7 ,0 ,4 ,10 ,1 ,13 ,11 ,6
	,4 ,3 ,2 ,12 ,9 ,5 ,15 ,10 ,11 ,14 ,1 ,7 ,6 ,0 ,8 ,13

	,4 ,11 ,2 ,14 ,15 ,0 ,8 ,13 ,3 ,12 ,9 ,7 ,5 ,10 ,6 ,1
	,13 ,0 ,11 ,7 ,4 ,9 ,1 ,10 ,14 ,3 ,5 ,12 ,2 ,15 ,8 ,6
	,1 ,4 ,11 ,13 ,12 ,3 ,7 ,14 ,10 ,15 ,6 ,8 ,0 ,5 ,9 ,2
	,6 ,11 ,13 ,8 ,1 ,4 ,10 ,7 ,9 ,5 ,0 ,15 ,14 ,2 ,3 ,12

	,13 ,2 ,8 ,4 ,6 ,15 ,11 ,1 ,10 ,9 ,3 ,14 ,5 ,0 ,12 ,7
	,1 ,15 ,13 ,8 ,10 ,3 ,7 ,4 ,12 ,5 ,6 ,11 ,0 ,14 ,9 ,2
	,7 ,11 ,4 ,1 ,9 ,12 ,14 ,2 ,0 ,6 ,10 ,13 ,15 ,3 ,5 ,8
	,2 ,1 ,14 ,7 ,4 ,10 ,8 ,13 ,15 ,12 ,9 ,0 ,3 ,5 ,6 ,11
	
	};

	int PF [32]=
	{16 ,7 ,20 ,21 ,29 ,12 ,28 ,17
	,1 ,15 ,23 ,26 ,5 ,18 ,31 ,10
	,2 ,8 ,24 ,14 ,32 ,27 ,3 ,9
	,19 ,13 ,30 ,6 ,22 ,11 ,4 ,25
	};

	int inverse_IP[64]=
	{
		40,8,48,16,56,24,64,32
		,39,7,47,15,55,23 ,63 ,31
		,38 ,6 ,46 ,14 ,54 ,22 ,62 ,30 
		,37 ,5 ,45 ,13 ,53 ,21 ,61 ,29 
		,36 ,4 ,44 ,12 ,52 ,20 ,60 ,28
		,35 ,3 ,43 ,11 ,51 ,19 ,59 ,27 
		,34 ,2 ,42 ,10 ,50 ,18 ,58 ,26
		,33 ,1 ,41 ,9 ,49 ,17 ,57 ,25

	};

	bool subkey_list[16][48];
	

	vector <bool> binary_input;
	vector <bool> result;
	vector <bool> input_block;			
	vector <bool> block_result;
	vector <bool> right_half ;
	vector <bool> left_half;
	int mode=0;
	string key;
	string input;
	getline (cin,key);
	key_gen(key,subkey_list,PC_1,PC_2,left_shift_schedule);
	
	while(getline(cin,input))
	{
		
		if (input[1]!='#')
		{
			cout<< "invalid input"<<endl;
			break;
		}
		if (input[0]=='E')
		{
			mode=1;
			input=input.substr(2);
			cout << "mode: encryption"<<endl;
			cout << "message: "<< input << endl;
			cout << "subkeys: "<< endl;
			print_subkey_list(subkey_list,mode);
		
			int iteration_var;
			int block_num=0;
			
			binary_input=stirng_to_binary_vector(input);
			
			iteration_var=binary_input.size();
			while (iteration_var>0)
			{
				cout << "block "<< block_num+1 <<":"<< endl;
				input_block=to_64bit_input(binary_input,block_num);
				input_block=permutation_performer(input_block,IP,64);	
				block_result=encryption(input_block,EP,subkey_list,sbox_i,PF,inverse_IP,mode);
				result.insert(result.end(),block_result.begin(),block_result.end());	
				iteration_var=iteration_var-64;
				block_num++;
			}	
			cout << "result:"<< endl;
				print_vector_x_char_per_line(result,result.size());
			
		}	
		else if (input[0]=='D')
		{
			mode=2;
			input=input.substr(2);
			cout << "mode: decryption"<<endl;
			cout << "message: "<< input << endl;
			cout << "subkeys: "<< endl;
			print_subkey_list(subkey_list,mode);
		
			int iteration_var;
			int block_num=0;
			
			for (int i = 0; i < input.length(); i++)
			{
				binary_input.push_back(input[i]-'0');
			}
			
			
			iteration_var=binary_input.size();
			while (iteration_var>0)
			{
				cout << "block "<< block_num+1 <<":"<< endl;
				input_block=to_64bit_input(binary_input,block_num);
				input_block=permutation_performer(input_block,IP,64);	
				block_result=encryption(input_block,EP,subkey_list,sbox_i,PF,inverse_IP,mode);
				result.insert(result.end(),block_result.begin(),block_result.end());	
				iteration_var=iteration_var-64;
				block_num++;
			}	
			cout << "result:"<< endl;
			print_string_from_binay_vector(result,result.size());


		}	
		else
		{
			cout<< "invalid input [mode]"<<endl;
			break;	
		}
	
		result.clear();
		binary_input.clear();
	}


return 0;
}

