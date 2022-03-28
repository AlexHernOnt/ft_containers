/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/03/28 18:59:44 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include <iostream>

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		typedef unsigned int size_type;
		
		private:
			size_type _size;
			
		public:


			vector(const T &ref);
			explicit vector();
			~vector();
	};
	











	

	/*
	**		Cons & Dest
	*/
	
	template<typename T, class Allocator>
	vector<T, Allocator>::vector(const T &ref)
	{
		_size = 1;
	}
	


	vector (Allocator &alloc = allocator_type());




	template<typename T, class Allocator>
	vector<T, Allocator>::vector() 
	{

	}
		
	template<typename T, class Allocator>
	vector<T, Allocator>::~vector()
	{

	}
}
typedef int lenght;
#endif