/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/11 17:17:43 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include <iostream>
# include <cmath>

namespace ft
{
	template <typename vector>
	class vector_iterator
	{
		public:
			typedef typename vector::value_type				value_type;
			typedef value_type*								pointer_type;
			typedef value_type&								reference_type;
			typedef const value_type&						const_reference_type;

		private:
			pointer_type									m_ptr;

		public:

			/*
			**		_______________________________ Operators _______________________________
			*/

			//		________	>< Operators

			bool			operator<(vector_iterator& ref)
			{
				if (&(*m_ptr) < &(*ref))
					return (true);
				return (false);
			}

			bool			operator<=(vector_iterator& ref)
			{
				if (&(*m_ptr) <= &(*ref))
					return (true);
				return (false);
			}

			bool			operator>(vector_iterator& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}

			bool			operator>=(vector_iterator& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}
			



			//		________	+ Operators

			vector_iterator		operator+(const int n)
			{
				for (size_t i = 0; i < n; ++i)
					++m_ptr;
				return (*this);				
			}

			vector_iterator		operator+=(const int n)
			{
				for (size_t i = 0; i < n; ++i)
					++m_ptr;
				return (*this);				
			}



			//		________	- Operators

			vector_iterator		operator-(const int n)
			{
				for (size_t i = 0; i < n; ++i)
					--m_ptr;
				return (*this);				
			}

			vector_iterator		operator-=(const int n)
			{
				for (size_t i = 0; i < n; ++i)
					--m_ptr;
				return (*this);				
			}



			//		________	++-- Operators

			vector_iterator		&operator++()
			{
				m_ptr++;
				return (*this);
			}

			vector_iterator		operator++(int)
			{
				vector_iterator it_aux = *this;
				++(*this);
				return (it_aux);
			}

			vector_iterator		&operator--()
			{
				m_ptr--;
				return (*this);
			}

			vector_iterator		operator--(int)
			{
				vector_iterator it_aux = *this;
				--(*this);
				return (it_aux);
			}
			
			vector_iterator		operator=(const vector_iterator& ref)
			{
				this->m_ptr = ref.m_ptr;
				return (*this);				
			} 

			reference_type		operator[](const int &idx)
			{
				return *(m_ptr + idx);
			}

			bool				operator==(vector_iterator& ref) const
			{
				if (&(*m_ptr) == &(*ref))
					return (true);
				return (false);
			} 

			bool				operator!=(vector_iterator& ref) const
			{
				if (m_ptr != ref.m_ptr)
					return (true);				
				return (false);				
			}

			reference_type		operator*()
			{
				return (*m_ptr);
			}

			reference_type		operator->()
			{
				return (m_ptr);
			}


			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			vector_iterator()
			{
				m_ptr = NULL;
			}

			vector_iterator(pointer_type ptr)
			{
				m_ptr = ptr;
			}
	};





	//		______________________________________________________________________    V e c t o r     ______________________________________________________________________



	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef	vector_iterator<vector<T> >				iterator;
			// typedef	vector_const_iterator<vector<T> >		const_iterator;



			typedef size_t									size_type;

		private:
			size_type										_size;
			size_type										_capacity;
			allocator_type									_allocator;
			value_type										*_ptr;

		public:

			/*
			**		_______________________________ Iterators _______________________________
			*/

			iterator begin()
			{
				return (vector_iterator<vector<T> >(_ptr));
			}

			//const_iterator begin()
			//{
			//	if (!empty())
			//		return (vector_iterator<vector<T> >(_ptr));
			//}
			
			iterator end()
			{
				return (vector_iterator<vector<T> >(_ptr + _size));
			}




			/*
			**		_______________________________ Capacity ________________________________
			*/

			size_type	size() const
			{
				return (_size);
			}
			
			size_type	max_size() const
			{
				return (_allocator.max_size());
			}

			//When in resize: n < (_capacity *2), ej(80 < 128) the reisize goes to that 128 instead of the 80
			void		resize (size_type n, value_type val = value_type())
			{
				if (n <= _size)
					_size = n;
				else
				{
					if (n > _capacity)
						reserve(n);

					while (_size < n)
					{
						_ptr[_size] = val;
						_size++;
					}
				}
			}

			size_type	capacity() const
			{
				return (_capacity);
			}

