#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "./utils/utils.hpp"
#include "./utils/vector_iterator.hpp"
#include "./utils/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef	T value_type;
		typedef	Alloc allocator_type;
		typedef	typename allocator_type::reference reference;
		typedef	typename allocator_type::const_reference const_reference;
		typedef	typename allocator_type::pointer pointer;
		typedef	typename allocator_type::const_pointer const_pointer;
		typedef ft::VectorIterator<value_type> iterator;
		typedef ft::VectorIterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef	typename iterator_traits<iterator>::difference_type	difference_type;
		typedef	typename std::size_t size_type;

	private:
		allocator_type _alloc;
		pointer _start;
		size_type _size;
		size_type _capacity;

	public:
		explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(0), _size(0), _capacity(0) {}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(0), _size(n), _capacity(n)
		{
			_start = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_start[i], val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type* = 0) 
			: _alloc(alloc), _start(0), _size(0), _capacity(0)
		{
			this->assign(first, last);
		}

		vector(const vector &x) : _alloc(x._alloc), _start(0), _size(x._size), _capacity(x._size)
		{
			_start = _alloc.allocate(x._size);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_start[i], x._start[i]);
		}

		~vector()
		{
			this->clear();
			_alloc.deallocate(_start, _capacity);
		}

		vector &operator=(const vector &other)
		{
			if (*this == other)
				return(*this);
			this->clear();
			_alloc.deallocate(_start, _capacity);
			_capacity = other._capacity;
			_size = other._size;
			_start = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; ++i) {
				_alloc.construct(&_start[i], other._start[i]);
			}
			return(*this);
		}
		
		/*
		https://cplusplus.com/reference/vector/vector/begin/
		Returns an iterator pointing to the first element in the vector.
		Notice that, unlike member vector::front, which returns a reference to the first element, this function returns a random access iterator pointing to it.
		If the container is empty, the returned iterator value shall not be dereferenced.
		*/
		iterator begin()
		{
			return(iterator(_start));
		}

		const_iterator begin() const
		{
			return(const_iterator(_start));
		}

		/*
		https://cplusplus.com/reference/vector/vector/end/
		Returns an iterator referring to the past-the-end element in the vector container.
		The past-the-end element is the theoretical element that would follow the last element in the vector. It does not point to any element, and thus shall not be dereferenced.
		Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with vector::begin to specify a range including all the elements in the container.
		If the container is empty, this function returns the same as vector::begin.
		*/
		iterator end()
		{
			return(iterator(_start + _size));
		}

		const_iterator end() const
		{
			return(const_iterator(_start + _size));
		}
		/*
		https://cplusplus.com/reference/vector/vector/rbegin/
		Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
		Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.
		rbegin points to the element right before the one that would be pointed to by member end.
		Notice that unlike member vector::back, which returns a reference to this same element, this function returns a reverse random access iterator.
		*/
		reverse_iterator rbegin()
		{
			return(reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin() const
		{
			return(const_reverse_iterator(this->end()));
		}

		/*
		https://cplusplus.com/reference/vector/vector/rend/
		Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
		The range between vector::rbegin and vector::rend contains all the elements of the vector (in reverse order).
		*/
		reverse_iterator rend()
		{
			return(reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend(void) const
		{
			return(const_reverse_iterator(this->begin()));
		}

		/*
		https://cplusplus.com/reference/vector/vector/size/
		Returns the number of elements in the vector.
		This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
		*/
		size_type size() const
		{
			return(_size);
		}

		/*
		https://cplusplus.com/reference/vector/vector/max_size/
		Returns the maximum number of elements that the vector can hold.
		This is the maximum potential size the container can reach due to known system or library implementation limitations, but the container is by no means guaranteed to be able to reach that size: it can still fail to allocate storage at any point before that size is reached.
		*/
		size_type max_size() const
		{
			return(_alloc.max_size());
		}

		/*
		https://cplusplus.com/reference/vector/vector/resize/
		Resizes the container so that it contains n elements.
		If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
		If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
		If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
		Notice that this function changes the actual content of the container by inserting or erasing elements from it.
		n
		New container size, expressed in number of elements.
		Member type size_type is an unsigned integral type.
		*/
		void resize(size_type n, value_type val = value_type())
		{
			size_type new_capacity;

			if (n < _size)
				while (_size != n)
					this->pop_back();
			else if (n > _size)
			{
				if (n > _capacity)
				{
					if (_capacity == 0)
						new_capacity = 1;
					else
						new_capacity = _capacity * 2;
					if (new_capacity < n)
						new_capacity = n;
					this->reserve(new_capacity);
				}
				while (_size != n)
				{
					_alloc.construct(&_start[_size], val);
					_size++;
				}
			}
		}

		/*
		https://cplusplus.com/reference/vector/vector/capacity/
		Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
		Notice that this capacity does not suppose a limit on the size of the vector. When this capacity is exhausted and more is needed, it is automatically expanded by the container (reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.
		The capacity of a vector can be explicitly altered by calling member vector::reserve.
		*/
		size_type capacity() const
		{
			return(_capacity);
		}

		/*
		https://cplusplus.com/reference/vector/vector/empty/
		Returns whether the vector is empty (i.e. whether its size is 0).
		This function does not modify the container in any way. To clear the content of a vector, see vector::clear.
		true if the container size is 0, false otherwise
		No-throw guarantee: this member function never throws exceptions.
		*/
		bool empty() const
		{
			return(size() == 0 ? true : false); 
		}

		/*
		https://cplusplus.com/reference/vector/vector/reserve/
		Requests that the vector capacity be at least enough to contain n elements.
		If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
		In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
		This function has no effect on the vector size and cannot alter its elements.
		If the size requested is greater than the maximum size (vector::max_size), a length_error exception is thrown.
		If case of reallocation, the storage is allocated using the container's allocator, which may throw exceptions on failure (for the default allocator, bad_alloc is thrown if the allocation request does not succeed).
		*/
		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (n != 0 && n > _capacity)
			{
				value_type *tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&tmp[i], _start[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_start[i]);
				_alloc.deallocate(_start, _capacity);
				_capacity = n;
				_start = tmp;
			}
		}

		/*
		https://cplusplus.com/reference/vector/vector/operator[]/
		Returns a reference to the element at position n in the vector container.
		A similar member function, vector::at, has the same behavior as this operator function, except that vector::at is bound-checked and signals if the requested position is out of range by throwing an out_of_range exception.
		Portable programs should never call this function with an argument n that is out of range, since this causes undefined behavior.
		The element at the specified position in the vector.
		If the vector object is const-qualified, the function returns a const_reference. Otherwise, it returns a reference.
		*/
		reference operator[](size_type n)
		{
			return(_start[n]);
		}

		const_reference operator[](size_type n) const
		{
			return(_start[n]);
		}

		/*
		https://cplusplus.com/reference/vector/vector/at/
		Returns a reference to the element at position n in the vector.
		The function automatically checks whether n is within the bounds of valid 
		elements in the vector, throwing an out_of_range exception if it is not (i.e., 
		if n is greater than, or equal to, its size). This is in contrast with member operator[], 
		that does not check against bounds.
		*/
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return(_start[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return(_start[n]);
		}

		/*
		https://cplusplus.com/reference/vector/vector/front/
		Returns a reference to the first element in the vector.
		Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		Calling this function on an empty container causes undefined behavior.
		Return value
		A reference to the first element in the vector container.
		If the vector object is const-qualified, the function returns a const_reference. Otherwise, it returns a reference.
		Complexity: Constant.
		If the container is not empty, the function never throws exceptions (no-throw guarantee).
		Otherwise, it causes undefined behavior.	
		*/
		reference front()
		{
			return(_start[0]);
		}

		const_reference front() const
		{
			return(_start[0]);
		}

		/*
		https://cplusplus.com/reference/vector/vector/back/
		Returns a reference to the last element in the vector.
		Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
		Calling this function on an empty container causes undefined behavior.
		If the container is not empty, the function never throws exceptions (no-throw guarantee).
		Otherwise, it causes undefined behavior.
		*/	
		reference back()
		{
			return(_start[_size - 1]);
		}
		const_reference back() const
		{
			return(_start[_size - 1]);
		}

		/*
		https://cplusplus.com/reference/vector/vector/assign/

		range (1) : template <class InputIterator>  void assign (InputIterator first, InputIterator last);
		fill (2) : void assign (size_type n, const value_type& val);
		
		In the range version (1), the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
		In the fill version (2), the new contents are n elements, each initialized to a copy of val.
		If a reallocation happens,the storage needed is allocated using the internal allocator.
		Any elements held in the container before the call are destroyed and replaced by newly constructed elements (no assignments of elements take place).
		This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		
		n
		New size for the container.
		Member type size_type is an unsigned integral type.
		val
		Value to fill the container with. Each of the n elements in the container will be initialized to a copy of this value.
		Member type value_type is the type of the elements in the container, defined in vector as an alias of its first template parameter (T).
		il
		An initializer_list object. The compiler will automatically construct such objects from initializer list declarators.
		Member type value_type is the type of the elements in the container, defined in vector as an alias of its first template parameter (T).
		*/
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type assign(InputIterator first, InputIterator last)
		{
			int range_size;
			InputIterator tmp;

			tmp = first;
			range_size = 0;
			while (tmp != last)
			{
				tmp++;
				range_size++;
			}

			if (range_size < 0)
				throw std::length_error("Vector");
			this->clear();
			this->reserve(range_size);
			for (; first != last; ++first)
				this->push_back(*first);
		}

		void assign(size_type n, const value_type &val)
		{
			this->clear();
			if (_capacity < n)
				this->reserve(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_start[i], val);
			_size = n;
		}

		/*
		https://cplusplus.com/reference/vector/vector/push_back/
		Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		val
		Value to be copied (or moved) to the new element.
		Member type value_type is the type of the elements in the container, defined in vector as an alias of its first template parameter (T).
		
		If a reallocation happens, the storage is allocated using the container's allocator, which may throw exceptions on failure (for the default allocator, bad_alloc is thrown if the allocation request does not succeed).
		*/
		void push_back(const value_type &val)
		{

			if (_capacity < _size + 1)
			{
				if (_size == 0)
					this->reserve(1);
				else
					this->reserve(_size * 2);
			}
			_alloc.construct(&_start[_size], val);
			_size++;
		}

		/*
		https://cplusplus.com/reference/vector/vector/pop_back/
		Removes the last element in the vector, effectively reducing the container size by one.
		This destroys the removed element.
		Complexity : Constant.
		Exception safety : If the container is not empty, the function never throws exceptions (no-throw guarantee).
		Otherwise, it causes undefined behavior.
		*/
		void pop_back()
		{
			_alloc.destroy(&_start[_size - 1]);
			_size--;
		}

		/*
		https://cplusplus.com/reference/vector/vector/insert/
		The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
		
		single element (1) iterator insert (iterator position, const value_type& val);
		fill (2) void insert (iterator position, size_type n, const value_type& val);
		range (3) template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

		This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		The parameters determine how many elements are inserted and to which values they are initialized:		
		*/
		iterator insert(iterator position, const value_type &val)
		{
			iterator	it;
			size_type	index;

			index = position - this->begin();
			this->insert(position, 1, val);
			return(iterator(this->begin() + index));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type	index;
			iterator	mv_dest;
			iterator	mv_source;
			size_type	new_capacity;

			if (n == 0)
				return ;
			index = position - this->begin();
			if (_size + n >= _capacity)
			{
				if (_size == 0)
					new_capacity = 1;
				else
					new_capacity = _size * 2;
				if (new_capacity < _size + n)
					new_capacity = _size + n;
				this->reserve(new_capacity);
			}
			mv_source = this->end() - 1;
			mv_dest = mv_source + n;
			while (mv_source >= this->begin() + index)
			{
				_alloc.construct(&(*mv_dest), *mv_source);
				_alloc.destroy(&(*mv_source));
				mv_source--;
				mv_dest--;
			}
			mv_source++;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(&(*(mv_source)), val);
				mv_source++;
			}
			_size += n;
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type insert(iterator position, InputIterator first, InputIterator last)
		{
			iterator tmp;
			InputIterator tmp_input_iterator;
			iterator mv_dest;
			iterator mv_source;
			size_type nb_items;
			size_type position_len;

			tmp_input_iterator = first;
			nb_items = 0;
			while (tmp_input_iterator != last)
			{
				tmp_input_iterator++;
				nb_items++;
			}
			tmp = iterator(&(*first));
			position_len = &(*position) - _start;
			if (_size + nb_items > _capacity)
				this->reserve(_size + nb_items);
			mv_source = this->end() - 1;
			mv_dest = mv_source + nb_items;
			while (mv_source >= iterator(_start + position_len))
			{
				_alloc.construct(&(*(mv_dest)), *mv_source);
				_alloc.destroy(&(*(mv_source)));
				mv_source--;
				mv_dest--;
			}
			mv_source++;
			while (first != last)
			{
				_alloc.construct(&(*(mv_source)), *first);
				mv_source++;
				first++;
			}
			_size += nb_items;
		}

		/*
		https://cplusplus.com/reference/vector/vector/erase/
		Removes from the vector either a single element (position) or a range of elements ([first,last)).
		This effectively reduces the container size by the number of elements removed, which are destroyed.
		Because vectors use an array as their underlying storage, erasing elements in positions other than the vector end causes the container to relocate all the elements after the segment erased to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		
		position
		Iterator pointing to a single element to be removed from the vector.
		Member types iterator and const_iterator are random access iterator types that point to elements.
		first, last
		Iterators specifying a range within the vector] to be removed: [first,last). i.e., the range includes all the elements between first and last, including the element pointed by first but not the one pointed by last.
		Member types iterator and const_iterator are random access iterator types that point to elements.
		
		Return value
		An iterator pointing to the new location of the element that followed the last element erased by the function call. This is the container end if the operation erased the last element in the sequence.
		Member type iterator is a random access iterator type that points to elements.
		*/
		iterator erase(iterator position)
		{
			return(this->erase(position, position + 1));
		}

		iterator erase(iterator first, iterator last)
		{
			iterator	tmp;
			size_type	i;

			if (first == last)
				return(first);
			tmp = first;
			while (tmp != last)
			{
				_alloc.destroy(&(*tmp));
				tmp++;
				_size--;
			}
			tmp = first;
			i = 0;
			while (tmp != this->end())
			{
				_alloc.construct(&(*tmp), *(last + i));
				_alloc.destroy(&(*(last + i)));
				tmp++;
				i++;
			}
			return(first);
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_start[i]);
			_size = 0;
		}

		/*
		https://cplusplus.com/reference/vector/vector/swap/
		Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
		Notice that a non-member function exists with the same name, swap, overloading that algorithm with an optimization that behaves like this member function.
		x
		Another vector container of the same type (i.e., instantiated with the same template parameters, T and Alloc) whose content is swapped with that of this container.
		Exception safety
		If the allocators in both vectors compare equal, or if their allocator traits indicate that the allocators shall propagate, the function never throws exceptions (no-throw guarantee).
		Otherwise, it causes undefined behavior.
		*/
		void swap (vector &x)
		{
			value_type *tmp_start = this->_start;
			size_type tmp_size = this->_size;
			size_type tmp_capacity = this->_capacity;
			allocator_type tmp_alloc = this->_alloc;

			this->_start = x._start;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;

			x._start = tmp_start;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
			x._alloc = tmp_alloc;
		}

		/*
		https://cplusplus.com/reference/vector/vector/get_allocator/
		Returns a copy of the allocator object associated with the vector.
		Return Value : the allocator.
		*/
		allocator_type get_allocator(void) const
		{
			return(_alloc);
		}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &left, const vector<T,Alloc> &rhs)
	{
		typename ft::vector<T>::const_iterator	liter;
		typename ft::vector<T>::const_iterator	riter;

		liter = left.begin();
		riter = rhs.begin();
		if (left.size() != rhs.size())
			return(false);
		while (liter != left.end())
		{
			if (*liter != *riter)
				return(false);
			liter++;
			riter++;
		}
		return(true);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &left, const vector<T,Alloc> &right)
	{
		return(!(left == right));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &left, const vector<T,Alloc> &right)
	{
		typename ft::vector<T>::const_iterator liter;
		typename ft::vector<T>::const_iterator riter;

		liter = left.begin();
		riter = right.begin();

		while (liter != left.end())
		{
			if (riter == right.end() || (*liter) > (*riter))
				return(false);
			else if ((*liter) < (*riter))
				return(true);
			liter++;
			riter++;
		}
		return(riter != right.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &left, const vector<T,Alloc> &right)
	{
		return(!(right < left));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &left, const vector<T,Alloc> &right)
	{
		return(right < left);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &left, const vector<T,Alloc> &right)
	{
		return(!(left < right));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc> &x, vector<T,Alloc> &y)
	{
		x.swap(y);
	}
}

#endif
