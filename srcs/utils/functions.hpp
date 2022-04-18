/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:28:21 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/13 20:12:43 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FUNCTIONS_HPP__
# define __FUNCTIONS_HPP__

namespace ft
{
	template <bool, class IsTrue = void>
	struct enable_if;

	template <class IsTrue>
	struct enable_if < true, IsTrue >
	{
		typedef IsTrue type;
	};
}
#endif


	// template <bool B, class T = void>
	// struct Aenable_if
	// {};
	
	// template <class T>
	// struct Aenable_if <true, T>
	// {
	//     typedef T type;
	// };
	