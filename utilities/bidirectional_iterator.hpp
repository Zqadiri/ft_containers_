/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/13 18:12:04 by zqadiri          ###   ########.fr       */
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
	template <typename Key, typename T, typename Tree, typename Compare = std::less<T> >
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> // ? compare
	{
		public:
			typedef	Compare		compare;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type						value_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category				iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type					difference_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::reference						reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer							pointer;
			typedef typename ft::avl_tree<Key,T, Compare>::node_type											node;
		
		// //! ---- Contructors ------!//
		map_iterator(): root(), lastNode(), tree() {};
		
		map_iterator(const compare &com = compare()){
			root = lastNode = nullptr;
			comp = com;
		}

		map_iterator( const Tree & rhs, const node &rootPtr): root(), lastNode(), tree(){
			this->tree = rhs.tree;
			root = rootPtr;
        }

		map_iterator(const map_iterator &mi): root(), lastNode(), tree(){
			*this = mi;
		}

		map_iterator &operator=(const map_iterator &mi)
		{
			if (*this == mi)
				return (*this);
			// std::swap (*this, mi);
			return (*this);
		}

		// operator map_iterator<const T, compare>() const {
		// 	return map_iterator<const T, compare>(this->Node); }

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
			return (!(this == rhs));
		}
	
		/*
		 TODO: dereference operator
		 return a reference to the value pointed to by nodePtr
		*/

		reference operator*() const{ 
			return (this->root->value); 
		}

		pointer operator->() const{
			return (&this->root->value);
		}

		/*
		 TODO: increment operator 
		 move forward to next larger value
		*/

		map_iterator& operator++ (){
			if (root == nullptr)
			{
				root = tree->root;
			}
		}
		
		map_iterator operator++ (int);
	
		// * decrement. move backward to largest value < current value
		map_iterator  operator-- ();
	
		map_iterator  operator-- (int);
		
		

		private:
			node		*root;
			node		*lastNode;
			Tree		tree;
			compare		comp;

	};
}

#endif