			bool empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}
			
			void reserve (size_type n)
			{
				if (n > max_size())
					std::length_error("Error: reserve: trying to reserve more memory than possible by system.");
				if (n > _capacity)
				{
					value_type				*aux;

					_capacity = n;
					aux = _allocator.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						aux[i] = _ptr[i];
					}
					if (_ptr != NULL)
					{
						_allocator.deallocate(_ptr, _capacity);
					}
					_ptr = aux;
				}
			}




			/*
			**		_____________________________ Element access ____________________________
			*/

			reference operator[] (size_type n)
			{
				return (_ptr[n]);
			}

			const_reference operator[] (size_type n) const
			{
				return (_ptr[n]);
			}


			reference at(size_type n)
			{
				if (n < size())
					return (_ptr[n]);
				else
					throw (std::out_of_range("Error: at: trying to access out of bound element."));
			}	

			const_reference	at(size_type n) const
			{
				if (n < size())
					return (_ptr[n]);
				else
					throw (std::out_of_range("Error: at: trying to access out of bound element."));
			}


			reference front()
			{
				return (_ptr[0]);
			}
			
			const_reference front() const
			{
				return (_ptr[0]);
			}


			reference back()
			{
				return (_ptr[_size - 1]);
			}
			
			const_reference back() const
			{
				return (_ptr[_size - 1]);
			}




			/*
			**		_______________________________ Modifiers _______________________________
			*/
			
			//		_________________                 Assign                _________________


			void assign (size_type n, const value_type& val)
			{
				reserve(n);
				_size = n;
				for (size_type i = 0; i < n; ++i)
					_ptr[i] = val;
			}




			//		_________________               Push Back               _________________
			
			void	push_back (const value_type& val)
			{
				if (_capacity == 0)
				{
					_ptr = _allocator.allocate(1);
					_ptr[_size] = val;
					_capacity++;
				}
				else if (_size == _capacity)
				{
					reserve(_capacity * 2);
					_ptr[_size] = val;
				}
				else
					_ptr[_size] = val;
				_size++;
			}

			//		_________________               Push Back               _________________

			void pop_back()
			{
				if (_size >= 1)
					_size--;
			}




			//		_________________                 Insert                 _________________
			
			iterator insert (iterator position, const value_type& val)
			{
				iterator	it;
				iterator	ite;
				int			i;

				it = begin();
				ite = end();
				ite++;
				i = 0;

				while (it != position && it != ite)
				{
					it++;
					i++;
				}
				if (it != ite)
				{
					reserve(_size + 1);			// Too slow 1 to 1, expands only 1 time each, have to expand to x2 duuuhhh
					_size++;
					int a = _size - 1;
					int b = _size - 2;

					while (a != i)
					{
						_ptr[a] = _ptr[b];
						a--;
						b--;
					}
					_ptr[i] = val;
					
					it = begin();
					for (size_t j = 0; j < i; ++j)
					{
						it++;
					}
					return (it);
				}
				return (position);
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				iterator	it;
				iterator	ite;
				int			i;

				it = begin();
				ite = end();
				ite++;
				i = 0;

				while (it != position && it != ite)
				{
					it++;
					i++;
				}
				if (it != ite)
				{
					reserve(_size + n);
					_size = _size + n;
					int a = i + n;
					int b = i;

					while (a != _size)
					{
						_ptr[a] = _ptr[b];
						a++;
						b++;
					}
					a = i;
					while (a < i + n)
					{
						_ptr[a] = val;
						a++;
					}
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				size_type	size_iterators;
				iterator	it = begin();
				iterator	ite = end();
				int			i;

				size_iterators = 0;
				ite++;
				i = 0;
				while (it != position && it != ite)
				{
					it++;
					i++;
				}
				if (it != ite)
				{
					iterator first_aux = first;
					while (first_aux != last)
					{
						first_aux++;
						size_iterators++;
					}
					reserve(_size + size_iterators);
					_size = _size + size_iterators;
					int a = i + size_iterators;
					int b = i;

					while (a != _size)
					{
						_ptr[a] = _ptr[b];
						a++;
						b++;
					}
					a = i;
					while (a < i + size_iterators && first != last)
					{
						_ptr[a] = *first;
						first++;
						a++;
					}
				}
			}
			

			

			//		_________________                 Erease                 _________________

			iterator erase (iterator position)
			{
				iterator	it = begin();
				iterator	ite = end();
				int			delete_pos = 0;
				int			a;

				while (it != position && it != ite)
				{
					delete_pos++;
					it++;
				}
				if (it != ite)
				{
					a = delete_pos;
					while (a + 1 != _size)
					{
						_ptr[a] = _ptr[a + 1];
						a++;
					}
					_size -= 1;
					return (it);
				}
				return (it);				
			}

			iterator erase (iterator first, iterator last)
			{
				iterator	it = begin();
				iterator	ite = end();
				int			n_first = 0;
				int			n_last = 0;
				int			a;
				int			b;

				while (it != first && it != ite)
				{
					n_first++;
					it++;
				}
				it = begin();
				while (it != last && it != ite)
				{
					n_last++;
					it++;
				}
				if (it != ite)
				{
					a = n_first;
					b = n_last;
					while (b != _size)
					{
						_ptr[a] = _ptr[b];
						b++;
						a++;
					}
					_size -= n_last - n_first;
					return (it);
				}
				return (it);				
			}
			
			void clear()
			{
				_size = 0;
			}
			
			void swap (vector& x)
			{
				value_type				*aux;
				size_type				aux_size;
				size_type				aux_capacity;

				aux_size = _size;
				aux_capacity = _capacity;
				
				if (_capacity != 0)
				{
					aux = _allocator.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						aux[i] = _ptr[i];


					_allocator.deallocate(_ptr, _capacity);
					_capacity = x.capacity();
					_size = x.size();
					_ptr = _allocator.allocate(x.capacity());

					for (size_type i = 0; i < x.size(); ++i)
						_ptr[i] = x[i];
					while (x.size() != 0)
						x.pop_back();
					for (size_type i = 0; i < aux_size; ++i)
						x.push_back(aux[i]);
					_allocator.deallocate(aux, aux_capacity);
				}
			}






			/*
			**		_______________________________ Allocator _______________________________
			*/

			allocator_type get_allocator() const
			{
				return (_allocator);
			}




			/*
			**		_______________________________ Operator= _______________________________
			*/

			ft::vector<T, Allocator>& operator=(const vector& x)
			{
				if (_capacity != 0)
				{
					_allocator.deallocate(_ptr, _capacity);
					_ptr = NULL;
				}
				_size = 0;
				_capacity = 0;
				reserve(x.capacity());
				for (size_t i = 0; i < x.size(); i++)
					_ptr[i] = x[i];
				_size = x.size();
				_capacity = x.capacity();
				return (*this);
			}


			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			vector (const vector& x)
			{
				_size = 0;
				_capacity = 0;
				reserve(x.capacity());
				for (size_t i = 0; i < x.size(); i++)
					_ptr[i] = x[i];
				_size = x.size();
				_capacity = x.capacity();
			}

			explicit vector (size_type n, const value_type& val = value_type(),
								const allocator_type& alloc = allocator_type())
			{
				_size = 0;
				_capacity = 0;
				_ptr = NULL;
				insert(begin(), n, val);
			}



































			//template <class InputIterator>
			//vector (InputIterator first, InputIterator last,
			//			const allocator_type& alloc = allocator_type())
			//{
			//	int			i = 0;
			//	iterator	it = first;

			//	while (it != last)
			//	{
			//		it++;
			//		i++;
			//	}
			//	if (it != last)
			//	{
			//		reserve(i);
			//		for (size_t j = 0; j < i; ++j)
			//		{
			//			std::cout << first[j] << std::endl;
			//			_ptr[j] = first[j];
			//		}
			//	}
			//	_size = i;
			//	_capacity = i;
			//}

			vector() 
			{
				_ptr = NULL;
				_size = 0;
				_capacity = 0;
			}

			~vector()
			{
				if (_capacity != 0)
					_allocator.deallocate(_ptr, _capacity);
			}
	};





	/*
	**		______________________________ Relational operators ______________________________
	*/

	template <class T, class Allocator>
	bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())	
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}


	template <class T, class Allocator>
	bool operator!= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (!(lhs == rhs));
	}


	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (true);
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())	
			return (true);
		return (false);
	}


	template <class T, class Allocator>
	bool operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (true);
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())	
			return (true);
		return (false);
	}


	template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
}

//void	ft_leaks()
//{
//	system("leaks ft_containers");
//}

#endif