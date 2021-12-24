/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/24 16:14:02 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"
#include <type_traits>
#include <iterator>
#include <vector>
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
	// 	ft::Vector<int> my_vector(3);
	// 	ft::Vector<int>::iterator it(my_vector.begin());
	// 	ft::Vector<int>::const_iterator c_it(it);
	// }
	// {
	// 	/*------------------ std::vectors ---------------------*/
    //     std::vector<std::string>    v1(10, "string2");
    //     std::vector<char>            v2;
    //     /*------------------ ft:vectors ---------------------*/
    //     ft::Vector<std::string>     ft_v1(10, "string2");
    //     ft::Vector<char>             ft_v2;

    //   	v1.assign(10, "less");
    //     ft_v1.assign(10, "less");
	// 	for (ft::Vector<std::string>::size_type i = 0; i < v1.size(); i++)
	// 		std::cout << " *" << v1.at(i);
	// 	std::cout << "    " << v1.size() << "    " << v1.capacity();
	// 	std::cout << std::endl;
	// 	for (ft::Vector<std::string>::size_type i = 0; i < ft_v1.size(); i++)
	// 		std::cout << " *" << ft_v1.at(i);
	// 	std::cout << "    " << ft_v1.size() << "    " << ft_v1.capacity();
	// 	std::cout << std::endl;
	// }
	// ft::Vector<int> my_vector(3);
	// ft::Vector<int>::reverse_iterator it(my_vector.rbegin()); 
	// ft::Vector<int>::const_reverse_iterator c_it;
	// c_it = it;
	// {
	// 	std::vector<std::string>::iterator valid_it, valid_eit;
    //     ft::Vector<std::string>::iterator ft_valid_it, ft_valid_eit;
	// 	/*------------------ std::vectors ---------------------*/
	// 	std::vector<std::string>    v1(10, "string2");
	// 	v1.resize(1e2, "hello");
	// 			std::cout << v1.capacity() << std::endl;
	// 	std::cout << v1.size() << std::endl;
	// 	for (ft::Vector<std::string>::size_type i = 0; i < v1.size(); i++)
	// 		std::cout << " *" << v1.at(i);
	// 	/*------------------ ft::vectors ---------------------*/
	// 	ft::Vector<std::string>    ft_v1(10, "string2");
	// 	ft_v1.resize(1e2, "hello");
	// 		std::cout << v1.capacity() << std::endl;
	// 	std::cout << v1.size() << std::endl;
	// 	for (ft::Vector<std::string>::size_type i = 0; i < ft_v1.size(); i++)
	// 		std::cout << " *" << ft_v1.at(i);
	// 	v1.resize(20);
	// 	std::cout << v1.capacity() << std::endl;
	// 	std::cout << v1.size() << std::endl;
	// 	v1.resize(1e5);
	// 	std::cout << v1.capacity() << std::endl;
	// 	std::cout << v1.size() << std::endl;
	// 	std::cout <<"----------- ft ------------" << std::endl;

	// 	/*------------------ ft::vectors ---------------------*/
	// 	ft_v1.resize(20);
	// 	std::cout << ft_v1.capacity() << " before (20)" << std::endl;
	// 	std::cout << ft_v1.size() << " before (20) "<<std::endl;
	// 	ft_v1.resize(1e5);
	// 	std::cout << ft_v1.capacity() << std::endl;
	// 	std::cout << ft_v1.size() << std::endl;
	// 	std::cout <<"-----------------------" << std::endl;

	// 	/*------------------ std::vectors ---------------------*/
	// 	v1.resize(50);
	// 	std::cout << v1.capacity() << " before (50)" << std::endl;
	// 	std::cout << v1.size() << " before (50) "<<std::endl;
	// 	/*------------------ ft::vectors ---------------------*/
	// 	std::cout <<"----------- ft ------------" << std::endl;
		
	// 	ft_v1.resize(50);
	// 	std::cout << ft_v1.capacity() << " before (50)" << std::endl;
	// 	std::cout << ft_v1.size() << " before (50) "<<std::endl;

	// 	std::cout <<"-----------------------" << std::endl;

	// 	/*------------------ std::vectors ---------------------*/
	// 	v1.resize(0, "string4");
	// 	std::cout << v1.capacity()  << std::endl;
	// 	std::cout << v1.size() <<std::endl;
	// 	std::cout <<"----------- ft ------------" << std::endl;
	// 	ft_v1.resize(0, "string4");
	// 	std::cout << ft_v1.capacity()  << std::endl;
	// 	std::cout << ft_v1.size() <<std::endl;
	// }
	{
            // std::vector<std::string>     v1(15, "hello");
            // std::vector<std::string>    v(20, "string");
            // ft::Vector<std::string>     ft_v(20, "string");


        	std::vector<std::string>    v1(20, "less");
        	std::vector<int>    v2;
        	std::vector<int>    v3;
        	/*------------------ std::vectors ---------------------*/
        	ft::Vector<std::string>     ft_v1(20, "less");
        	ft::Vector<int>     ft_v2;
        	ft::Vector<int>     ft_v3;

    		std::vector<int> tmp;
    		tmp.assign(26000000, 1);

			std::cout << "\nsize std " <<v3.size();
			std::cout << "\ncap std " <<v3.capacity();
            std::cout << "\nsize ft  " <<ft_v3.size();
            std::cout << "\ncap ft  " <<ft_v3.capacity() << std::endl;
			
			v2.assign(22000000, 1);
			ft_v2.assign(22000000, 1);

			try
			{
				v2.insert(v2.end() - 600,10,  44);
				 ft_v2.insert(ft_v2.end() - 600,10, 44);
			}
			catch (std::exception &e)
			{
				std::cout << "error\n";
			}

			// std::cout << *(&(*it)) << std::endl;
			
			std::cout << "\nsize std " <<v2.size();
			std::cout << "\ncap std " <<v2.capacity();
            std::cout << "\nsize ft  " <<ft_v2.size();
            std::cout << "\ncap ft  " <<ft_v2.capacity() << std::endl;
			
			for (ft::Vector<std::string>::size_type i = 0; i < v2.size(); i++)
				std::cout << " " << v2.at(i);
			std::cout << "\n =====================\n";
			for (ft::Vector<std::string>::size_type i = 0; i < ft_v2.size(); i++)
				std::cout << " " << ft_v2.at(i);
			std::cout << std::endl;
			
           
		   
			// for (ft::Vector<std::string>::size_type i = 0; i < v1.size(); i++)
			// 	std::cout << "" << v1.at(i);
			// std::cout << "\n =====================\n";
			// for (ft::Vector<std::string>::size_type i = 0; i < ft_v1.size(); i++)
			// 	std::cout << "" << ft_v1.at(i);
			// std::cout << std::endl;
	}
	
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
		
		// {
		
		// 	std::vector<int> vec1(4, 100);
		// 	std::vector<int> v(5, 200);
			
		// 	std::vector<int> vr { 34,23 };
			
		// 	// inserts at the beginning of v
		// 	v.insert(v.begin() + 2, vec1.begin(), vec1.end());
		// 	std::cout << "*" <<v.capacity()<< std::endl;
		// 	for (std::vector<int>::size_type i = 0; i < v.size(); i++)
		// 	{
		// 		std::cout << i << ":";
		// 		std::cout << v.at(i) << ' ';
		// 	}
		// 	// try {
  		// 	//   v.at(100)=100;      // vector::at throws an out-of-range
  		// 	// }
  		// 	// catch (const std::out_of_range& oor) {
  		// 	//   std::cerr << "Out of Range error: " << oor.what() << '\n';
  		// 	// }
		// 	// v.clear();
		// 	std::cout << std::endl;
			
		// 	v.erase(v.begin());
		// 	v.pop_back();
		// 	v.push_back(99);

		// 	for (std::vector<int>::size_type i = 0; i < v.size(); i++)
		// 	{
		// 		std::cout << i << ":";
		// 		std::cout << v.at(i) << ' ';
		// 	}
		// 	std::cout << "size: " << v.size();
		// 	std::cout << std::endl;
		// }
		// {
		// 	std::cout << "********ft********" << std::endl;
		
		// 	ft::Vector<int> vec1(4, 100);
		// 	ft::Vector<int> v(5,200);
		
		// 	v.insert(v.begin() + 2, vec1.begin(), vec1.end());
		
		// 	for (ft::Vector<int>::size_type i = 0; i < v.size(); i++)
		// 	{
		// 		std::cout << i << ":";
		// 		std::cout << v.at(i) << ' ';
		// 	}
		// 	// try {
  		// 	//   v.at(100)=100;      // vector::at throws an out-of-range
  		// 	// }
  		// 	// catch (const std::out_of_range& oor) {
  		// 	//   std::cerr << "Out of Range error: " << oor.what() << '\n';
  		// 	// }
		// 	// v.clear();
		// 	std::cout << std::endl;
		// 	v.erase(v.begin());
		// 	v.pop_back();
		// 	v.push_back(99);

		// 	for (std::vector<int>::size_type i = 0; i < v.size(); i++)
		// 	{
		// 		std::cout << i << ":";
		// 		std::cout << v.at(i) << ' ';
		// 	}

		// 	std::cout << "size: " << v.size();
		// 	std::cout << std::endl;
		// }
	
		// iterator erase (iterator position)
		// {
		// 	pointer p_pos = &(*position);
		// 	_alloc.destroy(&(*position));
		// 	if (&(*position) + 1 == _end)
		// 		_alloc.destroy(&(*position));
		// 	else
		// 	{
		// 		for (int i = 0; i < _end - &(*position) - 1; i++)
		// 		{
		// 			_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
		// 			_alloc.destroy(&(*position) + i + 1);
		// 		}
		// 	}
		// 	_end -= 1;
		// 	return (iterator(p_pos));
		// }
		
		// iterator erase (iterator first, iterator last)
		// {
		// 	pointer p_first = &(*first);
		// 	for (; &(*first) != &(*last); first++)
		// 		_alloc.destroy(&(*first));
		// 	for (int i = 0; i < _end - &(*last); i++)
		// 	{
		// 		_alloc.construct(p_first + i, *(&(*last) + i));
		// 		_alloc.destroy(&(*last) + i);
		// 	}
		// 	_end -= (&(*last) - p_first);
		// 	return (iterator(p_first));
		// }
	
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
		{
		// 	std::cout << std::endl;
		// 	std::cout << std::endl;
		// 	std::cout << std::endl;

		// 	std::vector<int>::size_type sz;

  		// 	std::vector<int> foo;
  		// 	sz = foo.capacity();
  		// 	std::cout << "making foo grow:\n";
  		// 	for (int i=0; i<100; ++i) {
  		// 	  foo.push_back(i);
  		// 	  if (sz!=foo.capacity()) {
  		// 	    sz = foo.capacity();
  		// 	    std::cout << "capacity changed: " << sz << '\n';
  		// 	  }
  		// 	}
			
  		// 	std::vector<int> bar;
  		// 	sz = bar.capacity();
  		// 	bar.reserve(100);   // this is the only difference with foo above
  		// 	std::cout << "making bar grow:\n";
  		// 	for (int i=0; i<100; ++i) {
  		// 	  bar.push_back(i);
  		// 	  if (sz!=bar.capacity()) {
  		// 	    sz = bar.capacity();
  		// 	    std::cout << "capacity changed: " << sz << '\n';
  		// 	  }
  		// 	}
		// }

		// {
		// 	std::cout << std::endl;
		// 	std::cout << std::endl;
		// 	std::cout << std::endl;

		// 	ft::Vector<int>::size_type sz;

  		// 	ft::Vector<int> foo;
  		// 	sz = foo.capacity();
		// 	// std::cout << foo.capacity() <<  cap \n";
		// 	// std::cout << foo.size() << "************** cap \n";
  		// 	std::cout << "making foo grow:\n";
  		// 	for (int i=0; i<100; ++i) {
  		// 	  foo.push_back(i);
  		// 	  if (sz!=foo.capacity()) {
  		// 	    sz = foo.capacity();
  		// 	    std::cout << "capacity changed: " << sz << '\n';
  		// 	  }
  		// 	}
			
  		// 	ft::Vector<int> bar;
  		// 	sz = bar.capacity();
  		// 	bar.reserve(100);   // this is the only difference with foo above
  		// 	std::cout << "making bar grow:\n";
  		// 	for (int i=0; i<100; ++i) {
  		// 	  bar.push_back(i);
  		// 	  if (sz!=bar.capacity()) {
  		// 	    sz = bar.capacity();
  		// 	    std::cout << "capacity changed: " << sz << '\n';
  		// 	  }
  		// 	}
		// }

		// {
		// 	std::vector<int> foo (3,100);   
		// 	std::vector<int> bar (5,200);   
		// 	foo.swap(bar);

		// 	std::cout << "foo contains:";
		// 	for (unsigned i=0; i<foo.size(); i++)
		// 	std::cout << ' ' << foo[i];
		// 	std::cout << '\n';

		// 	std::cout << "bar contains:";
		// 	for (unsigned i=0; i<bar.size(); i++)
		// 	std::cout << ' ' << bar[i];
		// 	std::cout << '\n';
		// }
		// {
		// 	ft::Vector<int> foo (3,100);   // three ints with a value of 100
		// 	ft::Vector<int> bar (5,200);   // five ints with a value of 200

		// 	foo.swap(bar);

		// 	std::cout << "foo contains:";
		// 	for (unsigned i=0; i<foo.size(); i++)
		// 	std::cout << ' ' << foo[i];
		// 	std::cout << '\n';

		// 	std::cout << "bar contains:";
		// 	for (unsigned i=0; i<bar.size(); i++)
		// 	std::cout << ' ' << bar[i];
		// 	std::cout << '\n';
		// 	std::cout << '\n';
		// 	std::cout << '\n';

		// }
		// {
		// 	std::vector<int> myvector;

		// 	// set some initial content:
		// 	for (int i=1;i<10;i++) myvector.push_back(i);

		// 	// myvector.resize(5);
		// 	// myvector.resize(8,100);
		// 	myvector.resize(12);

		// 	std::cout << "myvector contains:";
		// 	for (size_t i=0;i<myvector.size();i++)
		// 		std::cout << ' ' << myvector[i];
		// 	std::cout << '\n';
		// }
		// {
		// 	ft::Vector<int> myvector;

		// 	// set some initial content:
		// 	for (int i=1;i<10;i++) myvector.push_back(i);

		// 	// myvector.resize(5);
		// 	// myvector.resize(8,100);
		// 	myvector.resize(12);

		// 	std::cout << "myvector contains:";
		// 	for (size_t i=0;i<myvector.size();i++)
		// 		std::cout << ' ' << myvector[i];
		// 	std::cout << '\n';

		// 	std::cout << '\n';
		// 	std::cout << '\n';
        	
		// 	std::vector<int> v(4,5);
		// 	std::vector<int>::reverse_iterator 		my_rit2(v.end());
    	//     std::vector<int>::const_reverse_iterator c_it, c_ob(v.end());
    	//     c_it = my_rit2;
    	//     // EQUAL(&(*my_rit2) == &(*c_it) && (&(*my_rit2) == &(*c_ob)));
			
		// }
    	return 0;
	}
}
