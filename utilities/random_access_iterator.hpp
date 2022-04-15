/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:05:49 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/14 23:25:19 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:

		//?------------Member types--------------?//

		typedef T																				iterator_type;
		// Category of the iterator
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		// Type of elements pointed
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		// Type to represent the difference between two iterators
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		// Type to represent a pointer to an element pointed
		typedef T*																				pointer;
		// Type to represent a reference to an element pointed
		typedef T&																				reference;

		//?------------- Constructors --------------?//

		random_access_iterator():_it(NULL){};
		
		random_access_iterator(const random_access_iterator &it){
			this->_it = it._it;
		}

		random_access_iterator(pointer p){
			this->_it = p;
		}

		random_access_iterator& operator=(const random_access_iterator& op) {
			_it = op._it;
			return (*this);}
		
		//?------------- Destructors --------------?//
		
		~random_access_iterator(){};

		//? ---------- Conversion Operator --------?//

		operator random_access_iterator<const T>() const {
			return random_access_iterator<const T>(this->_it);
		}

		//?----------- Public Member Function and operators --------?//

		pointer base() const{
			return(this->_it);
		}
			
		reference operator*(void) const {
			return (*_it);
		}

		pointer operator->(void) { 
			return &(this->operator*());
		}

		random_access_iterator operator+ (difference_type n) const{
			return (random_access_iterator(_it + n));
		}
			
		random_access_iterator operator- (difference_type n) const {
			return (random_access_iterator(_it - n));
		}

		random_access_iterator& operator++(){
			_it++;
			return (*this);
		}

		random_access_iterator operator++(int) {
  			random_access_iterator temp = *this;
  			operator++();
  			return temp;
		}

		random_access_iterator& operator+=(difference_type n) {
			_it += n;
			return (*this);
		}

		random_access_iterator& operator--(){
			_it--;
			return (*this);
		}

		random_access_iterator operator--(int) {
  			random_access_iterator temp = *this;
  			operator--();
  			return temp;
		}
		
		random_access_iterator& operator-= (difference_type n) {
			_it -= n;
			return (*this); }
		
		reference operator[](difference_type n) { 
			return (*(operator+(n)));
		}
	
		difference_type operator- (const random_access_iterator& rit){ 
			return (this->_it - rit._it);
		}

		private:
			pointer _it;
	};	

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator==(const ft::random_access_iterator<U> &lhs,
					const ft::random_access_iterator<T> &rhs){
		return (lhs.base() == rhs.base());
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator!=(const ft::random_access_iterator<U> &lhs,
					const ft::random_access_iterator<T> &rhs){
			return (!(lhs.base() == rhs.base()));
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator<(const ft::random_access_iterator<U> &lhs,
					const ft::random_access_iterator<T> &rhs){
			return (lhs.base() < rhs.base());
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator<=(const ft::random_access_iterator<U> &lhs,
					const ft::random_access_iterator<T> &rhs){
			return (lhs.base() <= rhs.base());
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator>(const ft::random_access_iterator<U> &lhs,
					const ft::random_access_iterator<T> &rhs){
			return (lhs.base() > rhs.base());
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator>=(const ft::random_access_iterator<U> &lhs,
					const ft::random_access_iterator<T> &rhs){
			return (lhs.base() >= rhs.base());
	}

	template<typename T, typename U>
	typename ft::random_access_iterator<T>::difference_type operator- (const random_access_iterator<U>& it, 
					const random_access_iterator<U>& rit){ 
		return (it.base() - rit.base());
	}

	template <typename T>
	ft::random_access_iterator<T> operator+ (typename ft::random_access_iterator<T>::difference_type n,
					const random_access_iterator<T>& rit){ 
		return ft::random_access_iterator<T>(rit.base() + n);
	}

}

#endif
