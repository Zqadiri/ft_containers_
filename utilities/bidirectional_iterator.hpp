/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/15 14:28:45 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include <functional>
#include <memory>


namespace ft
{
	template <typename T, typename Compare >
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> // ? compare
	{
		public:
			typedef	Compare		compare;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::avl_tree<T, Compare>												tree;
			typedef typename ft::BstNode<T>     													node_type;

		//! ---- Contructors ------!//
		
		map_iterator(): root(), nodePtr(), _tree() {};

		map_iterator( const tree &rhs, node_type *rootPtr): root(), nodePtr(), _tree(){
			this->_tree = rhs;
			root = _tree.rootPtr;
			
			// std::cout << "In the constructor : " << root->data._first << std::endl;
        }

		map_iterator(const map_iterator &mi): root(), nodePtr(), _tree(){
			*this = mi;
		}

		map_iterator &operator=(const map_iterator &mi)
		{
			if (*this == mi)
				return (*this);
			this->_tree = mi._tree;
			this->root = mi.root;
			return (*this);
		}

		~map_iterator(){}

		/* 
		 TODO: equality/inequality operators
		 when both iterator 
		 values iterate over the same underlying sequence
		*/
	
		bool operator== (const map_iterator& rhs) const{
			return (this->root == rhs.root);
		}
	
		bool operator!= (const map_iterator& rhs) const{
			return (this->root != rhs.root);
		}
	
		/*
		 TODO: dereference operator
		 return a reference to the value pointed to by nodePtr
		*/

		reference operator*() const{
			return (root->data);
		}
		
		pointer operator->() const{
			// std::cout << "In the operator-> : " << root->data._first << std::endl;
			return (&this->root->data);
		}

		/*
		 TODO: increment operator 
		 move forward to next larger value
		*/

		map_iterator& operator++ ()
		{
			node_type *temp;
			if (nodePtr == nullptr)
			{
				nodePtr = _tree.rootPtr;
				if (nodePtr == nullptr) //! empty tree
					throw underflow_error("map : "); //! change it [ Occurs when the result is not zero, but is too small to be represented ]
				while (nodePtr->left != nullptr)
					nodePtr = nodePtr->left; //* move to the smallest value in the tree
			}
			else
			{
				if (nodePtr != nullptr)
				{
					nodePtr = nodePtr->right; //* successor is the farthest left node of right subtree
					while (nodePtr->left != nullptr)
						nodePtr = nodePtr->left;
				}
				else
				{
					temp = nodePtr->rootPtr;
					while (temp != nullptr && nodePtr == temp->right)
					{
						nodePtr = temp;
						temp = temp->rootPtr;
					}
					nodePtr = temp;
					
				}
			}
			return *this;
		}
		
		map_iterator operator++ (int){
			map_iterator temp = *this;
			operator++();
			return temp;
		}
	
		// * decrement. move backward to largest value < current value
		map_iterator  operator-- ();
	
		map_iterator  operator-- (int);
		
		

		public: //!change it to private
			node_type		*root;
			node_type		*nodePtr; //! current location in the tree 
			tree			_tree;
	};
}

#endif