/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:25:09 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/06 14:37:23 by zqadiri          ###   ########.fr       */
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


	

    // template <typename T>
    //     struct is_input_iterator_tagged{const static bool value = false; };

    // /* Check is_input_iterator_tagged from ft::random_access_iterator_tag */
    // template <>
    //     struct is_input_iterator_tagged<ft::random_access_iterator_tag>{const static bool value = true;};

    // /* Check is_input_iterator_tagged from ft::bidirectional_iterator_tag */
    // template <>
    //     struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>{const static bool value = true; };

    // /* Check is_input_iterator_tagged from ft::forward_iterator_tag */
    // template <>
    //     struct is_input_iterator_tagged<ft::forward_iterator_tag>{const static bool value = true; };

    // /* Check is_input_iterator_tagged from ft::input_iterator_tag */
    // template <>
    //     struct is_input_iterator_tagged<ft::input_iterator_tag>{ const static bool value = true;};
}


#endif
