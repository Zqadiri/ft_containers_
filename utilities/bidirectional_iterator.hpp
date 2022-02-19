/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/19 19:01:53 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include <functional>
#include "../map/avl_tree.hpp"
#include <memory>


namespace ft
{
	template <typename T, typename Compare >
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> // ? compare
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

		map_iterator( const tree &rhs, node_type *rootPtr): root(), nodePtr(), _tree(){
			this->_tree = rhs;
			nodePtr = rootPtr;
			root = _tree.rootPtr;
        }

		map_iterator(const map_iterator &mi): root(), nodePtr(), _tree(){
			*this = mi;
		}

		operator const_iterator(){
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

		~map_iterator(){}

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

		map_iterator& operator++() //! infinity loop
		{
			node_type *temp;
			if (nodePtr == nullptr)
			{
				nodePtr = _tree.rootPtr;
				if (nodePtr == nullptr) //! empty tree
					throw std::underflow_error("map : "); //! change it [Occurs when the result is not zero, but is too small to be represented]
				while (nodePtr->left != nullptr){
					nodePtr = nodePtr->left; //* move to the smallest value in the tree
				}
			}
			else if (nodePtr->right != nullptr)
			{
				nodePtr = nodePtr->right; //* successor is the farthest left node of right subtree
				while (nodePtr->left != nullptr){
					nodePtr = nodePtr->left;
				}
			}
			else
			{
				temp = nodePtr->rootPtr;
				while (temp != nullptr && nodePtr == temp->right){
					nodePtr = temp;
					temp = temp->rootPtr;
				}
				nodePtr = temp;
			}
			return *this;
		}
		
		map_iterator operator++ (int){
			map_iterator copy = *this;
			operator++();
			return copy;
		}
	
		// * decrement. move backward to largest value < current value
		map_iterator&  operator-- () //! loop infinie
		{
			node_type *temp;
			if (nodePtr == nullptr)
			{
				nodePtr = _tree.rootPtr;
				if (nodePtr == nullptr)
					throw std::underflow_error("map : ");
				while (nodePtr->right != nullptr)
					nodePtr = nodePtr->right;
			}
			else if (nodePtr->left != nullptr)
			{
				nodePtr = nodePtr->left;
				while (nodePtr->right != nullptr)
					nodePtr = nodePtr->right;
			}
			else
			{
				temp = nodePtr->rootPtr;
				while (temp != nullptr && nodePtr == temp->left)
				{
					nodePtr = temp;
					temp = temp->rootPtr;
				}
				nodePtr = temp;
			}
			return (*this);
		}
	
		map_iterator  operator-- (int){
			map_iterator copy = *this;
			operator--();
			return (copy);
		}

		public: //!change it to private
			node_type		*root;
			node_type		*nodePtr; //! current location in the tree 
			tree			_tree;
	};
}

#endif