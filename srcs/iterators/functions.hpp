/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:28:21 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/26 21:19:39 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FUNCTIONS_HPP__
# define __FUNCTIONS_HPP__
# include <iostream>

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





	/*
	**	is_integral
	*/

	template <class T, T v>
	struct	integral_constant
	{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		
		operator		T() const
		{
			return (v);
		}
	};
	
	
	template<typename>
				struct	_is_integral_help :								public std::false_type	{ };
	template<> struct	_is_integral_help <bool> :						public std::true_type	{ };
	template<> struct	_is_integral_help <char> :						public std::true_type	{ };
	template<> struct	_is_integral_help <wchar_t> :					public std::true_type	{ };
	template<> struct	_is_integral_help <signed char> :				public std::true_type	{ };
	template<> struct	_is_integral_help <short int> :					public std::true_type	{ };
	template<> struct	_is_integral_help <int> :						public std::true_type	{ };
	template<> struct	_is_integral_help <long int> :					public std::true_type	{ };
	template<> struct	_is_integral_help <long long int> :				public std::true_type	{ };
	template<> struct	_is_integral_help <unsigned char> :				public std::true_type	{ };
	template<> struct	_is_integral_help <unsigned int> :				public std::true_type	{ };
	template<> struct	_is_integral_help <unsigned short int> :		public std::true_type	{ };
	template<> struct	_is_integral_help <unsigned long long int> :	public std::true_type	{ };
	template<> struct	_is_integral_help <unsigned long int> :			public std::true_type	{ };
	
	template <typename T> struct	remove_const						{ typedef T	type; };
	template <typename T> struct	remove_const <T const>				{ typedef T	type; };
	template <typename T> struct	remove_volatile						{ typedef T	type; };
	template <typename T> struct	remove_volatile <T volatile>		{ typedef T	type; };
	
	template <typename T>
	struct	remove_cv
	{
		typedef typename	remove_const<typename remove_volatile<T>::type>::type type;
	};
	
	template <class T>
	struct	is_integral :
		public integral_constant<bool, (_is_integral_help<typename remove_cv<T>::type>::value)> {	};
	








	/*
	**	Equal compare
	*/

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
	    							InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
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




	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
	







	/*
	**	make_pair
	*/




	template <typename _Iterator>
		struct iterator_traits
	    {
			typedef typename _Iterator::iterator_category					iterator_category;
			typedef typename _Iterator::value_type							value_type;
			typedef typename _Iterator::difference_type						difference_type;
			typedef typename _Iterator::pointer								pointer;
			typedef typename _Iterator::reference							reference;
		};
	
	
	template <typename _Tp>
		struct iterator_traits<_Tp*>
		{
			typedef std::random_access_iterator_tag							iterator_category;
			typedef _Tp														value_type;
			typedef ptrdiff_t												difference_type;
			typedef _Tp*													pointer;
			typedef _Tp&													reference;
		};
	
	
	template <typename _Tp>
		struct iterator_traits<const _Tp*>
		{
			typedef std::random_access_iterator_tag 						iterator_category;
			typedef _Tp														value_type;
			typedef ptrdiff_t												difference_type;
			typedef const _Tp*												pointer;
			typedef const _Tp&												reference;
		};
}




//void	ft_leaks()
//{
//	std::cout << "\n\n\n" << std::endl;
//	system("leaks ft_containers | grep bytes");
//}
#endif