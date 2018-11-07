#include "function.h"
using namespace std;

Function::Function(){}

Function::Function(const Function& g) 
{
	for (int i=0;i<g.pairs.size();i++)
		pairs.push_back(g.pairs[i]);
}

void Function::check_mutual_domain(const double x) const
{
	for (int i=0;i<pairs.size();i++)
	{
		if (pairs[i].get_x()==x)
			throw mutual_domain_exception();
	}
}
Function Function::operator+(const Pair& new_pair) const 
{
	Function new_Function(*this);
	try
	{
		this->check_mutual_domain(new_pair.get_x());
		new_Function.add_pair(new_pair);	
 	}
 	catch (mutual_domain_exception ex)
 	{
 		cerr << "mutual domain on: " << new_pair.get_x()<< "! " << endl;
 	} 	
 	return new_Function;
}

Function Function::operator+(const double _y) const
{
	Function new_Function(*this);
	for(int i=0;i<new_Function.pairs.size();i++)
	{
		new_Function.pairs[i].set_y(_y+pairs[i].get_y());
	}
 	
 	return new_Function;	
}	

Function Function::operator-(const double _y) const
{

	Function new_Function(*this);
	for(int i=0;i<new_Function.pairs.size();i++)
	{
		new_Function.pairs[i].set_y(pairs[i].get_y()-_y);
	}
 	
 	return new_Function;	
}

Function Function::operator*(const double _y) const
{

	Function new_Function(*this);
	for(int i=0;i<new_Function.pairs.size();i++)
	{
		new_Function.pairs[i].set_y(pairs[i].get_y()*_y);
	}
 	
 	return new_Function;	
}

Function Function::operator/(const double _y) const
{

	Function new_Function(*this);
	try
	{
		if (_y==0)
			throw division_by_zero_exception();
		for(int i=0;i<new_Function.pairs.size();i++)
		{
			new_Function.pairs[i].set_y(pairs[i].get_y()/_y);
		}
 	}
 	catch(division_by_zero_exception ex)
 	{
 		cerr << "division by zero not allowed!!" << endl;
 	}
 	return new_Function;	
}
	

int Function::find_pair(const Pair& new_pair) const
{
	bool found=false;
	int index;
	for (int i=0;i<this->pairs.size();i++)
	{
		if (this->pairs[i].get_x()==new_pair.get_x() && this->pairs[i].get_y()==new_pair.get_y())
		{
				found=true;
				index=i;			
		}
	}	
	if (found==false)
		throw pair_not_found_exception();
	else
		return index;
}

void Function::erase_pair_by_index(const int index)
{
	 pairs.erase(pairs.begin()+index);
}

Function Function::operator-(const Pair& new_pair) const
{
	Function new_Function(*this);
	try
	 {
		int index=this->find_pair(new_pair);
		new_Function.erase_pair_by_index(index);
	 }
	 catch(pair_not_found_exception ex)
	 {
	 	cerr << "pair " ;
	 	new_pair.print_pair();
	 	cerr << "was not found! " << endl;
	 }
	return new_Function;
}
	

Function& Function::operator+=(const Pair& new_pair)
{
	
	try
	{
		this->check_mutual_domain(new_pair.get_x());
		this->add_pair(new_pair);
	}
	catch(mutual_domain_exception ex)
	{
		cerr << "mutual domain on: " << new_pair.get_x()<< "! " << endl;
	}
}

Function& Function::operator-=(const Pair& new_pair)
{
	try
	{
		 int index=this->find_pair(new_pair);
		 this->erase_pair_by_index(index);	
	}
	catch(pair_not_found_exception ex)
	{
		cerr << "pair " ;
	 	new_pair.print_pair();
	 	cerr << "was not found! " << endl;		
	}

}
// int Function::get_size() const  
// {
// 	return pairs.size();
// }

void Function::add_pair(const Pair& new_pair)
{
	try
	{
		this->find_pair_by_x(new_pair.get_x());
		throw not_a_function_exception();
	}
	catch(pair_not_found_exception ex)
	{
		pairs.push_back(new_pair);
	}
	catch(not_a_function_exception e)
	{
		cerr << "wont be a function!" << endl;
	}
}

void Function::print_function() const
{
	for (int i=0;i< pairs.size();i++)
		pairs[i].print_pair();
}

int Function::find_pair_by_x(const double x) const
{
	int index=-1;
	bool found=false;
	for (int i=0;i<pairs.size();i++)
	{
		if(pairs[i].get_x()==x)
		{
			found=true;
			index=i;
			return index;
		}
	}
	if (found==false)
		throw pair_not_found_exception();
}

double& Function::operator()(const double x)
{
	try 
	{
		int index=this->find_pair_by_x(x);
		return pairs[index].get_y_refrence();
	}
	catch(pair_not_found_exception ex)
	{
		cout << x << " was not in domain!" << endl;
	}
	
}

Function operator+(const Pair& new_pair,const Function& f)
{
	Function new_Function(f);
	try
	{
		new_Function.check_mutual_domain(new_pair.get_x());
		new_Function.add_pair(new_pair);
	}
	catch(mutual_domain_exception ex)
	{
		cerr << "mutual domain on: " << new_pair.get_x()<< "! " << endl;	
	}
	return new_Function;
}

