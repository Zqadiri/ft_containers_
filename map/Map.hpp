/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:50:41 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/24 22:10:34 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../utilities/bidirectional_iterator.hpp"
#include "../utilities/utility.hpp"
#include "../utilities/avl_tree.hpp"
#include "../vector/vector.hpp"
#include <map>
#include <functional>
#include <algorithm>
#include <vector>
#include <memory>

namespace ft
{
	template <typename Key,
				typename T,
				typename Compare = std::less<Key>,
				typename Alloc = std::allocator<ft::pair<const Key,T> >
				> class map
	{
	public:
		typedef     		Key                                     				key_type;
		typedef     		T                                       				mapped_type;
		typedef     		ft::pair<const key_type,mapped_type>    				value_type;
		typedef				Compare 												key_compare;
		typedef	class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			protected:
				Compare comp;
  				value_compare (Compare c) : comp(c) {}
			public:
				bool operator() (const value_type& x, const value_type& y) const{
					return comp(x.first, y.first);
  				}
		} value_compare;
		typedef				Alloc														allocator_type;
		typedef	typename 	allocator_type::reference									reference;
		typedef typename 	allocator_type::const_reference 							const_reference;
		typedef typename 	allocator_type::pointer										pointer;
		typedef typename 	allocator_type::const_pointer   							const_pointer;
		typedef typename 	allocator_type::size_type									size_type;
		typedef 			ft::map_iterator<value_type , key_compare>					iterator;
		typedef 			ft::map_iterator<value_type , key_compare>					const_iterator;
		typedef				reverse_iterator<iterator> 									reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator> 						const_reverse_iterator;
		typedef	typename	std::ptrdiff_t												difference_type;
		typedef typename 	ft::avl_tree<value_type, key_compare>::node_type			node_type;
		
			//! ----------- Constructors & Destructor ------------ !//
		
		inline explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(), _comp(), _alloc(){
			_comp = comp;
			_alloc = alloc;
		}		

		template <class InputIterator>
		inline map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(){
			_comp = comp;
			_alloc = alloc;
			this->insert (first, last);
		}	

		inline map (const map& x){
			*this = x;
		}

		~map (void){
			this->erase(begin(), end());
		}

		//! ----------- Operators --------------!//

		map& operator=(const map& x){
			_alloc = x._alloc;
			_comp = x._comp;
			this->clear();
			if (x.size())
				this->insert(x.begin(), x.end());
			return (*this);
		}

		/*
		 TODO: Access element
		 If k matches the key of an element the function returns a reference to its mapped value.
		 If k does not match the key of any element the function inserts a new element .
		 (*((this->insert(make_pair(k,mapped_type()))).first)).second
		*/
	
		mapped_type& operator[] (const key_type& k){
			if (_tree.searchForKey(k, _tree.rootPtr)){
				node_type *find = _tree.searchKey(k, _tree.rootPtr);
				return find->data.second;
			}
			this->insert(ft::make_pair(k, mapped_type()));
			node_type *ret = _tree.searchKey(k, _tree.rootPtr);
 			return ret->data.second;
		}

		// !------- Member functions ----------!//

		/*
		 TODO: Clear the map
		 destroy all the map element 
		*/

		void clear(){ //! deallocate
			this->erase(begin(), end());
		}

		void swap (map& x){
			allocator_type tmp_alloc = _alloc;
			key_compare tmp_comp = _comp;
			typename ft::avl_tree<value_type, key_compare> tmp_tree = _tree;

			this->_tree = x._tree;
			this->_alloc = x._alloc;
			this->_comp = x._comp;
			
			x._alloc = tmp_alloc;
			x._comp = tmp_comp;
			x._tree = tmp_tree;
		}

		size_type max_size() const{
			allocator_type alloc;
			return (alloc.max_size());
		}

		bool empty() const{
			return (_tree.treeSize == 0);
		}

		value_compare value_comp() const
			{ return (value_compare(key_compare())); }

		size_type size() const{
			return (_tree.treeSize);			
		}

		iterator begin(){
			if (!_tree.rootPtr)
				return (iterator());
			iterator it(_tree, _tree.beginTree(_tree.rootPtr));
			return (it);	
		}

		const_iterator begin() const{
			if (!_tree.rootPtr)
				return (iterator());
			const_iterator it(_tree, _tree.beginTree(_tree.rootPtr));
			return (it);		
		}

		reverse_iterator rbegin(){
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(this->end());
		}

		reverse_iterator rend(){
			return reverse_iterator(this->begin());			
		}

		const_reverse_iterator rend() const{
			return const_reverse_iterator(this->begin());
		}

