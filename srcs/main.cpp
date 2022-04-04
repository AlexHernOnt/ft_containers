/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:49:08 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/04 19:45:04 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main ()
{
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
	{
		std::cout << vector[i] << std::endl;
	}
	return (0);	
}










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
	{
		std::cout << vector[i] << std::endl;
	}
	return (0);	
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