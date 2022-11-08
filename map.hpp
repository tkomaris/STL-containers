#ifndef MAP_HPP
#define MAP_HPP

#include <stdexcept>
/*
https://cplusplus.com/reference/stdexcept/
This header defines a set of standard exceptions that both the library 
and programs can use to report common errors.
*/
#include "./utils/utils.hpp"
#include "./utils/map_iterator.hpp"
#include "./utils/reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		/*
		https://cplusplus.com/reference/map/map/
		Maps are associative containers that store elements formed by a combination of a key value and 
		a mapped value, following a specific order. In a map, the key values are generally used to sort 
		and uniquely identify the elements, while the mapped values store the content associated to this 
		key. The types of key and mapped value may differ, and are grouped together in member type value_type, 
		which is a pair type combining both: typedef pair<const Key, T> value_type;

		Internally, the elements in a map are always sorted by its key following a specific strict weak 
		ordering criterion indicated by its internal comparison object (of type Compare).
		map containers are generally slower than unordered_map containers to access individual elements 
		by their key, but they allow the direct iteration on subsets based on their order.
		The mapped values in a map can be accessed directly by their corresponding key using the bracket 
		operator ((operator[]).
		*/
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef BSTNode<value_type>	map_node;
		typedef ft::MapIterator<map_node, value_type> iterator;
		typedef ft::ConstMapIterator<map_node, const value_type, iterator> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef typename Alloc::template rebind<map_node>::other node_allocator_type;
	
	private:
		key_compare	_compare;
		allocator_type _alloc;
		node_allocator_type	_node_alloc;
		map_node* _root;
		map_node* _end;
		map_node* _rend;
		size_type _size;
	
	public:	
		class value_compare
		{
			friend class map;

		protected:
			Compare _comp;
			value_compare(Compare c) : _comp(c) {}

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return(_comp(x.first, y.first));
			}
		};

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) 
			: _compare(comp), _alloc(alloc), _node_alloc(std::allocator<map_node>()), _root(NULL), _end(NULL), _rend(NULL), _size(0)
		{
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, map_node());
				_rend = _node_alloc.allocate(1);
				_node_alloc.construct(_rend, map_node());
				_rend->parent = _end;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			_compare = comp;
			_size = 0;
			_alloc = alloc;
			_node_alloc = std::allocator<map_node>();
            _root = NULL;
            
            _end = _node_alloc.allocate(1);
            _node_alloc.construct(_end, map_node());
            _rend = _node_alloc.allocate(1);
            _node_alloc.construct(_rend, map_node());
            _rend->parent = _end;
			this->insert(first, last);
		}

		map(const map &x)
		{
            _end = _node_alloc.allocate(1);
            _node_alloc.construct(_end, map_node());

            _rend = _node_alloc.allocate(1);
            _node_alloc.construct(_rend, map_node());
            _rend->parent = _end;
            _root = NULL;
            *this = x;
		}

		~map()
		{
			this->clear();
			_node_alloc.destroy(_end);
			_node_alloc.deallocate(_end, 1);
			_node_alloc.destroy(_rend);
			_node_alloc.deallocate(_rend, 1);
		}

		map &operator=(const map &x)
		{
            this->clear();
            _compare = x._compare;
			_size = 0;
			_alloc = x._alloc;
			_node_alloc = x._node_alloc;
            this->insert(x.begin(), x.end());
			return(*this);
		}
		
		/*
		https://cplusplus.com/reference/map/map/begin/
		Returns an iterator referring to the first element in the map container.
		Because map containers keep their elements ordered at all times, 
		begin points to the element that goes first following the container's sorting criterion.
		If the container is empty, the returned iterator value shall not be dereferenced.
		*/
		iterator begin()
		{
			return(iterator(_rend->parent));
		}

		const_iterator begin() const
		{
			return(const_iterator(_rend->parent));
		}
		
		/*
		https://cplusplus.com/reference/map/map/end/
		Returns an iterator referring to the past-the-end element in the map container.
		The past-the-end element is the theoretical element that would follow the last element in the map container. It does not point to any element, and thus shall not be dereferenced.
		Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with map::begin to specify a range including all the elements in the container.
		If the container is empty, this function returns the same as map::begin.
		*/
		iterator end()
		{
			return(iterator(_end));
		}

		const_iterator end() const
		{
			return(const_iterator(_end));
		}

		reverse_iterator rbegin()
		{
			return(reverse_iterator(_end));
		}

		const_reverse_iterator rbegin() const
		{
			return(const_reverse_iterator(_end));
		}

		reverse_iterator rend()
		{
			return(reverse_iterator(_rend->parent));
		}

		const_reverse_iterator rend() const
		{
			return(const_reverse_iterator(_rend->parent));
		}

		/*
		https://cplusplus.com/reference/map/map/empty/
		true if the container size is 0, false otherwise.
		*/
		bool empty() const
		{
			if (_size == 0)
				return(1);
			return(0);
		}

		/*
		Return: the number of elements in the map container.
		_last_node is from binary_search_tree_algo.hpp: it is the variable which keeps the pointers about the parent, left and right children
		*/
		size_type size() const
		{
			return(_size);
		}
		
		// Return: the maximum number of elements that the map container can hold.
		size_type max_size() const
		{
			return(_alloc.max_size());
		}

		/*
		https://cplusplus.com/reference/map/map/operator[]/
		If k matches the key of an element in the container, the function returns a reference to its mapped value.
		If k does not match the key of any element in the container, the function inserts a new element with that 
		key and returns a reference to its mapped value. Notice that this always increases the container size by one, 
		even if no mapped value is assigned to the element (the element is constructed using its default constructor).
		A similar member function, map::at, has the same behavior when an element with the key exists, but throws an exception when it does not.
		A call to this function is equivalent to:
		(*((this->insert(make_pair(k,mapped_type()))).first)).
		*/
		mapped_type &operator[](const key_type &k)
		{
			return((*(this->insert(value_type(k, mapped_type())).first)).second);
		}
		
		/*
		https://cplusplus.com/reference/map/map/at/
		Returns a reference to the mapped value of the element identified with key k.
		If k does not match the key of any element in the container, the function throws an out_of_range exception.
		*/
        mapped_type &at(const key_type &key)
        {
            iterator it = this->find(key);
            if (it == this->end())
                throw std::out_of_range("out_of_range");
            return((*it).second);
        }

        const mapped_type &at(const key_type &key) const
        {
            const_iterator it = this->find(key);
            if (it == this->end())
                throw std::out_of_range("out_of_range");
            return((*it).second);
        }

		/*
		https://cplusplus.com/reference/map/map/insert/
		Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
		Because element keys in a map are unique, the insertion operation checks whether each inserted element has a key equivalent 
		to the one of an element already in the container, and if so, the element is not inserted, returning an iterator to this existing
		element (if the function returns a value). For a similar container allowing for duplicate elements, see multimap.
		An alternative way to insert elements in a map is by using member function map::operator[].
		Internally, map containers keep all their elements sorted by their key following the criterion specified by its comparison 
		object. The elements are always inserted in its respective position following this ordering.
		Return value : 
		The single element versions (pair<iterator,bool> insert (const value_type& val)) return a pair, with its member pair::first set 
		to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map. The pair::second 
		element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
		The versions with a hint (iterator insert (iterator position, const value_type& val)) return an iterator pointing to either 
		the newly inserted element or to the element that already had an equivalent key in the map.
		*/
		pair<iterator, bool> insert(const value_type &val)
		{
			iterator	it;
			map_node	*node;
			map_node	*new_node;

			if (!_root)
			{
				_root = _node_alloc.allocate(1);
				_node_alloc.construct(_root, map_node(val));
				
				_root->left = _rend;
				_root->right = _end;
				_end->parent = _root;
				_rend->parent = _root;

				_size = 1;
				return(ft::make_pair(iterator(_root), true));
			}
			it = this->find(val.first);
			if (it != this->end())
				return(ft::make_pair(it, false));
			node = _root;
			while (node->right || node->left)
			{
				if (_compare(node->value.first, val.first))
				{
					if (node->right && node->right != _end)
						node = node->right;
					else
						break ;
				}
				else
				{
					if (node->left && node->left != _rend)
						node = node->left;
					else
						break ;
				}
			}
			new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, map_node(val));
			new_node->parent = node;
			if (_compare(node->value.first, val.first))
			{
				new_node->right = node->right;
                if (new_node->right)
				    new_node->right->parent = new_node;
				new_node->left = NULL;
				node->right = new_node;
			}
			else
			{
				new_node->left = node->left;
                if (new_node->left)
				    new_node->left->parent = new_node;
				new_node->right = NULL;
				node->left = new_node;
			}
			_size++;
			return(ft::make_pair(new_node, true));
		}

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return((this->insert(val)).first);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this->insert(*first);
				first++;
			}
		}

		/*
		https://cplusplus.com/reference/map/map/erase/
		Removes from the map container either a single element or a range of elements ([first,last)).
		This effectively reduces the container size by the number of elements removed, which are destroyed.
		Return value: for the key-based version (size_type erase (const key_type& k)), the function returns the number of elements erased.
		*/
		void erase(iterator position)
		{
			map_node *node;
			map_node *right;
			map_node *left;
			map_node *parent;
            map_node *next;

			node = position.get_internal_pointer();
			right = node->right;
			left = node->left;
			parent = node->parent;
            next = node->next();
			if (!right && !left)
			{
				if (parent->right == node)
					parent->right = NULL;
				else
					parent->left = NULL;
			}
			else if (!right && left)
			{
				if (parent->right == node)
					parent->right = left;
				else
					parent->left = left;
				left->parent = parent;
			}
			else if (right && !left)
			{
				if (parent->right == node)
					parent->right = right;
				else
					parent->left = right;
				right->parent = parent;
			}
			else
			{
				if (next != node->right)
				{
					if (next->right)
					{
						next->parent->left = next->right;
						next->right->parent = next->parent;
					}
					if (!parent)
						_root = next;
					else if (parent->right == node)
						parent->right = next;
					else
						parent->left = next;
                    if (next->parent->right == next)
                        next->parent->right = NULL;
                    else
                        next->parent->left = NULL;
					next->parent = parent;
					next->right = right;
					next->left = left;
					left->parent = next;
					right->parent = next;
				}
				else
				{
					if (!parent)
						_root = next;
					else if (parent->right == node)
						parent->right = next;
					else
						parent->left = next;
					left->parent = next;
					next->parent = parent;
					next->left = left;
				}
			}
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
			_size--;
			if (_size == 0)
			{
				_root = NULL;
				_rend->right = NULL;
				_rend->left = NULL;
				_end->right = NULL;
				_end->left = NULL;
				_rend->parent = _end;
			}
		}

		size_type erase(const key_type &k)
		{
			iterator it;
			if ((it = this->find(k)) == this->end())
				return(0);
			erase(it);
			return(1);
		}

		void erase(iterator first, iterator last)
		{
            iterator to_delete;

            if (first == last)
                return ;
            to_delete = first;
            erase(++first, last);
            erase(to_delete);
		}

		/*
		https://cplusplus.com/reference/map/map/swap/
		Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
		After the call to this member function, the elements in this container are those which were in x before the call, and the 
		elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
		*/
		void swap(map &x)
		{
            map_node    *tmp;
            size_type   size_tmp;

            if (x == *this)
                return ;
            tmp = x._root;
            x._root = _root;
            _root = tmp;
            tmp = x._end;
            x._end = _end;
            _end = tmp;
            tmp = x._rend;
            x._rend = _rend;
            _rend = tmp;
            size_tmp = x._size;
            x._size = _size;
            _size = size_tmp;
		}

		/*
		https://cplusplus.com/reference/map/map/clear/
		Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		*/
		void clear()
		{
			this->erase(this->begin(), this->end());
		}

		/*
		https://cplusplus.com/reference/map/map/key_comp/
		Returns a copy of the comparison object used by the container to compare keys.
		The comparison object of a map object is set on construction. Its type (member key_compare) 
		is the third template parameter of the map template. By default, this is a less object, which returns the same as operator<.
		This object determines the order of the elements in the container: it is a function pointer 
		or a function object that takes two arguments of the same type as the element keys, and returns true if 
		the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.
		Two keys are considered equivalent if key_comp returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).
		*/
		key_compare key_comp() const
		{
			return(key_compare());
		}

		/*
		https://cplusplus.com/reference/map/map/value_comp/
		Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
		The arguments taken by this function object are of member type value_type (defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type part of the value is not taken into consideration in this comparison.
		The comparison object returned is an object of the member type map::value_compare, which is a nested class that uses the internal comparison object to generate the appropriate comparison functional class.
		*/
		value_compare value_comp() const
		{
			return(value_compare(key_compare()));
		}

		/*
		https://cplusplus.com/reference/map/map/find/
		Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
		Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).
		Another member function, map::count, can be used to just check whether a particular key exists.
		*/
		iterator find(const key_type &k)
		{
			map_node *node;

			node = _root;
			while (node && node != _end && node != _rend &&
                    (_compare(node->value.first, k) ||
				    _compare(k, node->value.first)))
			{
				if (_compare(node->value.first, k))
					node = node->right;
				else
					node = node->left;
			}
			if (node && node != _end && node != _rend &&
                    !_compare(node->value.first, k) &&
					!_compare(k, node->value.first))
				return(iterator(node));
			else
				return(iterator(_end));
		}

		const_iterator find(const key_type &k) const
		{
			map_node *node;

			node = _root;
			while (node && node != _end && node != _rend &&
                    (_compare(node->value.first, k) ||
					_compare(k, node->value.first)))
			{
				if (_compare(node->value.first, k))
					node = node->right;
				else
					node = node->left;
			}
			if (node && node != _end && node != _rend &&
                    !_compare(node->value.first, k) &&
					!_compare(k, node->value.first))
				return(const_iterator(node));
			else
				return(const_iterator(_end));
		}

		/*
		https://cplusplus.com/reference/map/map/count/
		Searches the container for elements with a key equivalent to k and returns the number of matches.
		Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise).
		Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).
		Return value : 1 if the container contains an element whose key is equivalent to k, or zero otherwise.
		*/
		size_type count(const key_type &k) const
		{
			if (this->find(k) == this->end())
				return 0;
			return 1;
		}

		/*
		https://cplusplus.com/reference/map/map/lower_bound/
		Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
		The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false.
		If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is not less than k.
		A similar member function, upper_bound, has the same behavior as lower_bound, except in the case that the map contains an element with a key equivalent to k: In this case, lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		*/
        iterator lower_bound(const key_type &k)
        {
            iterator iter = this->begin();
            while (iter != this->end())
            {
                if (!_compare(iter->first, k))
                    break;
                iter++;
            }
    		return(iter);
        }

        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator iter = this->begin();
            while (iter != this->end())
            {
                if (!_compare(iter->first, k))
                    break;
                iter++;
            }
    		return(iter);
        }

		/*
		https://cplusplus.com/reference/map/map/upper_bound/
		Returns an iterator pointing to the first element in the container whose key is considered to go after k.
		The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.
		If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is greater than k.
		A similar member function, lower_bound, has the same behavior as upper_bound, except in the case that the map contains an element with a key equivalent to k: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		Return value : an iterator to the the first element in the container whose key is considered to go after k, or map::end if no keys are considered to go after k.
		*/
        iterator upper_bound(const key_type &k)
        {
            reverse_iterator iter = this->rbegin();
            while (iter!= this->rend())
            {
                if (!_compare(k, iter->first))
                    break;
                iter++;
            }
    		return(iter.base());
        }

        const_iterator upper_bound(const key_type &k) const
        {
            const_reverse_iterator iter = this->rbegin();
            while (iter != this->rend())
            {
                if (!_compare(k, iter->first))
                    break;
                iter++;
            }
    		return(iter.base());
        }

		/*
		https://cplusplus.com/reference/map/map/equal_range/
		Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
		Because the elements in a map container have unique keys, the range returned will contain a single element at most.
		If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).
		Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).
		*/
	    pair<const_iterator,const_iterator> equal_range(const key_type &k) const
        {
            const_iterator lower = this->lower_bound(k);
            const_iterator upper = this->upper_bound(k);
            return(ft::make_pair(lower, upper));
        }

        pair<iterator,iterator> equal_range(const key_type &k)
        {
            iterator lower = this->lower_bound(k);
            iterator upper = this->upper_bound(k);
            return(ft::make_pair(lower, upper));
        }
		
		/*
		https://cplusplus.com/reference/map/map/get_allocator/
		Returns a copy of the allocator object associated with the map.
		*/
		allocator_type get_allocator() const
		{
			return(_alloc);
		}
	};

    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key,T,Compare,Alloc> &left, const ft::map<Key,T,Compare,Alloc> &right)
    {
        typename ft::map<Key, T>::const_iterator riter = right.begin();
        typename ft::map<Key, T>::const_iterator liter = left.begin();

        if (left.size() != right.size())
            return(false);
        while (riter != right.end() && liter != left.end())
        {
            if (*riter != *liter)
                return(false);
            riter++;
            liter++;
        }
        return(true);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key,T,Compare,Alloc> &left, const ft::map<Key,T,Compare,Alloc> &right)
    {
        return(!(right == left));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key,T,Compare,Alloc> &left, const ft::map<Key,T,Compare,Alloc> &right)
    {
        return(ft::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key,T,Compare,Alloc> &left, const ft::map<Key,T,Compare,Alloc> &right)
    {
        return(!(left > right));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key,T,Compare,Alloc> &left, const ft::map<Key,T,Compare,Alloc> &right)
    {
        return(right < left);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key,T,Compare,Alloc> &left, const ft::map<Key,T,Compare,Alloc> &right)
    {
    	return(!(left < right));
    }

    template<class Key, class T, class Compare, class Alloc>
    void swap(ft::map<Key,T,Compare,Alloc> &left, ft::map<Key,T,Compare,Alloc> &right)
    {
        return(left.swap(right));
    }
}

#endif
