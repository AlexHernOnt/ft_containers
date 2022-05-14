/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:28:21 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/14 17:46:56 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FUNCTIONS_HPP__
# define __FUNCTIONS_HPP__

namespace ft
{
	/*
	**	Enable if
	*/

	template <bool, class IsTrue = void>
	struct enable_if;

	template <class IsTrue>
	struct enable_if < true, IsTrue >
	{
		typedef IsTrue type;
	};


	struct IteratorTrait
	{

	};




	/*
	**	is_integral
	*/









	/*
	**	Equal compare
	*/

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
	    							InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}




	/*
	**	Lexicographical compare
	*/

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first1 > *first2)
				return (false);
			first1++;
			first2++;
		}
		if (first1 == last1 && first2 != last2)
			return (true);
		else if (first1 != last1 && first2 == last2)
			return (false);
		return (false);
	}





	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}




	/*
	**	pair
	*/

		template <class T1, class T2>
		struct  pair
		{
			typedef T1					first_type;
			typedef T2					second_type;

			public:
				first_type				first;
				second_type				second;

			pair				&operator=(const pair &ref)
			{
				if (this == &ref)
					return (*this);
				first = ref.first;
				second = ref.second;
				return (*this);
			}

			// Cons & Des
			pair()
			{
				
			}
			
			template<class T, class K>
			pair(const pair<T, K> &ref) : first(ref.first), second(ref.second)
			{
			}
			
			pair(const first_type &g_first, const second_type &g_second)  : first(g_first), second(g_second)
			{
			}
		};





	/*
	**	make_pair
	*/














}


void	ft_leaks()
{
	std::cout << "\n\n\n" << std::endl;
	system("leaks ft_containers | grep bytes");
}
#endif