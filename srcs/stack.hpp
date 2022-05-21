/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:02:32 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/21 20:35:57 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__
# include <iostream>
# include "iterators/functions.hpp"
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T													value_type;
			typedef Container											container_type;
			typedef size_t												size_type;

		private:
			container_type												_vec;

		public:
				bool empty() const
				{
					return (_vec.empty());
				}




				size_type size() const
				{
					return (_vec.size());
				}




				value_type& top()
				{
					return (_vec.back());
				}




				const value_type& top() const
				{
					return (_vec.back());
				}


				void push (const value_type& val)
				{
					_vec.push_back(val);
				}

				void pop()
				{
					_vec.pop_back();					
				}





				/*
				**		___________________		Cons & Dest     ___________________
				*/

				explicit stack (const container_type& ctnr = container_type())
				{
					_vec = ctnr;
				}

				virtual ~stack()
				{
				
				}
	};
}

#endif