#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cstddef>
#include <iterator>

namespace ft
{
    template<class Iterator>
    class iterator_traits
	{
	public:
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T>
    class iterator_traits<T *>
	{
	public:
        typedef	ptrdiff_t difference_type;
        typedef	T value_type;
        typedef	T* pointer;
        typedef	T& reference;
        typedef	std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    class iterator_traits<const T *>
    {
	public:
        typedef	ptrdiff_t difference_type;
        typedef	T value_type;
        typedef	const T *pointer;
        typedef	const T &reference;
        typedef	std::random_access_iterator_tag iterator_category;
    };

	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return(false);
			else if (*first1 < *first2)
				return(true);
			++first1;
			++first2;
		}
		return(first2 != last2);
	};

	template<class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return(false);
			else if (comp(*first1, *first2))
				return(true);
			++first1;
			++first2;
		}
		return(first2 != last2);
	};

	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return(false);
			++first1;
			++first2;
		}
		return(true);
	};

	template<typename T>
	struct is_pointer
	{
		static const bool value = false;
	};

	template<typename T>
	struct is_pointer<T *>
	{
		static const bool value = true;
	};

	template<typename T>
	struct is_void
	{
		static const bool value = false;
	};

	template<>
	struct is_void<void>
	{
		static const bool value = true;
	};

	template<typename T>
	struct is_integral
	{
		static const bool value = false;
	};

	template<>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long unsigned>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<short unsigned>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long long unsigned>
	{
		static const bool value = true;
	};

	template<bool Cond, class T = void>
	struct enable_if
	{
	};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class T1, class T2>
	struct pair {

		typedef T1 first_type;
		typedef T2 second_type;

		first_type 	first;
		second_type second;

		pair(void): first(), second() {}

		pair(const first_type& a, const second_type& b): first(a), second(b) {}

		template<class U, class V>
		pair(const pair<U,V> &pr): first(pr.first), second(pr.second) {}

		pair<T1,T2> &operator = (const pair<T1,T2> &other)
		{
			if (*this == other)
				return(*this);
			this->first = other.first;
			this->second = other.second;
			return(*this);
		}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return(pair<T1,T2>(x,y));
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& left, const pair<T1,T2>& right)
	{
		return(left.first == right.first && left.second == right.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& left, const pair<T1,T2>& right)
	{
		return(!(left == right));
	}

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& left, const pair<T1,T2>& right)
	{
		return(left.first < right.first || (!(right.first < left.first) && left.second < right.second));
	}

	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& left, const pair<T1,T2>& right)
	{
		return(right < left);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& left, const pair<T1,T2>& right)
	{
		return(right > left);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& left, const pair<T1,T2>& right)
	{
		return(right < left);
	}
};

#endif
