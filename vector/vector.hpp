/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:50 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/08 12:42:47 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERCTOR_HPP_
#define VERCTOR_HPP_

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

/*
	Namespace refers to various blocks that can be created in a 
	program to group all similar objects, and you can 
	refer to all variables, functions, or classes within a block.
*/

namespace   ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		private:
			typedef T value_type; /*The first template parameter*/
			typedef Allocator	allocator_type; /*The second template parameter*/
			typedef	allocator_type::reference reference; /*value_type&*/
			typedef allocator_type::const_reference const_reference; /*const value_type& */
			typedef allocator_type::pointer pointer; /*value_type* */
			typedef allocator_type::const_pointer const_pointer; /*const value_type* */
			
		public:
			// public member functions
			vector(/* args */);
			~vector();
	};
}

#endif
