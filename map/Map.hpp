/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:50:41 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/09 20:41:37 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../utilities/bidirectional_iterator.hpp"
#include "../utilities/utility.hpp"
#include "avl_tree.hpp"
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

	public:
		typedef     		Key                                     															key_type;
		typedef     		T                                       															mapped_type;
		typedef     		ft::pair<const key_type,mapped_type>    															value_type;
		typedef				Compare 																							key_compare;
		typedef	class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map; //?
			protected:
				Compare comp;
  				value_compare (Compare c) : comp(c) {}
			public:
				bool operator() (const value_type& x, const value_type& y) const{
    				return comp(x.first, y.first);
  				}
		} value_compare;
		typedef				Alloc																								allocator_type;
		typedef	typename 	allocator_type::reference																			reference;
		typedef typename 	allocator_type::const_reference 																	const_reference;
		typedef typename 	allocator_type::pointer         																	pointer;
		typedef typename 	allocator_type::const_pointer   																	const_pointer;
		typedef typename 	allocator_type::size_type       																	size_type;
		typedef 			ft::map_iterator<pair<const key_type,mapped_type>, avl_tree<key_type, mapped_type>, Compare> 		iterator;
		typedef 			ft::map_iterator<const pair<const key_type,mapped_type>, avl_tree<key_type, mapped_type>, Compare>	const_iterator;
		// typedef				reverse_iterator<iterator> 					reverse_iterator;
		// typedef				ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
		typedef	typename	std::ptrdiff_t								difference_type;
		
			//! ----------- Constructors & Destructor ------------ !//
		
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()){
			_comp = comp;
			_alloc = alloc;
			// _tree = nullptr;	
		}		

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());

		map (const map& x){
			*this = x;
		}

		map& operator=(const map& x){
			if (*this == x)
				return (*this);
			// std::swap(*this, x);
			return (*this);
		}

		// !------- Member functions ----------!//
		iterator begin(){
			_tree.minValue(_tree._parent);
			return (iterator());	
		}

		const_iterator begin() const;
		
		pair<iterator,bool> insert (const value_type& val);
	
		iterator insert (iterator position, const value_type& val);

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last);

		private:
			avl_tree<key_type, mapped_type>	_tree;
			key_compare						_comp;
			allocator_type					_alloc;
	};
			  
}

#endif