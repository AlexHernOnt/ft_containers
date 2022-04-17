/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:49:08 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/17 19:07:21 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "tests.hpp"
#include <vector>
#include <ctime>

int main()
{
    time_t now;
	struct tm *ts;	
    
	now = time(0);

	long long a = now;
	
	for	(int i = 0; i < 30000; i++)
		for	(int g = 0; g < 100000; g++)
			;


		
	std::cout << (a ) << std::endl;
	std::cout << (now) << std::endl;
	std::cout << (a - now) << std::endl;
	
	//test_assign();
	return (0);
}













































//			888     888                   888                     
//			888     888                   888                     
//			888     888                   888                     
//			Y88b   d88P  .d88b.   .d8888b 888888  .d88b.  888d888 
//			 Y88b d88P  d8P  Y8b d88P"    888    d88""88b 888P"   
//			  Y88o88P   88888888 888      888    888  888 888     
//			   Y888P    Y8b.     Y88b.    Y88b.  Y88..88P 888     
//			    Y8P      "Y8888   "Y8888P  "Y888  "Y88P"  888     


template < typename T>
void print_vector(ft::vector<T> aux)
{
	for (size_t i = 0; i < aux.size(); ++i)
		std::cout << aux[i] << std::endl;
}


template < typename T>
void print_vector(std::vector<T> aux)
{
	for (size_t i = 0; i < aux.size(); ++i)
		std::cout << aux[i] << std::endl;
}