		iterator end(){
			if (!_tree.rootPtr)
				return (iterator());
			node_type *temp = _tree.minValue(_tree.rootPtr);
			iterator it(_tree, temp);
			return (++it);  
		}
		
		const_iterator end() const{
			node_type *temp = _tree.minValue(_tree.rootPtr);
			const_iterator it(_tree, temp);
			return (++it);		
		}
		
		/*
		 TODO: Insert a single element
		 insert a single element in the avlTree
		 return false if the value already exists
		 and true if its not
		*/

		pair<iterator,bool> insert (const value_type& val){
			size_type init_size = _tree.treeSize;
			_tree.rootPtr = _tree.insert(_tree.rootPtr, val);
			iterator it(_tree, _tree.rootPtr);
			if (init_size != _tree.treeSize)
				return (ft::make_pair(it, true));
			return (ft::make_pair(it, false));
		}
	

		iterator insert (iterator position, const value_type& val){
			(void)position;
			_tree.rootPtr = _tree.insert(_tree.rootPtr, val);
			iterator it(_tree, _tree.rootPtr);
			return (it);
		}

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last){
			for ( ; first != last; first++)
				this->insert(ft::make_pair(first->first, first->second));
		}

		/*
		 TODO: find an element by key
		*/

		iterator find (const key_type& k) {
			node_type *find = _tree.searchKey(k, _tree.rootPtr);
			iterator it(_tree, find);
			return (it);
		}
		
		const_iterator find (const key_type& k) const{
			node_type *find = _tree.searchKey(k, _tree.rootPtr);
			iterator it(_tree, find);
			return (it);
		}

		allocator_type get_allocator() const{
			return (_alloc);
		}

		key_compare key_comp() const{
			return (key_compare());
		}

		/*
		 TODO: Return a iterator 
		 pointing to the element have "k" like key, give an iterator to it.
		 @Two keys are considered equivalent if key_comp returns false reflexively
		*/

		iterator lower_bound (const key_type& k){
			node_type *temp = _tree.lowerBound(_tree.beginTree(_tree.rootPtr), k);
			if (!temp)
				return (end());
			return (iterator(_tree, temp));
		}

		const_iterator lower_bound (const key_type& k) const{
			node_type *temp = _tree.lowerBound(_tree.beginTree(_tree.rootPtr), k);
			if (!temp)
				return (end());
			return (const_iterator(_tree, temp));
		}

		/*
		 TODO:Returns an iterator
		 pointing to the first element in the container 
		 whose key is considered to go after k
		*/

		iterator upper_bound (const key_type& k){
			node_type *temp = _tree.upperBound(_tree.beginTree(_tree.rootPtr), k);
			if (!temp)
				return (end());
			return (iterator(_tree, temp));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			node_type *temp = _tree.upperBound(_tree.beginTree(_tree.rootPtr), k);
			if (!temp)
				return (end());
			return (const_iterator(_tree, temp));
		}
		
		size_type count (const key_type& k) const{
			if (_tree.searchForKey(k, _tree.rootPtr))
				return (1);
			return(0);
		}

		pair<iterator,iterator> equal_range (const key_type& k)
		{
			if (_tree.searchForKey(k, _tree.rootPtr))
			{
				iterator it(_tree, _tree.searchKey(k, _tree.rootPtr)), ite = this->end();
				if (it == --ite)
					return ft::make_pair(it, iterator());
				return ft::make_pair(it, ++it);
			}
			return ft::make_pair(upper_bound(k), upper_bound(k));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		/*
		 TODO: Erase elements
		 Removes from the map either a single element 
		 or a range of elements ([first,last))
		*/

		void erase (iterator position){
			_tree.rootPtr = _tree.deleteNode(_tree.rootPtr, (*position).first);
			_tree.treeSize--;
		}

		size_type erase (const key_type& k){
			if (!_tree.searchForKey(k, _tree.rootPtr))
				return 0;
			_tree.rootPtr = _tree.deleteNode(_tree.rootPtr, k);
			_tree.treeSize--;
			return 1;
		}

		void erase (iterator first, iterator last){
			ft::Vector<key_type> keyToRemove;
			for(; first != last; ++first)
				keyToRemove.push_back((*first).first);
			for (std::vector<int>::size_type i = 0; i < keyToRemove.size(); i++){
				_tree.rootPtr = _tree.deleteNode(_tree.rootPtr, keyToRemove.at(i));
				_tree.treeSize--;
			}
		}

		private:
			typename ft::avl_tree<value_type, key_compare>	_tree;
			key_compare										_comp;
			allocator_type									_alloc;

	};
	
	//! -------------- Relational operators ---------------- !//

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());	
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator< ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator> ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
  	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){
		x.swap(y);
	}
}

#endif
