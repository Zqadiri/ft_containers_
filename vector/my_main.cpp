/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/04 16:13:44 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"
#include <type_traits>

class A {};
 
enum E : int {};

void foo(unsigned i) {
  std::cout << "unsigned " << i << "\n";
}

template <typename T>
void foo(const T& t) {
  std::cout << "template " << t << "\n";
}

int main() 
{
	{
		std::cout << "********STD********" << std::endl;
		std::vector<int> first;                              
		std::vector<int> second(4,100);                      
		std::vector<int> third(second.begin(),second.end()); 
		std::vector<int> fourth(third);                      
		
		std::cout << '\n';
		std::cout << "********FT********" << std::endl;
		// int a[] = {1,2,3,4,5};
		ft::Vector<int> default_vec;
		ft::Vector<int> v2(second.begin(),second.end());
		ft::Vector<int> vec (4,100);                       
		std::cout << second.front() << std::endl;
		std::cout << vec.front() << std::endl;
		foo(48);
	}
	{
		std::cout << "********Type traits********" << std::endl;
		std::cout << ft::is_integral<A>::value << '\n';
		std::cout << ft::is_integral<E>::value << '\n';
		std::cout << ft::is_integral<float>::value << '\n';
		std::cout << ft::is_integral<int>::value << '\n';
		std::cout << ft::is_integral<const int>::value << '\n';
		std::cout << ft::is_integral<bool>::value << '\n';
		std::cout << "********Type traits********" << std::endl;
		std::cout << std::is_integral<A>::value << '\n';
		std::cout << std::is_integral<E>::value << '\n';
		std::cout << std::is_integral<float>::value << '\n';
		std::cout << std::is_integral<int>::value << '\n';
		std::cout << std::is_integral<const int>::value << '\n';
		std::cout << std::is_integral<bool>::value << '\n';
	}
}
