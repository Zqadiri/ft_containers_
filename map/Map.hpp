/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:50:41 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/16 15:27:26 by zqadiri          ###   ########.fr       */
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
		typedef     		Key                                     				key_type;
		typedef     		T                                       				mapped_type;
		typedef     		ft::pair<const key_type,mapped_type>    				value_type;
		typedef				Compare 												key_compare;
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
		typedef				Alloc													allocator_type;
		typedef	typename 	allocator_type::reference								reference;
		typedef typename 	allocator_type::const_reference 						const_reference;
		typedef typename 	allocator_type::pointer         						pointer;
		typedef typename 	allocator_type::const_pointer   						const_pointer;
		typedef typename 	allocator_type::size_type       						size_type;
		typedef 			ft::map_iterator<value_type , key_compare> 				iterator;
		// typedef 			ft::map_iterator<const value_type , key_compare> 		const_iterator;
		// typedef				reverse_iterator<iterator> 								reverse_iterator;
		// typedef				ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef	typename	std::ptrdiff_t											difference_type;
		typedef typename 	ft::avl_tree<value_type, key_compare>::node_type		node_type;
		
			//! ----------- Constructors & Destructor ------------ !//
		
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(){
			_comp = comp;
			_alloc = alloc;
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
			std::swap(*this, x);
			return (*this);
		}

		// !------- Member functions ----------!//

		/*
		 TODO: Clear the map
		 destroy all the map element 
		*/

		void clear(){
			iterator start = this->begin();
			iterator end = this->end();
			for (; start != end; start++)
				_tree.nodeAlloc.destroy(start.nodePtr);
			_tree.treeSize = 0;
		}

		size_type size() const{
			return (_tree.treeSize);			
		}

		iterator begin(){
			node_type *temp = _tree.beginTree(_tree.rootPtr);
			iterator it(_tree, temp);
			return (it);	
		}

      	iterator end(){
			node_type *temp = _tree.minValue(_tree.rootPtr);
			iterator it(_tree, temp);
			return (it);  
		}
		
		/*
		 TODO: Insert a single element
		 insert a single element in the avlTree
		 return false if the value already exists
		 and true if its not
		*/

		pair<iterator,bool> insert (const value_type& val){
			_tree.rootPtr = _tree.insert(_tree.rootPtr, val);
			iterator it(_tree, _tree.rootPtr);
			return (ft::make_pair(it, true));		
		}
	
		iterator insert (iterator position, const value_type& val){
			(void)position;
			_tree.rootPtr = _tree.insert(_tree.rootPtr, val);
			iterator it(_tree, _tree.rootPtr);
			return (ft::make_pair(it, true));
		}

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last);
			  
		private:
			typename ft::avl_tree<value_type, key_compare>	_tree;
			key_compare										_comp;
			allocator_type									_alloc;
	};
}

#endif


////////////////////TODO
//! T = pair<Key, mapped_value>
//? template <typename T> struct node;
//? template <typename T, typename Compare = std::less<typename T::first_type>,
//? typename Alloc = std::allocator <T> > class avl_tree;
//? template <typename Category, typename T, ....> class biterator
