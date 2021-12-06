/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:56:51 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/05 19:14:28 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>
#include <vector>

/*
template<typename T, typename = void>
struct is_iterator
{
   static const bool value = false;
};

template<typename T>
struct is_iterator<T, typename std::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type>
{
   static const bool value = true;
};
*/

template<typename T, typename = void>
struct is_iterator{
   static const bool value = false;
};

template<typename T>
struct is_iterator<T, typename std::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type>
{
   static const bool value = true;
};

int main()
{
   static_assert(!is_iterator<int>::value, "ass");
   static_assert(is_iterator<int*>::value, "ass");
   static_assert(is_iterator<std::vector<int>::iterator>::value, "ass");
}