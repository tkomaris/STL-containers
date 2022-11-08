#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iterator>

namespace ft
{
	template<class Pair>
	struct BSTNode
	{
		BSTNode* parent;
		BSTNode* left;
		BSTNode* right;
		Pair value;

		explicit BSTNode() : parent(NULL), left(NULL), right(NULL), value() {}

		explicit BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data) {}

		~BSTNode() {}

		BSTNode(const BSTNode &x) : parent(x.parent), left(x.left), right(x.right), value(x.value) {}

		BSTNode &operator=(const BSTNode &x)
		{
			if (this != &x)
			{
				parent = x.parent;
				left = x.left;
				right = x.right;
				value = x.value;
			}
			return(*this);
		}

		BSTNode *findMin(BSTNode *node)
		{
			if (!node)
				return NULL;
			while (node->left)
				node = node->left;
			return(node);
		}

		BSTNode *findMax(BSTNode *node)
		{
			if (!node)
				return NULL;
			while (node->right)
				node = node->right;
			return(node);
		}

		BSTNode *next()
		{
			BSTNode* tmp = this;

			if (tmp->right)
				return findMin(tmp->right);

			BSTNode* tmpparent = tmp->parent;

			while (tmpparent && tmp == tmpparent->right)
			{
				tmp = tmpparent;
				tmpparent = tmpparent->parent;
			}
			return(tmpparent);
		}

		BSTNode *prev()
		{
			BSTNode *tmp = this;

			if (tmp->left)
				return findMax(tmp->left);

			BSTNode* p = tmp->parent;
			while (p && tmp == p->left)
			{
				tmp = p;
				p = p->parent;
			}
			return(p);
		}
	};
	
    template <class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>
	class MapIterator
	{
	public:
    	typedef T value_type;
    	typedef Distance difference_type;
    	typedef Pointer pointer;
    	typedef Reference reference;
    	typedef Category iterator_category;

	protected:
		T *_ptr;
	
	public:

		MapIterator() : _ptr(NULL) {}

		MapIterator(const MapIterator &other)
		{
			*this = other;
		}

		MapIterator(T *ptr) : _ptr(ptr) {}

		~MapIterator() {}

		T *get_internal_pointer(void) const
		{
			return(_ptr);
		}

		MapIterator &operator=(const MapIterator &other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return(*this);
		}

		MapIterator &operator++()
		{
			_ptr = _ptr->next();
			return(*this);
		}

		MapIterator &operator--()
		{
			_ptr = _ptr->prev();
			return(*this);
		}

		MapIterator operator++(int)
		{
			MapIterator tmp = *this;
			_ptr = _ptr->next();
			return(tmp);
		}

		MapIterator operator--(int)
		{
			MapIterator tmp = *this;
			_ptr = _ptr->prev();
			return(tmp);
		}

		bool operator==(const MapIterator &other) const
		{
			return(_ptr == other._ptr);
		}

		bool operator!=(const MapIterator &other) const
		{
			return(_ptr != other._ptr);
		}

		reference operator*() const
		{
			return(_ptr->value);
		}

		pointer operator->() const
		{
			return(&_ptr->value);
		}
	};

	template <class T, class U, class MapIterator, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>
	class ConstMapIterator
	{
	public:
    	typedef T         		value_type;
    	typedef Distance  		difference_type;
    	typedef Pointer   		pointer;
    	typedef Reference 		reference;
    	typedef Category  		iterator_category;
	
	protected:
		T *_ptr;
	
	public:
		ConstMapIterator() : _ptr(NULL) {}

		ConstMapIterator(const ConstMapIterator &other)
		{
			*this = other;
		}

		ConstMapIterator(T* ptr) : _ptr(ptr) {}

		ConstMapIterator(const MapIterator &other)
		{
			_ptr = other.get_internal_pointer();
		}

		~ConstMapIterator() {}

		T *get_internal_pointer() const
		{
			return(_ptr);
		}

		ConstMapIterator &operator=(const ConstMapIterator &other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return(*this);
		}

		ConstMapIterator &operator++()
		{
			_ptr = _ptr->next();
			return(*this);
		}

		ConstMapIterator &operator--()
		{
			_ptr = _ptr->prev();
			return (*this);
		}

		ConstMapIterator operator++(int)
		{
			ConstMapIterator tmp = *this;
			_ptr = _ptr->next();
			return(tmp);
		}

		ConstMapIterator operator--(int)
		{
			ConstMapIterator tmp = *this;
			_ptr = _ptr->prev();
			return(tmp);
		}

		bool operator==(const ConstMapIterator &other) const
		{
			return(_ptr == other._ptr);
		}

		bool operator!=(const ConstMapIterator &other) const
		{
			return(_ptr != other._ptr);
		}

		const reference operator*() const
		{
			return(_ptr->value);
		}

		const pointer operator->() const
		{
			return(&_ptr->value);
		}
	};
}

#endif
