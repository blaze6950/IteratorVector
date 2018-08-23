#pragma once

#include <iostream>
#include <initializer_list>
#include <algorithm>
using std::cout;
using std::endl;
using std::ostream;
using std::initializer_list;


template<typename T>
class vector
{
	T* p = nullptr;
	size_t size = 0;

	void copy(const vector& src);

	/*friend ostream& operator<< <T>(ostream& stream, const vector<T>& v)
	{
		stream << "vector" << endl;
		return stream;
	}*/
	
public:
	vector(){}
	vector(const vector& src);

	explicit vector(int size)
	{
		this->size = size;
		p = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			p[i] = 0;
		}
	}

	vector(const initializer_list<T>& list)
	{		
		size = list.size();
		p = new T[size];		
		int i = 0;
		
		/*
		const T* cur = list.begin();		
		while (cur != list.end())
		{
			p[i] = *cur;
			i++;
			cur++;
		}*/

		for (auto& item : list)
		{
			p[i] = item;
			i++;
		}
	}

	~vector()
	{
		delete[] p;
	}

	vector& operator=(const vector& src);
	T& operator[](int index)
	{
		return p[index];
	}

	size_t getSize(){ return size; }

	void add(T value);



	class iterator : public std::iterator<std::forward_iterator_tag, T>
	{
		T* _p;
		int _size;
		int _count = 0;
	public:
		iterator()
		{
			_p = nullptr;
			_size = 0;
		}

		iterator(T* p, int size)
		{
			_p = p;
			_size = size;
		}

		iterator& operator++ ()
		{
			_count++;
			if (_count == _size)
				_p = nullptr;
			else
			{ 
				_p++;				
			}
			
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			_count++;
			if (_count == _size)
				_p = nullptr;
			else
			{
				_p++;
				
			}
			return tmp;
		}

		T& operator* ()
		{
			return *_p;
		}

		bool operator != (iterator& it)
		{
			return _p != it._p;
		}

		bool operator == (iterator& it)
		{
			return _p == it._p;
		}

	};

	iterator begin()
	{
		return iterator(p, size);
	}

	iterator end()
	{
		return iterator();
	}
	
};




template<typename T>
void vector<T>::copy(const vector& src)
{
	size = src.size;
	p = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		p[i] = src.p[i];
	}
}

template<typename T>
vector<T>::vector(const vector<T>& src)
{
	copy(src);
}

template<typename T>
vector<T>& vector<T>::operator=(const vector& src)
{
	if (this != &src)
	{
		delete[] p;
		copy(src);
	}

	return *this;
}

template<typename T>
void vector<T>::add(T value)
{
	T* tmp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = p[i];
	}

	tmp[size] = value;

	delete[] p;
	p = tmp;
	size++;
}