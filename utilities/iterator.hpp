/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:10:22 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/15 00:41:34 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP_
#define ITERATOR_HPP_

#include <stddef.h>
#include "iterator.hpp"
#include "iterator_traits.hpp"


namespace ft
{
	//!----------------Category tags--------------!//
	/*
		This is a base class template that can be used 
		to derive iterator classes from it. 
		It is not an iterator class and does not provide any
		of the functionality an iterator is expected to have.
	*/

	//!---------------- Iterator Base Class -----------------!//
	
	template <typename Category, typename T, typename Distance = ptrdiff_t,
			typename Pointer = T*, typename Reference = T&>
	class iterator 
	{
		public :
			typedef T						value_type;
			typedef Distance				difference_type;
			typedef Pointer					pointer;
			typedef Reference				reference;
			typedef Category 				iterator_category;
	};

	//!--------------- Predefined iterators ----------------!//
	
			/*----------- REVERSE ITERATOR -----------*/
	
	template <class Iterator> 
	class reverse_iterator
	{
			//?------------Member types--------------?//

		public :

			// Iterator's type
			typedef Iterator													iterator_type;
			// Preserves Iterator's category
			typedef	typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			// Preserves Iterator's value type
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			// Preserves Iterator's difference type
			typedef	typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			// Preserves Iterator's pointer type
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			// Preserves Iterator's reference type
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			
			//?------------- Constructors --------------?//

		/*
		** Construct a reverse iterator object from
		** an original iteretor.
		** The behavior of the constructed object
		** replicate the orignal, but he iterates
		** in the reverse order.
		*/

		reverse_iterator() : _it(Iterator()){}
 
		explicit reverse_iterator (const iterator_type  &it): _it(it){
		}
		
		template <typename Iter>
		 reverse_iterator (const reverse_iterator<Iter>& rev_it){
			*this = rev_it;
 		}

			//?----------- Public Member Function --------?//

		/*
		TODO: Return base iterator
		** base() converts a reverse iterator into the corresponding forward iterator
		*/

		iterator_type base() const{
			return(_it);
		}

		/*
		TODO: Assign iterator
		** Assigns rev_it's base iterator to the object's base iterator, replacing its current value.
		*/
		
		template <class Iter>
  	   	reverse_iterator& operator= (const reverse_iterator<Iter>& rev_it)
		{
			_it = rev_it.base();
			return (*this);	  
		}
		
		/*
		TODO: Dereference iterator
		** Returns a reference to the element pointed to by the iterator.
		** Internally, the function decreases a
		** copy of its base iterator and returns 
		** the result of dereferencing it.
		*/

		reference operator*() const{
			iterator_type tmp = _it;
			 (--tmp);
			return (*tmp);
		}

		/*
		TODO: Addition operator
		** Returns a reverse iterator pointing to the element located n positions away.
		** Adds an offset to an iterator and returns 
		** the NEW reverse_iterator addressing the inserted element
		** at the new offset position.
		*/
		
		reverse_iterator operator+ (difference_type n) const{
			return (reverse_iterator(_it - n));
		}
		
		/*
		TODO: Increment operator
		** Advances the reverse_iterator by one position.
		*/

		reverse_iterator& operator++(){
			--(_it);
			return (*this);
		}

		reverse_iterator operator++(int){
			reverse_iterator temp = *this;
			++(*this);
			return (temp);
		}
	
		/*
		TODO: Advance iterator
		** Advances the reverse_iterator by n element positions
		** Internally, the function decreases by n the base iterator kept by the object	
		*/

		reverse_iterator& operator+= (difference_type n){
			_it -= n;
			return (*this);
		}
		
		/*
		TODO: Subtraction operator
		** Returns a reverse iterator pointing to the element located n positions before
		** Internally, the function applies the binary operator+ on the base iterator and 
		** returns a reverse iterator constructed with the resulting iterator value.
		*/
	
		reverse_iterator operator- (difference_type n) const{
			return(reverse_iterator(_it + n));
		}
		
		/*
		TODO: Decrement operator
		** Decreases the reverse_iterator by one position.
		*/

		reverse_iterator& operator--(){
			++(_it);
			return (*this);
		}

		reverse_iterator operator--(int) {
  			reverse_iterator temp = *this;
  			--(*this);
  			return temp;
		}
	
		/*
		TODO: Retrocede iterator
		** Descreases the reverse_iterator by n element positions.
		** Internally, the function increases by n the base iterator kept by the object 
		*/

		reverse_iterator& operator-= (difference_type n){
			_it += n;
			return (*this);
		}
		
		/*
		TODO: Dereference iterator
		** Returns a pointer to the element pointed to by the iterator
		** The function calls operator* and returns its address
		*/

		pointer operator->() const {
		  return &(operator*());
		}

		/*
		TODO: Dereference iterator with offset
		** Internally, the function accesses the proper element 
		** of its base iterator, returning the same as: base()[-n-1]
		*/
	
		reference operator[] (difference_type n) const{
			return (this->base()[-n - 1]);		
		}
		
		private:
			Iterator		_it;
	};

		//?----------Non-member function overloads-------?//
	
	//*-------relational operators-----------*//

	/*
	TODO: Relational operators for reverse_iterator
	** Performs the appropriate comparison operation between 
	** the reverse_iterator objects lhs and rhs.
	** Internally, the function compares directly the base iterators
	** using the reflexively equivalent relational operator
	** Inverse comparisons are applied 
	** in order to take into account that the iterator order is reversed.
	*/

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() == rhs.base());
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() != rhs.base());			   
	}


	template< class Iterator1, class Iterator2 >
	bool operator< ( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() > rhs.base());			   
	}

	template<class Iterator1, class Iterator2>
	bool operator<=( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() >= rhs.base());			   
	}

	template<class Iterator1, class Iterator2>
	bool operator>( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() < rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator>=( const reverse_iterator<Iterator1>& lhs,
                 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() <= rhs.base());		   
	}

	/*
	TODO: Subtraction operator
	** Returns the distance between lhs and rhs.
	** The function returns the same as subtracting lhs's base iterator from rhs's base iterator.
	*/

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return (rhs.base() - lhs.base());
	}

	/*
	TODO: Addition operator
	** Returns a reverse iterator pointing to the element located n positions
	** away from the element pointed to by rev_it.
	*/

	template <class Iterator>
		reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) { 
		return (rev_it + n);
	}		
}

#endif
