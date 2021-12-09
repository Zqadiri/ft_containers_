/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/09 20:17:41 by zqadiri          ###   ########.fr       */
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
	// {
	// 	int myints[] = {16,2,77,29};
  	// 	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	// 	std::vector<int>::iterator i1;
	// 	std::cout << "size :" << fifth.size() << std::endl;
	// 	i1 = fifth.begin() + 2;
	// 	fifth.insert(i1, 15);
	// 	std::cout << "size :" << fifth.size() << std::endl;
	// 	for (std::vector<int>::size_type i = 0; i < fifth.size(); i++) {
    // 		std::cout << i << ":";
    // 		std::cout << fifth.at(i) << ' ';
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << "********ft********" << std::endl;
	// 	ft::Vector<int> defaultf;
	// 	ft::Vector<int> first(myints, myints + sizeof(myints) / sizeof(int) );                              
	// 	ft::Vector<int>::iterator i2;
	// 	i2 = first.begin() + 2;
	// 	// i2 = defaultf.begin();

	// 	first.insert(i2, 15);
	// 	// defaultf.insert(i2, 15);

	// 	for (ft::Vector<int>::size_type i = 0; i < first.size(); i++) {
    // 		std::cout << i << ":";
    // 		std::cout << first.at(i) << ' ';
	// 	}
	// 		std::cout << std::endl;


		// {
		// 	std::cout << "********fill********" << std::endl;
    	// 	std::vector<int> vec(4 ,100);
    	// 	std::vector<int>::iterator it = vec.begin() + 2;
		
    	// 	// inserts 4 two times at front
    	// 	vec.insert(it, 10, 10);
    	// 	std::cout << "The vector elements are: ";
		// 	int i = 0;
    	// 	for (it = vec.begin(); it != vec.end(); ++it)
		// 	{
		// 		std::cout <<  i++ <<":";
    	// 	    std::cout << *it << " ";
		// 	}
		// 	std::cout << std::endl;	
		// 	std::cout << vec.capacity() << "cap \n";
		// }

		// {
		// 	std::cout << "********ft********" << std::endl;
    	// 	ft::Vector<int> vec(4 ,100);
    	// 	ft::Vector<int>::iterator it  = vec.begin() + 2;
    	// 	vec.insert(it, 10, 10);
    	// 	std::cout << "The vector elements are: ";
    	// 	// for (it = vec.begin(); it != vec.end(); ++it){
		// 	// 	std::cout <<  ":";
    	// 	//     std::cout << *it << " ";
		// 	// }		
		// 	for (ft::Vector<int>::size_type i = 0; i < vec.size(); i++)
		// 	{
		// 		std::cout << i << ":";
		// 		std::cout << vec.at(i) << ' ';
		// 	}
		// 	std::cout << std::endl;
		// }
		
		{
		
			std::vector<int> vec1(4, 100);
			std::vector<int> v(5, 200);
		
			// inserts at the beginning of v
			v.insert(v.begin() + 2, vec1.begin(), vec1.end());
			std::cout << "*" <<v.capacity()<< std::endl;
			for (std::vector<int>::size_type i = 0; i < v.size(); i++)
			{
				std::cout << i << ":";
				std::cout << v.at(i) << ' ';
			}
			// try {
  			//   v.at(100)=100;      // vector::at throws an out-of-range
  			// }
  			// catch (const std::out_of_range& oor) {
  			//   std::cerr << "Out of Range error: " << oor.what() << '\n';
  			// }
			// v.clear();
			std::cout << std::endl;
			
			v.erase(v.begin() + 2);
			for (std::vector<int>::size_type i = 0; i < v.size(); i++)
			{
				std::cout << i << ":";
				std::cout << v.at(i) << ' ';
			}
			std::cout << "size: " << v.capacity();
			std::cout << std::endl;
		}
		{
			std::cout << "********ft********" << std::endl;
		
			ft::Vector<int> vec1(4, 100);
			ft::Vector<int> v(5,200);
		
			v.insert(v.begin() + 2, vec1.begin(), vec1.end());
		
			for (ft::Vector<int>::size_type i = 0; i < v.size(); i++)
			{
				std::cout << i << ":";
				std::cout << v.at(i) << ' ';
			}
			// try {
  			//   v.at(100)=100;      // vector::at throws an out-of-range
  			// }
  			// catch (const std::out_of_range& oor) {
  			//   std::cerr << "Out of Range error: " << oor.what() << '\n';
  			// }
			// v.clear();
			std::cout << std::endl;

			v.erase(v.begin() + 2);
			for (std::vector<int>::size_type i = 0; i < v.size(); i++)
			{
				std::cout << i << ":";
				std::cout << v.at(i) << ' ';
			}
			std::cout << "size: " << v.capacity();

			std::cout << std::endl;
		}
		
		// {
		// 	std::vector<int> myvector (5);

  		// 	std::vector<int>::reverse_iterator rit = myvector.rbegin();

  		// 	int i=0;
  		// 	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
  		// 	  *rit = ++i;
			
		// 	// std::cout << "rb: " << *(myvector.rbegin()) << std::endl;
		// 	// std::cout << "b: "  << *(myvector.begin()) << std::endl;
		// 	// std::cout << "re: " << *(myvector.rend()) << std::endl;
		// 	// std::cout << "e: " << *(myvector.end()) << std::endl;
  		// 	std::cout << "myvector contains:";
  		// 	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  		// 	  std::cout << ' ' << *it;
  		// 	std::cout << '\n';
		// }
		
		// {
		// 	ft::Vector<int> myvector (5);

		// 	ft::Vector<int>::reverse_iterator rit;

		// 	int i=0;
		// 	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		// 		*rit = ++i;
		// 	// std::cout << "rb: " << *(myvector.rbegin()) << std::endl;
		// 	// std::cout << "b: "  << *(myvector.begin()) << std::endl;
		// 	// std::cout << "re: " << *(myvector.rend()) << std::endl;
		// 	// std::cout << "e: " << *(myvector.end()) << std::endl;
		// 	myvector.insert(myvector.begin(), 1, 6);
		// 	std::cout << "myvector contains:";
		// 	for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		// 		std::cout << "*  " << *it;
		// 	std::cout << '\n';
		// }
    	return 0;
	// }
}
