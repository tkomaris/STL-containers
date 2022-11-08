#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "utils.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		typedef typename ft::iterator_traits<Iterator>::pointer	pointer;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;

	private: 
		iterator_type _internal_it;

	public:
		reverse_iterator() : _internal_it(NULL) {}

		explicit reverse_iterator(iterator_type iter) : _internal_it(iter) {}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_iter) : _internal_it(rev_iter.base()) {}

		iterator_type base() const
		{
			return(iterator_type(_internal_it));
		}

		reverse_iterator &operator++()
		{
			_internal_it--;
			return(*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
  			return(tmp);
		}

		reverse_iterator &operator--()
		{
			_internal_it++;
			return(*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return(tmp);
		}

		reference operator*() const
		{
            iterator_type tmp = _internal_it;
			return(*(--tmp));
		}

		pointer operator->() const
		{
			return(&(operator*()));
		}

		reverse_iterator operator+(difference_type n) const
		{
			return(reverse_iterator<Iterator>(_internal_it - n));
		}

		reverse_iterator operator-(difference_type n) const
		{
			return(reverse_iterator<Iterator>(_internal_it + n));
		}

		reverse_iterator &operator+=(difference_type n)
		{
			_internal_it -= n;
			return(*this);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			_internal_it += n;
			return(*this);
		}

		reference operator[](difference_type n) const
		{
			return(_internal_it[-n -1]);
		}
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return(reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(right.base() - left.base());
	}

	template <class IteratorR, class IteratorL>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(right.base() - left.base());
	}

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(left.base() == right.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator==(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(left.base() == right.base());
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(left.base() != right.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator!=(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(left.base() != right.base());
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(left.base() > right.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(left.base() > right.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(left.base() >= right.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<=(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(left.base() >= right.base());
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(left.base() < right.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(left.base() < right.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right)
	{
		return(left.base() <= right.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>=(const reverse_iterator<IteratorL> &left, const reverse_iterator<IteratorR> &right)
	{
		return(left.base() <= right.base());
	}
}
#endif