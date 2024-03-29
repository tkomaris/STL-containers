#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef	T value_type;
		typedef	Container container_type;
		typedef	std::size_t size_type;

	protected:
		container_type c;

	public:
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}

		/*
		https://cplusplus.com/reference/stack/stack/empty/
		Returns whether the stack is empty: i.e. whether its size is zero.
		This member function effectively calls member empty of the underlying container object.
		*/
		bool empty() const
		{
			return c.empty();
		}

		/*
		https://cplusplus.com/reference/stack/stack/size/
		Returns the number of elements in the stack.
		This member function effectively calls member size of the underlying container object.
		*/
		size_type size() const
		{
			return c.size();
		}
		
		/*
		https://cplusplus.com/reference/stack/stack/top/
		Returns a reference to the top element in the stack.
		Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.This member function effectively calls member back of the underlying container object.
		*/
		value_type &top()
		{
			return c.back();
		}

		const value_type &top() const
		{
			return c.back();
		}

		/*
		https://cplusplus.com/reference/stack/stack/push/
		Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.
		This member function effectively calls the member function push_back of the underlying container object.
		*/
		void push(const value_type &value)
		{
			c.push_back(value);
		}

		/*
		https://cplusplus.com/reference/stack/stack/pop/
		Removes the element on top of the stack, effectively reducing its size by one.
		The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.
		This calls the removed element's destructor.
		This member function effectively calls the member function pop_back of the underlying container object.
		*/
		void pop()
		{
			c.pop_back();
		}

		friend	bool operator==(const ft::stack<T,Container>& left, const ft::stack<T,Container>& right)
		{
			return left.c == right.c;
		}
		friend	bool operator!=(const ft::stack<T,Container>& left, const ft::stack<T,Container>& right)
		{
			return left.c != right.c;
		}
		friend	bool operator<(const ft::stack<T,Container>& left, const ft::stack<T,Container>& right)
		{
			return left.c < right.c;
		}
		friend	bool operator<=(const ft::stack<T,Container>& left, const ft::stack<T,Container>& right)
		{
			return left.c <= right.c;
		}
		friend	bool operator>(const ft::stack<T,Container>& left, const ft::stack<T,Container>& right)
		{
			return left.c > right.c;
		}
		friend	bool operator>=(const ft::stack<T,Container>& left, const ft::stack<T,Container>& right)
		{
			return left.c >= right.c;
		}
	};
}

#endif
