/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/24 22:10:12 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include <functional>
#include "./avl_tree.hpp"
#include <memory>


namespace ft
{
	template <typename T, typename Compare = std::less<typename T::first_type> >
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		typedef 			map_iterator< const T, Compare >	const_iterator;
		public:
			typedef	Compare		compare;
			typedef	typename iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef	typename iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef	typename iterator<std::bidirectional_iterator_tag, T>::reference			reference;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::avl_tree<T, Compare>											tree;
			typedef typename ft::BstNode<T>     												node_type;

		//! ---- Contructors ------!//
		
		map_iterator(): root(), nodePtr(), _tree() {};

		map_iterator( const tree &rhs, node_type *rootPtr): root(), nodePtr(){
			_tree = rhs;
			nodePtr = rootPtr;
			root = _tree.rootPtr;
		}

		map_iterator(node_type *rootPtr): root(), nodePtr(){
			nodePtr = rootPtr;
			root = _tree.rootPtr;
		}

		map_iterator(const map_iterator &mi): root(), nodePtr(), _tree(){
			*this = mi;
		}

		operator const_iterator()const {
			return const_iterator(this->current_tree, this->_node);
		}

		map_iterator &operator=(const map_iterator &mi)
		{
			if (*this == mi)
				return (*this);
			this->_tree = mi._tree;
			this->root = mi.root;
			this->nodePtr = mi.nodePtr;
			return (*this);
		}

		~map_iterator(){
		}

		/* 
		 TODO: equality/inequality operators
		 when both iterator 
		 values iterate over the same underlying sequence
		*/
	
		bool operator== (const map_iterator& rhs) const{
			return (root == rhs.root && nodePtr == rhs.nodePtr);
		}
	
		bool operator!= (const map_iterator& rhs) const{
			return (_tree != rhs._tree || nodePtr != rhs.nodePtr);
		}
	
		/*
		 TODO: dereference operator
		 return a reference to the value pointed to by nodePtr
		*/

		reference operator*() const{
			return (nodePtr->data);
		}
		
		pointer operator->() const{
			return (&this->nodePtr->data);
		}

		/*
		 TODO: increment operator 
		 move forward to next larger value
		*/

		map_iterator& operator++(){
			nodePtr = _tree.nextNode(nodePtr);
			return *this;
		}
		
		map_iterator operator++ (int){
			map_iterator copy = *this;
			operator++();
			return copy;
		}
	
		map_iterator&  operator-- (){
			nodePtr = _tree.preNode(nodePtr);
			return (*this);
		}
	
		map_iterator  operator-- (int){
			map_iterator copy = *this;
			operator--();
			return (copy);
		}

		private: //!change it to private
			node_type		*root;
			node_type		*nodePtr;
			tree			_tree;
	};
}

#endif