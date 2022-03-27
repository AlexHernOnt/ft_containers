/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/03/27 18:34:08 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include <iostream>

namespace	ft
{
	template <typename T>
	class vector
	{
		private:
			/* data */
		public:
			vector(const T &ref);
			vector();
			~vector();
	};
	
	template<typename T>
	vector<T>::vector(const T &ref)
	{
		
	}
	
	template<typename T>
	vector<T>::vector() 
	{
	}
	
	template<typename T>
	vector<T>::~vector()
	{

	}
}

#endif