/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/06 21:40:58 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"
#include <type_traits>
#include <iterator>

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
	// {
	// 	std::cout << "********STD********" << std::endl;
	// 	std::vector<int> first;                              
	// 	std::vector<int> second(4,100);                 
	// 	std::vector<int> third(second.begin(),second.end()); 
	// 	std::vector<int> fourth(third);                      
		
	// 	std::cout << '\n';
	// 	std::cout << "********FT********" << std::endl;
		// int a[] = {1,2,3,4,5};
	// 	ft::Vector<int> default_vec;
	// 	ft::Vector<int> vec (4,100);
              
	// 	ft::Vector<int> v3(second.begin(),second.end());
		// std::cout << second.front() << std::endl;
		// std::cout << vec.front() << std::endl;
	// 	// foo(48);
	// }
	
	// {
	// 	ft::Vector<int>v1(4,100);
	// 	ft::Vector<int>::iterator i1;
	// 	ft::Vector<int>::iterator i2;
	// 	i1 = v1.begin();
	// 	i2 = v1.end();
	// 	std::cout << "* "<< v1.size()  << std::endl;
	// 	std::cout << "* "<< v1.back() << std::endl;
	// 	std::cout << (i1 == i2) << std::endl;
	// 	std::cout << &i1 << std::endl;
	// 	std::cout << &i2 << std::endl;
	// 	if ( i1 == i2)
	// 		std::cout << "Yes\n";
			
	// 	std::cout << "----------------\n";
	// 	std::vector<int>v2(4,100);
	// 	std::vector<int>::iterator i7;
	// 	std::vector<int>::iterator i9;
	// 	i7 = v2.begin();
	// 	i9 = v2.end();
	// 	std::cout << "- "<< v2.size() << std::endl;
	// 	std::cout << "- "<< v2.back() << std::endl;
	// 	std::cout << (i7 == i9) << std::endl;
	// 	std::cout << &i7 << std::endl;
	// 	std::cout << &i9 << std::endl;
	// 	if ( i7 == i9)
	// 		std::cout << "Yes";

	// 	std::cout << "********Type traits ft********" << std::endl;
	// 	std::cout << ft::is_integral<A>::value << '\n';
	// 	std::cout << ft::is_integral<E>::value << '\n';
	// 	std::cout << ft::is_integral<float>::value << '\n';
	// 	std::cout << ft::is_integral<int>::value << '\n';
	// 	std::cout << ft::is_integral<const int>::value << '\n';
	// 	std::cout << ft::is_integral<bool>::value << '\n';
	// 	// std::cout << ft::is_integral>::value << '\n';
	// 	std::cout << "********Type traits********" << std::endl;
	// 	std::cout << std::is_integral<A>::value << '\n';
	// 	std::cout << std::is_integral<E>::value << '\n';
	// 	std::cout << std::is_integral<float>::value << '\n';
	// 	std::cout << std::is_integral<int>::value << '\n';
	// 	std::cout << std::is_integral<const int>::value << '\n';
	// 	std::cout << std::is_integral<bool>::value << '\n';
	// }
	{
		int myints[] = {16,2,77,29};
  		ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		std::vector<int> second ; 
		std::vector<int>::iterator i1;
		i1 = second.begin();
		second.insert(i1, 15);
		for (std::vector<int>::size_type i = 0; i < fifth.size(); i++) {
    		std::cout << i << ":";
    		std::cout << fifth.at(i) << ' ';
		}
		std::cout << std::endl;
		std::cout << "********ft********" << std::endl;
		ft::Vector<int> first(4,100);                              
		ft::Vector<int>::iterator i2;
		i2 = first.begin() + 2;
		first.insert(i2, 15);
		for (ft::Vector<int>::size_type i = 0; i < first.size(); i++) {
    		std::cout << i << ":";
    		std::cout << first.at(i) << ' ';
		}
		std::cout << std::endl;
    	return 0;
	}
}
