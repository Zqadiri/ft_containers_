
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:25:09 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/15 23:44:42 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <type_traits>
#include "iterator.hpp"
#include <utility>
#include <algorithm>
namespace ft
{
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T>
	{typedef T type;};

	/*
	** Trait class that identifies whether T is an integral type.
	*/
	
	/*
	** bool
	** char
	** char16_t
	** char32_t
	** wchar_t
	** signed char
	** short int
	** int
	** long int
	** long long int
	** unsigned char
	** unsigned short int
	** unsigned int
	** unsigned long int
	** unsigned long long int
	*/

	template<typename T>
	struct is_integral{static const bool value = false;};

	template<>
	struct is_integral<bool> {static const bool value = true;};
	template<>
	struct is_integral<char> {static const bool value = true;};
	template<>
	struct is_integral<char16_t> {static const bool value = true;};
	template<>
	struct is_integral<char32_t> {static const bool value = true;};
	template<>
	struct is_integral<wchar_t> {static const bool value = true;};
	template<>
	struct is_integral<signed char> {static const bool value = true;};
	template<>
	struct is_integral<int> {static const bool value = true;};
	template<>
	struct is_integral<long int> {static const bool value = true;};
	template<>
	struct is_integral<long long int> {static const bool value = true;};
	template<>
	struct is_integral<unsigned char> {static const bool value = true;};
	template<>
	struct is_integral<unsigned short int> {static const bool value = true;};
	template<>
	struct is_integral<unsigned int> {static const bool value = true;};
	template<>
	struct is_integral<unsigned long int> {static const bool value = true;};
	template<>
	struct is_integral<unsigned long long int> {static const bool value = true;};

	//!------------------- Lexicographical_compare --------------------!//

	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
		  if (first2==last2 || *first2<*first1) return false;
		  else if (*first1<*first2) return true;
		  ++first1; ++first2;
		}
		return (first2!=last2);
	};

	template <class InputIterator1, class InputIterator2, class Compare>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp);

	//!---------------------------- Equal ------------------------------!//

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) 
		{
			if (!(*first1 == *first2))  
				return false;
			++first1; ++first2;
		}
		return true;
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  	bool equal (InputIterator1 first1, InputIterator1 last1,
			  InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1) 
		{
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;	  
	};


	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		//*A member variable is the variable you declare in a class definiton
		
		T1		_first;
		T2		_second;

			//?------- Member Functions ---------?//

		pair():_first(), _second(){};

		template<class U, class V>
		pair (const pair<U,V>& pr): _first(pr._first), _second(pr._second){
		}

		pair (const first_type& first, const second_type& second){
			this->_first = first;
			this->_second = second;
		}

		pair& operator= (const pair& pr){
			this->_first = pr._first;
			this->_second = pr._second;
			return (*this);
		}

	};

	//?------- Non-member function overloads  ---------?//

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return ((lhs._first == rhs._first) && (lhs._second && rhs._second));
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (!(lhs == rhs));
	}

	template <typename T1, typename T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){   
		return (lhs.first < rhs.first || (!(rhs.first<lhs.first) && (lhs.second<rhs.second)));
	}

	template <typename T1, typename T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){   
		return !(rhs<lhs);
	}

	template <typename T1, typename T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){   
		return (rhs<lhs);   
	}

	template <typename T1, typename T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){   
		return !(lhs<rhs);
	}

	// * make pair

	template <typename T1, typename T2>
	pair<T1,T2> make_pair (T1 x, T2 y){
		return (pair<T1,T2>(x,y));		  
	}

	template <typename Key, typename T, typename pairAllocator = std::allocator<ft::pair<const Key, T> > >
	struct BstNode
	{
		private:
			pairAllocator pairAlloc;
		public:
			ft::pair<const Key, T> data; //? value type 
			BstNode *right;
			BstNode *left;
			BstNode *rootPtr; //? store the address of the root

		BstNode(): data(){};
		~BstNode(){};
		
		BstNode(const pair <const Key, T> p){
			puts("cons");
			pairAlloc.construct(&data, p);
		}

		BstNode(const Key K, const T &val, BstNode *rt, BstNode *lt, BstNode *p){
			this->data._first = K;
			this->data._second = val;
			this->right = nullptr;
			this->left = nullptr;
			this->rootPtr = nullptr;
		}

		BstNode(const BstNode &no){
			*this = no;
		}

		BstNode &operator=(const BstNode &no){
			if (*this == no)
				return(*this);
			this->data._first = no.data._first;
			this->data._second = no.data._second;
			this->right = no.right;
			this->left = no.left;
			this->rootPtr = no.rootPtr;
			return (*this);
		}

		bool operator==(const BstNode &no){
			return ( (this->data == no.data) ? true : false );
		}
	};
}

#endif
