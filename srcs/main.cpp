/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:49:08 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/25 17:06:42 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TYPE ft

#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "iterators/tests.hpp"

#include <map>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>    // std::lexicographical_compare


int main()
{
	test_vector();
	test_vector_iterators();
	return (0);
}













































































/*
	struct timeval start;
	gettimeofday(&start, NULL);
	
	test_lexicolographical_compare();
	test_vector_iterators()
	test_vector_reverse_iterators();





	std::cout << "___________________" << std::endl;
	std::cout << "_ It took: _" << time_now(&start) << "_ ms" << std::endl;
	std::cout << "___________________" << std::endl;

*/




//			888     888                   888                     
//			888     888                   888                     
//			888     888                   888                     
//			Y88b   d88P  .d88b.   .d8888b 888888  .d88b.  888d888 
//			 Y88b d88P  d8P  Y8b d88P"    888    d88""88b 888P"   
//			  Y88o88P   88888888 888      888    888  888 888     
//			   Y888P    Y8b.     Y88b.    Y88b.  Y88..88P 888     
//			    Y8P      "Y8888   "Y8888P  "Y888  "Y88P"  888     


//
//		____________________________ Constructors _____________________________
//

void test_constructors()
{
	std::cout << "\n\nConstructors" << std::endl;

	TYPE::vector<int>		a;
	TYPE::vector<int>		b(2, 42);
	TYPE::vector<int>		c(b.begin(), b.end());
	TYPE::vector<int>		d(b);

	std::cout << "Fill Constructor: " << std::endl;
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
		
	std::cout << "Range Constructor: " << std::endl << std::endl;
	for (size_t i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
		
	std::cout << "Copy Constructor: " << std::endl << std::endl;
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << std::endl;
}




//
//		______________________________ Assaign ________________________________
//

void test_assign()
{
	std::cout << "\n\nAssaign" << std::endl;

	TYPE::vector<int> first;
	TYPE::vector<int> second;
	TYPE::vector<int> third;
	
	first.assign (7, 100);
	
	TYPE::vector<int>::iterator it;
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




//
//		___________________________ Swap External _____________________________
//

void test_swap_external()
{
	std::cout << "\n\nSwap External" << std::endl;

	TYPE::vector<int> foo (3,100);   // three ints with a value of 100
	TYPE::vector<int> bar (5,200);   // five ints with a value of 200
		
	swap(foo, bar);
	
	TYPE::vector<int>::iterator it = foo.begin();
		
	std::cout << "foo contains:";
	while (it != foo.end())
	{
		std::cout << ' ' << *it;
		++it;
	}
	std::cout << '\n';
		
	std::cout << "bar contains:";
	for (TYPE::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}




//
//		_______________________ Lexicographical_compare _______________________
//

bool	mycomp (int c1, int c2)
{
	return (c1 == c2);
}

void	test_lexicolographical_compare()
{
	std::cout << "\n\nLexicographical_compare" << std::endl;
	TYPE::vector<int> foo1;
	TYPE::vector<int> boo1;

	foo1.push_back(1);
	foo1.push_back(1);
	foo1.push_back(5);
	
	boo1.push_back(1);
	boo1.push_back(1);
	boo1.push_back(6);

	std::cout << "Test 1: " << TYPE::lexicographical_compare(foo1.begin(), foo1.begin() + 3, boo1.begin(), boo1.begin() + 3) << std::endl;




	TYPE::vector<int> foo2;
	TYPE::vector<int> boo2;

	foo2.push_back(10);
	
	boo2.push_back(99);

	std::cout << "Test 2: " << TYPE::lexicographical_compare(foo2.begin(), foo2.begin() + 1, boo2.begin(), boo2.begin() + 1, mycomp) << std::endl;





	TYPE::vector<int> foo3;
	TYPE::vector<int> boo3;

	foo3.push_back(10);
	
	boo3.push_back(10);

	std::cout << "Test 3: " << TYPE::lexicographical_compare(foo3.begin(), foo3.begin() + 1, boo3.begin(), boo3.begin() + 1, mycomp) << std::endl;
	



	TYPE::vector<int> foo4;
	TYPE::vector<int> boo4;

	foo4.push_back(1200);
	foo4.push_back(0);
	
	boo4.push_back(1200);
	boo4.push_back(1234);

	std::cout << "Test 4: " << TYPE::lexicographical_compare(foo4.begin(), foo4.begin() + 2, boo4.begin(), boo4.begin() + 2, mycomp) << std::endl;




	TYPE::vector<int> foo5;
	TYPE::vector<int> boo5;

	foo5.push_back(1200);
	foo5.push_back(0);
	
	boo5.push_back(12);
	boo5.push_back(10);

	std::cout << "Test 5: " << TYPE::lexicographical_compare(foo5.begin(), foo5.begin() + 2, boo5.begin(), boo5.begin() + 2, mycomp) << std::endl;	

}









//			88 888888 888888 88""Yb    db    888888  dP"Yb  88""Yb .dP"Y8 
//			88   88   88__   88__dP   dPYb     88   dP   Yb 88__dP `Ybo." 
//			88   88   88""   88"Yb   dP__Yb    88   Yb   dP 88"Yb  o.`Y8b 
//			88   88   888888 88  Yb dP""""Yb   88    YbodP  88  Yb 8bodP' 


void	vi_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator				it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	it++;
	itc++;

	if (it == itc)
		std::cout << "it is equal" << std::endl;
}

void	vi_not_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator				it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	itc++;

	if (it != itc)
		std::cout << "it is not equal" << std::endl;
}

void	vi_major()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	it++;

	if (it > itc)
		std::cout << "it is bigger" << std::endl;
}

