/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insights.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:07:10 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/06 16:10:41 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<type_traits>
#include <memory>
#include <vector>
template <class T, class Allocator = std::allocator<T> >
	class Vector
	{		
		public:
			//!-------------------- Member types ------------------------!//
			/*The first template parameter
			Type representing the type of data stored in a vector.*/
			typedef T																value_type; 
			/*The second template parameter*/
			typedef Allocator														allocator_type;
			/*Type that provides a reference to an element stored in a vector.*/
			template <class InputIterator>
			explicit Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				 typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				std::cout << "range constructor" <<std::endl;
			}
    };

int main()
{
		std::vector<int> second(4,100);                               
		Vector<int> v3(second.begin(),second.end());
}

//********************************************************************************
