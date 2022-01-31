/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:50:41 by zqadiri           #+#    #+#             */
/*   Updated: 2022/01/06 11:36:26 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../utilities/bidirectional_iterator.hpp"
#include "../utilities/utility.hpp"
#include <map>
#include <functional>
#include <memory>

namespace ft
{
	template < class Key,                                      		 // map::key_type
		   class T,													 // map::mapped_type
		   class Compare = std::less<Key>,                           // map::key_compare
		   class Alloc = std::allocator<ft::pair<const Key,T> >      // map::allocator_type
		   > class map
	{
		typedef     		Key                                     	key_type;
		typedef     		T                                       	mapped_type;
		typedef     		ft::pair<const key_type,mapped_type>    	value_type;
		typedef				Compare 									key_compare;
		typedef				Alloc										allocator_type;
		typedef	typename 	allocator_type::reference					reference;
		typedef typename 	allocator_type::const_reference 			const_reference;
		typedef typename 	allocator_type::pointer         			pointer;
		typedef typename 	allocator_type::const_pointer   			const_pointer;
		typedef 			bidirectional_iterator<T>					iterator;
		typedef 			bidirectional_iterator<const T>				const_iterator;
		typedef				reverse_iterator<iterator> 					reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
		typedef	typename	iterator_traits<iterator>::difference_type	difference_type;
		typedef typename 	allocator_type::size_type       			size_type;
		
			//! ----------- Constructors & Destructor ------------ !//
		
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());		

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());

		map (const map& x);

		private:
		
		
	};
			  
}

#endif