void	vi_major_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	if (it >= itc)
		std::cout << "it is bigger/equal" << std::endl;
}

void	vi_minor()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	itc++;

	if (it < itc)
		std::cout << "it is smaller" << std::endl;
}

void	vi_minor_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	if (it <= itc)
		std::cout << "it is smaller/equal" << std::endl;
}

void	vi_plus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	std::cout << *(it + 1) << std::endl;
	std::cout << *it << std::endl << std::endl;

}

void	vi_plus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	std::cout << *(it += 1) << std::endl;
	std::cout << *it << std::endl << std::endl;

}

void	vi_minus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	it++;
	it++;
	std::cout << *(it - 1) << std::endl;
	std::cout << *it << std::endl << std::endl;
}

void	vi_minus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	it++;
	it++;
	std::cout << *(it -= 1) << std::endl;
	std::cout << *it << std::endl << std::endl;
}


void	vi_incre_pre()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	itc = vector.begin();
	it = vector.begin();

	std::cout << "Const:     " << *(++itc) << std::endl;
	std::cout << "Non Const: " << *(++it) << std::endl;
}

void	vi_incre_post()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	itc = vector.begin();
	it = vector.begin();

	std::cout << "Const:     " << *(itc++) << " -> " << *itc << std::endl;
	std::cout << "Non Const: " << *(it++)  << " -> " << *it  << std::endl << std::endl;
}

void	vi_decre_pre()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;

	itc = vector.begin();
	it = vector.begin();

	it++;
	it++;

	itc++;
	itc++;

	std::cout << "Const:     " << *(--itc) << std::endl;
	std::cout << "Non Const: " << *(--it) << std::endl;
}

void	vi_decre_post()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	itc = vector.begin();
	it = vector.begin();

	it++;
	it++;

	itc++;
	itc++;

	std::cout << "Const:     " << *(itc--) << " -> " << *itc << std::endl;
	std::cout << "Non Const: " << *(it--)  << " -> " << *itc << std::endl << std::endl;
}

void	vi_copy()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);


	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	it = vector.begin();
	it++;
	it++;

	itc = it;

	std::cout << "Copied: " << *itc << " _ Original: " << *it << std::endl;
}

