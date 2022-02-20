/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:49:41 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/20 16:52:19 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "Vector.hpp"

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

int main()
{
    // std::vector<int> vector;
    // ft::Vector<int> v(4, 5);
    // ft::Vector<int>::reverse_iterator my_rit2(v.begin());
    // ft::Vector<int>::const_reverse_iterator c_it(v.begin());
    // c_it = my_rit2;
    // std::vector<int> v;
    // vector.assign(2600 * 1000, 1);
    // // g_start2 = timer();
    // v.push_back(*(vector.insert(vector.end() - 800 * 1000, 44)));
    // // g_end2 = timer();
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::Vector<A> vv;
    ft::Vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
    	// v.push_back(vv.size());
    	// v.push_back(vv.capacity());
    }
    system("leaks a.out");
    // return v;
}