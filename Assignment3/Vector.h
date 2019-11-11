#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Vector
	{
	private:
		T* data;
		int size;
		int capacity;

		void Resize(int value) 
		{
			if(value > 0)
			{
				int minimum = (capacity < value)?(capacity):(value);
				T* tmp = new T[minimum];

				for(int i = 0;i < minimum;i += 1)
				{
					tmp[i] = data[i];
				}

				delete[] data;
				capacity = value;
				data = new T[capacity];

				for(int i = 0;i < minimum;i += 1)
				{
					data[i] = tmp[i];
				}

				delete[] tmp;
			}
		}
	public:
		Vector() : Vector(10) {}
	
		Vector(int n) : capacity(n), size(0)
		{
			if(capacity <= 0)
			{
				capacity = 0;
			}
			
			data = new T[capacity];
		}
	
		Vector(const Vector<T>& obj)
		{
			size = obj.size;
			capacity = obj.capacity;
			data = new T[capacity];

			for(int i = 0;i < size;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Vector<T>& operator=(const Vector<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(int i = 0;i < size;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}

			return *this;
		}

		~Vector() {delete[] data;}

		int Length() const {return size;}

		int Capacity() const {return capacity;}

		bool IsEmpty() const {return size == 0;}

		void Clear() {return size = 0;}

		T& operator[](int index) 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		const T& operator[](int index) const 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		T& At(int index) 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		const T& At(int index) const 
		{
			if(index >= 0 && index < size)
			{
				return data[index];
			}
			throw "Out Of Bound";
		}

		void Insert(const T& value)
		{
			if(size == capacity)
			{
				Resize(capacity * 2);
			}
			
			data[size] = value;
			size += 1;
		}

		void Remove()
		{
			if(size > 0)
			{
				size -= 1;
			}
		}

		void Optimize()
		{
			Resize(size);
		}

		void SetSize(int value)
		{
			if(value > 0)
			{
				if(value > capacity)
				{
					Resize(value);
				}
				size = value;
			}
		}

		void Fill(const T& value,int n)
		{
			if(n > 0)
			{
				SetSize(n);
				for(int i = 0;i < size;i += 1)
				{
					data[i] = value;
				}
			}
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(int i = 0;i < size;i += 1)
			{
				out << data[i];

				if(i + 1 < size)
				{
					out << ",";
				}
			}

			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