Function operator-(const Pair& new_pair,const Function& f)
{
	Function new_Function(f);
	try
	{
		int index=new_Function.find_pair(new_pair);
		new_Function.erase_pair_by_index(index);
	}
	catch(pair_not_found_exception ex)
	{
		cerr << "pair " ;
	 	new_pair.print_pair();
	 	cerr << "was not found! " << endl;
	}
	return new_Function;
}

Function operator+(const double _y,const Function& f)
{
	Function new_Function(f+_y);
	return new_Function;
}

Function operator*(const double _y,const Function& f)
{
	Function new_Function(f*_y);
	return new_Function;
}

Function operator-(const double _y,const Function& f)
{
	Function new_Function((f*-1)+_y);
	return new_Function;
}


Function Function::operator++()
{
	Function new_Function(*this);
	*this=*this+1;
	return new_Function;
}
	
Function Function::operator++(int)
{
	*this=*this+1;
	Function new_Function(*this);
	return new_Function;

}

Function& Function::operator=(const Function& f)
{
	int size=pairs.size();
	for (int i=0;i<size;i++)
		pairs.pop_back();
	for(int i=0;i<f.pairs.size();i++)
	{
		pairs.push_back(f.pairs[i]);
	}
}

Function& Function::operator+=(const Function& f)
{	
	int index;
	
	for(int i=0;i<f.pairs.size();i++)
	{
		try
		{
			index=find_pair_by_x(f.pairs[i].get_x());
			pairs[index].set_y(pairs[index].get_y()+f.pairs[i].get_y());
		}
		catch(pair_not_found_exception ex)
		{
			continue;
		}
	}	
}

Function& Function::operator-=(const Function& f)
{	
	int index;
	
	for(int i=0;i<f.pairs.size();i++)
	{
		try
		{
			index=find_pair_by_x(f.pairs[i].get_x());
			pairs[index].set_y(pairs[index].get_y()-f.pairs[i].get_y());
		}
		catch(pair_not_found_exception ex)
		{
			continue;
		}
	}	
}

Function Function::operator+(const Function& f) const
{
	Function new_Function(*this);
	int index;
	for(int i=0;i<new_Function.pairs.size();i++)
	{
		try
		{
			index=new_Function.find_pair_by_x(f.pairs[i].get_x());
			new_Function.pairs[index].set_y(pairs[index].get_y()+f.pairs[i].get_y());
		}
		catch(pair_not_found_exception ex)
		{
			new_Function.erase_pair_by_index(i);
		}
	}	

	return new_Function;
}

Function Function::operator-(const Function& f) const
{
	Function new_Function(*this);
	int index;
	for(int i=0;i<new_Function.pairs.size();i++)
	{
		try
		{
			index=new_Function.find_pair_by_x(f.pairs[i].get_x());
			new_Function.pairs[index].set_y(pairs[index].get_y()-f.pairs[i].get_y());
		}
		catch(pair_not_found_exception ex)
		{
			new_Function.erase_pair_by_index(i);
		}
	}	

	return new_Function;
}

bool Function::operator==(const Function& f)
{
	if (pairs.size()!=f.pairs.size())
		return false;
	else
	{
		
		for (int i=0;i<pairs.size();i++)
		{
			try
			{
				f.find_pair(pairs[i]);
			}
			catch(pair_not_found_exception ex)
			{
				return false;
			}
		}
		return true;
	}

}

Function Function::operator|(const Function& f) const
{
	Function new_Function(*this);
	int index;
	for(int i=0;i<new_Function.pairs.size();i++)
	{
		try
		{
			index=new_Function.find_pair_by_x(f.pairs[i].get_x());
			new_Function.pairs[index].set_y(pairs[index].get_y()+f.pairs[i].get_y());
		}
		catch(pair_not_found_exception ex)
		{
			continue;
		}
	}	
	for(int i=0;i<f.pairs.size();i++)
	{
		try
		{
			index=f.find_pair_by_x(new_Function.pairs[i].get_x());
			continue;
		}
		catch(pair_not_found_exception ex)
		{
			new_Function.add_pair(f.pairs[i]);
		}
	}

	return new_Function;	
}

Function& Function::operator|=(const Function& f)
{
	
	int index;
	for(int i=0;i<pairs.size();i++)
	{
		try
		{
			index=this->find_pair_by_x(f.pairs[i].get_x());
			pairs[index].set_y(pairs[index].get_y()+f.pairs[i].get_y());
		}
		catch(pair_not_found_exception ex)
		{
			continue;
		}
	}	
	for(int i=0;i<f.pairs.size();i++)
	{
		try
		{
			index=f.find_pair_by_x(pairs[i].get_x());
			continue;
		}
		catch(pair_not_found_exception ex)
		{
			this->add_pair(f.pairs[i]);
		}
	}
	
}
Function Function::operator()(const Function& f)
{
	Function new_Function;
	int index;
	for (int i=0;i<f.pairs.size();i++)
	{
		double x=f.pairs[i].get_x();
		double _x=f.pairs[i].get_y();
		try
		{	
			int index=this->find_pair_by_x(_x);
			double y=pairs[index].get_y();
			Pair temp(x,y);
			new_Function.add_pair(temp);
		}
		catch (pair_not_found_exception ex)
		{
			continue;
		}
	}
	return new_Function;
}

ostream& operator<<(ostream& out,const Function& f)
{
	for (int i=0;i<f.pairs.size();i++)
	{
		out << "(" << f.pairs[i].get_x() << "," << f.pairs[i].get_y();
			if (i==f.pairs.size()-1)
				out << ")" << endl;
			else
				out << "), ";
	}
	return out;
}
