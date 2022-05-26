/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:02:32 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/26 20:47:53 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__
# include "vector.hpp"
# include "iterators/functions.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T													value_type;
			typedef Container											container_type;
			typedef size_t												size_type;
			
		protected:
			container_type												c;

		public:
				bool empty() const
				{
					return (c.empty());
				}

				size_type size() const
				{
					return (c.size());
				}

				value_type& top()
				{
					return (c.back());
				}

				const value_type& top() const
				{
					return (c.back());
				}

				void push(const value_type& val)
				{
					c.push_back(val);
				}
				
				void pop()
				{
					c.pop_back();					
				}




				/*
				**		___________________		Operator=     ___________________
				*/

				template <typename U, typename _container>
				friend bool operator==(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs.c == rhs.c);
				}
			
				template <typename U, typename _container>
				friend bool operator!=(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs.c != rhs.c);
				}
			
				template <typename U, typename _container>
				friend bool operator<(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs.c < rhs.c);
				}
			
				template <typename U, typename _container>
				friend bool operator<=(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs.c <= rhs.c);
				}
			
				template <typename U, typename _container>
				friend bool operator>(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs.c > rhs.c);
				}
			
				template <typename U, typename _container>
				friend bool operator>=(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs.c >= rhs.c);
				}


			
				/*
				**		___________________		Operator=     ___________________
				*/

				stack	&operator=(const stack &ref)
				{
					this->c = ref.c();
				}




				/*
				**		___________________		Cons & Dest     ___________________
				*/

				explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
				{
				}

				~stack()
				{
				}
	};
}

#endif