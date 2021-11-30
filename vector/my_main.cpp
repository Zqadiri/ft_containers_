/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/30 22:03:17 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"

void foo(unsigned i) {
  std::cout << "unsigned " << i << "\n";
}

template <typename T>
void foo(const T& t) {
  std::cout << "template " << t << "\n";
}

int main() 
{
    
    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second(4,100);                       // four ints with value 100
    std::vector<int> third(second.begin(),second.end());  // iterating through second
    std::vector<int> fourth(third);                       // a copy of third
    
    std::cout << '\n';
    // int a[] = {1,2,3,4,5};
    ft::Vector<int> default_vec;
    ft::Vector<int> v2(second.begin(),second.end());
    ft::Vector<int> vec (4,100);                       
    std::cout << second.front() << std::endl;
    std::cout << vec.front() << std::endl;
    foo(48);
    // ft::Vector<int> vect(second);
    return(0);
}
