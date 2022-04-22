/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:28:21 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/22 14:08:41 by ahernand         ###   ########.fr       */
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











	/*
	**	make_pair
	*/














}
#endif