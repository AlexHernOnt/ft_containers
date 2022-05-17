/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:55:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/17 20:26:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "iterators/functions.hpp"
# include "iterators/map_iterators.hpp"
# include "iterators/BST.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef	Compare											key_compare;
//			typedef													value_compare;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;

			
			typedef node<value_type>								node_type;
			
			typedef ft::map_iterator<value_type, node_type>			iterator;
			typedef ft::map_iterator<const value_type, node_type>	const_iterator;


//			typedef 												reverse_iterator;
//			typedef 												const_reverse_iterator;
//			typedef 												difference_type;
			typedef size_t											size_type;

			node<value_type>										*_root;
		private:
			allocator_type											_allocator;
			key_compare												_compare;
			size_type												_size;

		public:




			/*
			**		___________________		Iterators     ___________________
			*/

			iterator						begin()
			{
				return (ft::map_iterator<value_type, node_type>(bst_get_first(_root)));
			}

			const_iterator					begin() const
			{
				return (ft::map_iterator<value_type, node_type>(bst_get_first(_root)));

			}

			iterator						end()
			{
				return (bst_get_last(_root));
			}

			const_iterator					end() const
			{
				return (bst_get_last(_root));
			}








			/*
			**		___________________		Capacity     ___________________
			*/

			bool							empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			size_type						size() const
			{
				return (_size);				
			}

			size_type						max_size() const
			{
				return (_allocator.max_size());
			}








			/*
			**		___________________		Element Access     ___________________
			*/

			mapped_type&					operator[] (const key_type& k)
			{
				node_type					*aux;

				aux = bst_search(_root, k);
				if (aux == NULL)
				{
					T		b;

					insert(ft::pair<const Key, T>(k, b));
					aux = bst_search(_root, k);
				}
				return (aux->data.second);
			}








			/*
			**		___________________		Modifiers     ___________________
			*/




			//		___________________		Insert     ___________________	




			ft::pair<iterator, bool>		insert (const value_type &val)
			{
				bool					existed;

				if (bst_search(_root, val.first) == NULL)
					existed = false;
				else
					existed = true;

				if (_size == 0)
				{
					if (_root != NULL)
						delete _root;
					_root = new node<value_type>(val, NULL, 0);
					_root->right = new node<value_type>(val, _root, 1);

				}
				else
					new_node(_root, _root, val);
				_size++;
				return (ft::pair<iterator, bool>(iterator(bst_search(_root, val.first)), existed));
			}




			iterator						insert(iterator position, const value_type& val)
			{
				if (&position == NULL)
					;
				insert(val);
				return (iterator(bst_search(_root, val.first)));
			}




			template <class InputIterator>
			void							insert (InputIterator first, InputIterator last)
			{

				for (; first != last; first++)
				{
					insert(ft::pair<const Key, T>((first)->first, (first)->second));
				}
			}








			//		___________________		Erease     ___________________	




			size_type						erase(const key_type &val)
			{
				mapped_type				mapped_aux;

				if (bst_search(_root, val) == NULL)
					return (0);				
				_root = delete_node(_root, ft::pair<const key_type, mapped_type>(val, mapped_aux), _root);
				--_size;
				return (1);
			}




			void							erase(iterator position)
			{
				erase (position._ptr->data.first);
			}




			void							erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase (first);
					first++;
				}
			}








			//		___________________		Swap     ___________________	




			void	swap (map& x)
			{
				ft::map<Key, T, Compare, Alloc>						aux;
				
				aux.complete_memory_copy(*this);
				this->complete_memory_copy(x);
				x.complete_memory_copy(aux);
				aux._root = NULL;
			}








			//		___________________		Swap     ___________________	




			void clear()
			{
				Key							a;
				T							b;

				_size = 0;
				clear_tree(_root);
				_root = new node<value_type>(ft::pair<const Key, T>(a, b), NULL, 1);
			}








			/*
			**		___________________		Observers     ___________________
			*/




			key_compare						key_comp() const
			{
				return (_compare);
			}



			//value_compare					value_comp() const
			//{
			//	return (_compare);
			//}








			/*
			**		___________________		Operations     ___________________
			*/




			iterator						find(const key_type &k)
			{
				node_type					*aux;

				aux = bst_search(_root, k);
				if (aux == NULL)
					return (end());
				return (iterator(aux));
			}




			const_iterator						find(const key_type &k) const
			{
				node_type						*aux;

				aux = bst_search(_root, k);
				if (aux == NULL)
					return (end());
				return (const_iterator(aux));
			}








			/*
			**		___________________		Allocator     ___________________
			*/
			
			
			
			
			allocator_type					get_allocator() const
			{
				return (_allocator);				
			}








			/*
			**		___________________		Operator =     ___________________
			*/

			map&							operator= (const map& x)
			{
				clear_tree(_root);
				_root = NULL;
				_size = 0;
				insert(x.begin(), x.end());
				return (*this);
			}








			/*
			**		___________________		Cons & Dest     ___________________
			*/




			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				Key		a;
				T		b;

				_root = new node<value_type>(ft::pair<const Key, T>(a, b), NULL, 1);
				_allocator = alloc;
				_compare = comp;
				_size = 0;
			}




			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				_compare = comp;
				_size = 0;
				insert(first, last);
			}




			map (const map& x)
			{
				_size = 0;
				insert(x.begin(), x.end());
			}




			~map()
			{
				clear_tree(_root);
			}

			private:
				void	complete_memory_copy(map	&x)
				{
					_size = x.size();
					_allocator = x.get_allocator();
					_compare = x._compare; 
					_root = x._root;
				}
	};
}

#endif