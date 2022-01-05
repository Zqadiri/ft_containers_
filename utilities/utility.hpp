
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


	template <class T1, class T2> struct pair
	{
		
	};
}

#endif