void test_constructors()
{
	ft::vector<int>			a;
	ft::vector<int>		b(2, 42);
	ft::vector<int>		c(b.begin(), b.end());
	ft::vector<int>		d(b);

	std::cout << "Fill Constructor: " << std::endl;
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
		
	std::cout << "Range Constructor: " << std::endl << std::endl;
	for (int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
		
	std::cout << "Copy Constructor: " << std::endl << std::endl;
	for (int i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;
}




void test_assign()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;
	
	first.assign (7, 100);
	
	ft::vector<int>::iterator it;
	it = first.begin() + 1;
	
	second.assign (it, first.end() - 1);
	
	int myints[] = { 1776, 7, 4};
	third.assign (myints, myints + 3);

	std::cout << "Size of first: "	<< int (first.size())	<< '\n';
	print_vector(first);
	std::cout << "Size of second: "	<< int (second.size())	<< '\n';
	print_vector(second);
	std::cout << "Size of third: "	<< int (third.size())	<< '\n';
	print_vector(third);

}































/*		INSERT TEST
	ft::vector<int>		deposit;
	ft::vector<int>		vector;

	deposit.push_back(3);
	deposit.push_back(2);
	deposit.push_back(5);
	deposit.push_back(7);

	vector.insert(vector.begin(), deposit.begin(), deposit.end());
	
	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
	*/


















	//ft::vector<int> first;
	//ft::vector<int> second (4, 100);
	//ft::vector<int> third (second.begin(), second.end());
	//ft::vector<int> fourth (third);

	//// the iterator constructor can also be used to construct from arrays:
	
	//int ints[] = { 16, 2, 77, 29 };
	//ft::vector<int> fifth (ints, ints + sizeof(ints) / sizeof(int) );

	//std::cout << "The contents of fifth are:";
	
	//for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	//	std::cout << ' ' << *it;
	
	//std::cout << '\n';
















































/*
	std::vector<std::string> vector;
	
	for (int i = 0 ; i < 5; i++)
		vector.push_back("Amen");
		
	for (int i = 0 ; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
	
	std::cout << "Capacity Before: " << vector.capacity() << std::endl << std::endl;


	
	
	vector.resize(15, "PENIS");
	for (int i = 0 ; i < vector.size(); i++)				std::cout << vector[i] << std::endl;

	std::cout << "Capacity: " << vector.capacity() << std::endl;
		std::cout << vector[4] << std::endl;
	// vector.resize(8,100);
	// vector.resize(12);
	
	// std::cout << "vector contains:";
	// for (int i = 0; i < vector.size(); i++)
	// 	std::cout << ' ' << vector[i];
	// std::cout << '\n';
	*/


























/*
	std::cout << 							"_____________ Simple Iterator test __________" << "\n"<< std::endl;

	ft::vector<std::string>					vector;

	vector.push_back("Hello");
	vector.push_back("Charming");
	vector.push_back("Oh beautiful");
	
	ft::vector<std::string>::iterator		it = vector.begin();
	ft::vector<std::string>::iterator		ite = vector.end();
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
*/







/*
	std::cout << 							"_____________  Instert range test __________" << "\n"<< std::endl;

	ft::vector<int>					vector;
	ft::vector<int>::iterator		it;
	ft::vector<int>::iterator		ite;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	it = vector.begin();
	ite = vector.end();

	it++;
	vector.insert(it, 10, 42);
	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
	return (0);	
*/



/*
	std::cout << 							"_____________  Instert 2 itereators test __________" << "\n"<< std::endl;

	ft::vector<int>					vector_4iterators;
	ft::vector<int>					vector;
	ft::vector<int>::iterator		it;
	ft::vector<int>::iterator		ite;


	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	vector_4iterators.push_back(84);
	vector_4iterators.push_back(84);
	vector_4iterators.push_back(84);
	vector_4iterators.push_back(84);
	



	it = vector.begin();
	ite = vector.end();

	it++;
	it++;
	vector.insert(it, vector_4iterators.begin(), vector_4iterators.end());

	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
	return (0);	

*/











/*
	{
		std::cout << std::endl << std::endl << "_____________  Operator test  equal 1__________" << "\n"<< std::endl;
		
		ft::vector<int>		vector_1;
		ft::vector<int>		vector_2;
	
		
		if (vector_1 == vector_2)
			std::cout << " equal" << std::endl;
	}
	{
		std::cout << std::endl << std::endl << "_____________  Operator test  equal 2__________" << "\n"<< std::endl;
		
		ft::vector<int>		vector_1;
		ft::vector<int>		vector_2;
	
		vector_1.push_back(53);
		vector_2.push_back(53);
		
		if (vector_1 == vector_2)
			std::cout << " equal" << std::endl;
	}
	{
		std::cout << std::endl << std::endl << "_____________  Operator test  equal 2__________" << "\n"<< std::endl;
		
		ft::vector<int>		vector_1;
		ft::vector<int>		vector_2;
	
		vector_1.push_back(214);
		vector_2.push_back(224);
		
		if (vector_1 == vector_2)
			std::cout << " equal" << std::endl;

			
		std::cout << std::endl << std::endl << std::endl;
	}	
	{
		std::cout << std::endl << std::endl << "_____________  Operator test not equal 1__________" << "\n"<< std::endl;
		
		ft::vector<int>		vector_1;
		ft::vector<int>		vector_2;
	
		vector_1.push_back(214);
		vector_2.push_back(213);
		
		if (vector_1 != vector_2)
			std::cout << " Not equal" << std::endl;
	}
	{
		std::cout << std::endl << std::endl << "_____________  Operator test not equal 2__________" << "\n"<< std::endl;
		
		ft::vector<int>		vector_1;
		ft::vector<int>		vector_2;
	
		vector_1.push_back(214);
		
		if (vector_1 != vector_2)
			std::cout << " Not equal" << std::endl;
	}
	{
		std::cout << std::endl << std::endl << "_____________  Operator test not equal 2__________" << "\n"<< std::endl;
		
		ft::vector<int>		vector_1;
		ft::vector<int>		vector_2;
	
		vector_1.push_back(214);
		vector_2.push_back(214);
		
		if (vector_1 != vector_2)
			std::cout << " Not equal" << std::endl;
	}		
*/































































// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }
