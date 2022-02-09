/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/09 16:04:43 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"


namespace ft
{
	template <typename T, typename Compare>
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> // ? compare
	{
		public:
			typedef	Compare		compare;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;

		// //! ---- Contructors ------!//
		~map_iterator(){};
		
		map_iterator(const compare &com = compare()){
			Node = lastNode = nullptr;
			comp = com;
		}
		
		map_iterator(const map_iterator &mi): Node(nullptr), lastNode(nullptr), comp(){
			*this = mi;
		}
		
		map_iterator &operator=(const map_iterator &mi)
		{
			if (*this == mi)
				return (*this);
			this->Node = mi.Node;
			this->lastNode = mi.lastNode;
			this->comp = mi.comp;
			return (*this);
		}
		
		/* 
		 TODO: equality/inequality operators
		 when both iterator 
		 values iterate over the same underlying sequence
		*/
	
		bool operator== (const map_iterator& rhs) const{
			return (this->Node == rhs.Node);
		}
	
		bool operator!= (const map_iterator& rhs) const{
			return (!(this == rhs));
		}
	
		/*
		 TODO: dereference operator.
		 return a reference to the value pointed to by nodePtr
		*/

		reference operator*() const{ 
			return (this->_node->value); 
		}

		pointer operator->() const{
			return (&this->_node->value);
		}

		// * increment. move forward to next larger value
		map_iterator& operator++ ();
		map_iterator operator++ (int);
	
		// * decrement. move backward to largest value < current value
		map_iterator  operator-- ();
	
		map_iterator  operator-- (int);
		
		

		private:
			T		*Node;
			T		*lastNode;
			compare	comp;
	};
}

#endif