void	vi_dereference()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator	itc;

	itc = vector.begin();
	it = vector.begin();

	it++;
	it++;

	itc++;
	itc++;

	std::cout << "Const:     " << *(itc) << std::endl;
	std::cout << "Non Const: " << *(it) << std::endl;

	int &og = *(it);

	og = 42;

	std::cout << og << " _ " << *(itc)<< std::endl;
}

void	vi_brackets()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator	itc;

	itc = vector.begin();
	it = vector.begin();

	std::cout << "Const:     " << itc[2] << std::endl;
	std::cout << "Non Const: " << it[2] << std::endl;
}

void	test_vector_iterators()
{
	vi_equal();
	vi_not_equal();
	vi_minor();
	vi_minor_equal();
	vi_major();
	vi_major_equal();
	vi_plus();
	vi_plus_equal();
	vi_minus();
	vi_minus_equal();
	vi_incre_pre();
	vi_incre_post();
	vi_decre_pre();
	vi_decre_post();
	vi_copy();
	vi_dereference();
	vi_brackets();
}

void	test_vector()
{
	//	Construct
	{
		std::vector<int>	first;                                // empty vector of ints
		std::vector<int>	second (4,100);                       // four ints with value 100
		std::vector<int>	third (second.begin(),second.end());  // iterating through second
		std::vector<int>	fourth (third);                       // a copy of third
		
		int											myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		
		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	//	Operator=
	{
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);
		
		bar = foo;
		foo = std::vector<int>();
		
		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}	
	//	Begin
	{
		std::vector<int> myvector;
		for (int i = 1; i <= 5; i++) myvector.push_back(i);
		
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	//	End
	{
		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);
		
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	//	Rbegin
	{
		std::vector<int> myvector (5);  // 5 default-constructed ints

		int i = 0;

		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	//	Rend
	{
		std::vector<int> myvector (5);  // 5 default-constructed ints
		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		
		int i = 0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;
		
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	//	Size
	{
		std::vector<int>	myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i = 0; i < 10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(), 10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}
	//	Max Size
	{
		std::vector<int>	myvector;
	
		for (int i = 0; i < 100; i++) myvector.push_back(i);
	
		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}	
	//Resize
	{
		std::vector<int> myvector;
		
		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);
		
		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		
		std::cout << "myvector contains:";
		for (size_t i = 0; i < myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	//Capacity
	{
		std::vector<int> myvector;
	
		// set some content in the vector:
		for (int i = 0; i < 100; i++) myvector.push_back(i);
	
		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	//Empty
	{
		std::vector<int> myvector;
		int sum (0);
		
		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);
		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		std::cout << "total: " << sum << '\n';
	}
	//Reserve
	{
		std::vector<int>::size_type			sz;
	
		std::vector<int>					foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			foo.push_back(i);
			if (sz!=foo.capacity())
			{
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	
		std::vector<int>					bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			bar.push_back(i);
			if (sz!=bar.capacity())
			{
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
}





















	







/*


//			88""Yb 888888 Yb    dP 888888 88""Yb .dP"Y8 888888     88 888888 888888 88""Yb    db    888888  dP"Yb  88""Yb .dP"Y8 
//			88__dP 88__    Yb  dP  88__   88__dP `Ybo." 88__       88   88   88__   88__dP   dPYb     88   dP   Yb 88__dP `Ybo." 
//			88"Yb  88""     YbdP   88""   88"Yb  o.`Y8b 88""       88   88   88""   88"Yb   dP__Yb    88   Yb   dP 88"Yb  o.`Y8b 
//			88  Yb 888888    YP    888888 88  Yb 8bodP' 888888     88   88   888888 88  Yb dP""""Yb   88    YbodP  88  Yb 8bodP' 



void	vri_equal()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();
	if (rit == rita)
		std::cout << "These are equal" << std::endl;
}

void	vri_not_equal()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();
	rita++;

	if (rit != rita)
		std::cout << "These are not equal" << std::endl;
}



void	vri_minor()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	rita++;
	if (rit < rita)
		std::cout << "First is minor" << std::endl;
}

void	vri_minor_equal()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	if (rit <= rita)
		std::cout << "First is minor or equal" << std::endl;
}

void	vri_major()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	rit++;
	if (rit > rita)
		std::cout << "First is mayor" << std::endl;
}

void	vri_major_equal()
{
 	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	if (rit >= rita && *(rit++) && rit >= rita)
		std::cout << "First is mayor/equal" << std::endl;
}


void	vri_plus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	std::cout << *(rit + 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}

void	vri_plus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	std::cout << *(rit += 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}

void	vri_minus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	rit++;
	rit++;
	std::cout << *(rit - 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}

void	vri_minus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	rit++;
	rit++;
	std::cout << *(rit -= 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}


void	vri_incre_pre()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	rit = vector.rbegin();
	ritc = vector.rbegin();

	std::cout << "Const:     " << *(++rit) << std::endl;
	std::cout << "Non Const: " << *(++ritc) << std::endl;
}

void	vri_incre_post()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	rit = vector.rbegin();
	ritc = vector.rbegin();

	std::cout << "Const:     " << *(ritc++) << " -> " << *ritc << std::endl;
	std::cout << "Non Const: " << *(rit++)  << " -> " << *rit  << std::endl << std::endl;
}

void	vri_decre_pre()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;

	ritc = vector.rbegin();
	rit = vector.rbegin();

	rit++;
	rit++;

	ritc++;
	ritc++;

	std::cout << "Const:     " << *(--ritc) << std::endl;
	std::cout << "Non Const: " << *(--rit) << std::endl;
}

void	vri_decre_post()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	ritc = vector.rbegin();
	rit = vector.rbegin();

	rit++;
	rit++;

	ritc++;
	ritc++;

	std::cout << "Const:     " << *(ritc--) << " -> " << *ritc << std::endl;
	std::cout << "Non Const: " << *(rit--)  << " -> " << *ritc << std::endl << std::endl;
}

void	vri_copy()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);


	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	rit = vector.rbegin();
	rit++;
	rit++;

	ritc = rit;

	std::cout << "Copied: " << *ritc << " _ Original: " << *rit << std::endl;
}

void	vri_dereference()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;

	rit = vector.rbegin();
	ritc = vector.rbegin();

	rit++;
	rit++;

	ritc++;
	ritc++;

	std::cout << "Const:     " << *(ritc) << std::endl;
	std::cout << "Non Const: " << *(rit) << std::endl;

	int &og = *(rit);

	og = 42;

	std::cout << og << " _ " << *(ritc)<< std::endl;
}

void	vri_brackets()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;

	rit = vector.rbegin();
	ritc = vector.rbegin();

	std::cout << "Non Const: " << rit[2] << std::endl;
	std::cout << "Const:     " << ritc[2] << std::endl;
}

void	test_vector_reverse_iterators()
{
	vri_equal();
	vri_not_equal();
	vri_minor();
	vri_minor_equal();
	vri_major();
	vri_major_equal();
	vri_plus();
	vri_plus_equal();
	vri_minus();
	vri_minus_equal();
	vri_incre_pre();
	vri_incre_post();
	vri_decre_pre();
	vri_decre_post();
	vri_copy();
	vri_dereference();
	vri_brackets();
}

*/








































//
//		_________________________ Auxiliar Functions __________________________
//

long	time_now(struct timeval	*start)
{
	long				ms;
	struct timeval		end;

	gettimeofday(&end, NULL);
	ms = (((end.tv_sec * (1000000) + end.tv_usec)
				- (start->tv_sec * 1000000 + start->tv_usec)));
	return (ms);
}

template < typename T>
void print_vector(TYPE::vector<T> aux)
{
	for (size_t i = 0; i < aux.size(); ++i)
		std::cout << aux[i] << std::endl;
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
