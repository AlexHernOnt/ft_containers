/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:02:32 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/25 16:50:14 by ahernand         ###   ########.fr       */
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

				void push(const value_type& val)
				{
					_vec.push_back(val);
				}
				
				void pop()
				{
					_vec.pop_back();					
				}




				/*
				**		___________________		Operator=     ___________________
				*/

				template <typename U, typename _container>
				friend bool operator==(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs._vec == rhs._vec);
				}
			
				template <typename U, typename _container>
				friend bool operator!=(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs._vec != rhs._vec);
				}
			
				template <typename U, typename _container>
				friend bool operator<(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs._vec < rhs._vec);
				}
			
				template <typename U, typename _container>
				friend bool operator<=(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs._vec <= rhs._vec);
				}
			
				template <typename U, typename _container>
				friend bool operator>(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs._vec > rhs._vec);
				}
			
				template <typename U, typename _container>
				friend bool operator>=(stack<U, _container> const &lhs, stack<U, _container> const &rhs)
				{
					return (lhs._vec >= rhs._vec);
				}


			
				/*
				**		___________________		Operator=     ___________________
				*/

				stack	&operator=(const stack &ref)
				{
					this->_vec = ref._vec();
				}




				/*
				**		___________________		Cons & Dest     ___________________
				*/

				explicit stack (const container_type& ctnr = container_type()) : _vec(ctnr)
				{
				}

				~stack()
				{
				}
	};
}

#endif