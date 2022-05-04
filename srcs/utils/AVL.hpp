/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:24:15 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/04 20:00:57 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AVL_HPP__
# define __AVL_HPP__
# include  <iostream>

template <class T>
class node
{
	public:
		T			data;
		
		node*		left;
		node* 		right;
	
		node (int val)
		{
			data = val;

			// Left and right child for node
			// will be initialized to null
			left = NULL;
			right = NULL;
	  }
};

#endif