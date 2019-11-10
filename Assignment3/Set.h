#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Set
	{
	private:
		T* data;
		int size;
		int capacity;

		void Resize()
		{
			int oldCapacity = capacity;
			T* tmp = new T[oldCapacity];
			
			for(int i = 0;i < oldCapacity;i += 1)
			{
				tmp[i] = data[i];
			}

			delete[] data;
			capacity *= 2;
			data = new T[capacity];

			for(int i = 0;i < oldCapacity;i += 1)
			{
				data[i] = tmp[i];
			}
			delete[] tmp;
		}
	public:
		Set() : size(0), capacity(20) 
		{
			data = new T[capacity];
		}

		Set(const Set<T>& obj)
		{
			size = obj.size;
			capacity = obj.capacity;
			data = new T[capacity];

			for(int i = 0;i < size;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Set& operator=(const Set<T>& rhs)
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

		~Set() {delete[] data;}

		bool Contains(const T& value) const 
		{
			for(int i = 0;i < size;i += 1)
			{
				if(value == data[i])
				{
					return true;
				}
			}
			return false;
		}

		void Add(const T& value)
		{
			if(!Contains(value))
			{
				if(size == capacity)
				{
					Resize();
				}
				
				data[size] = value;
				size += 1;
			}
		}

		void Remove(const T& value)
		{
			int i = 0;
			
			while(i < size && data[i] != value)
			{
				i += 1;
			}

			if(i != size)
			{
				size -= 1;
				
				for(;i < size;i += 1)
				{
					data[i] = data[i+1];
				}
			}
		}

		bool IsEmpty() const {return (size == 0);}

		int Cardinality() const {return size;}

		friend Set<T> Intersection(const Set<T>& A,const Set<T>& B)
		{
			Set<T> R;

			if(!A.IsEmpty() && !B.IsEmpty())
			{
				int n = A.Cardinality();
				
				for(int i = 0;i < n;i += 1)
				{
					if(B.Contains(A.data[i]))
					{
						R.Add(A.data[i]);
					}
				}
			}

			return R;
		}

		friend Set<T> Union(const Set<T>& A,const Set<T>& B)
		{
			Set<T> R;

			int m = A.Cardinality(), n = B.Cardinality();

			if(m > n)
			{
				R = A;
				
				for(int i = 0;i < n;i += 1)
				{
					if(!A.Contains(B.data[i]))
					{
						R.Add(B.data[i]);
					}
				}
			}
			else
			{
				R = B;
				
				for(int i = 0;i < m;i += 1)
				{
					if(!B.Contains(A.data[i]))
					{
						R.Add(A.data[i]);
					}
				}
			}

			return R;
		}

		friend Set<T> Difference(const Set<T>& A,const Set<T>& B)
		{
			Set<T> R = A;

			if(!R.IsEmpty())
			{
				int n = B.Cardinality();
				
				for(int i = 0;i < n;i += 1)
				{
					if(A.Contains(B.data[i]))
					{
						R.Remove(B.data[i]);
					}
				}
			}

			return R;
		}

		friend bool Subset(const Set<T>& A,const Set<T>& B)
		{
			if(A.IsEmpty())
			{	
				return true;
			}
			else if(A.Cardinality() > B.Cardinality())
			{
				return false;
			}
			else
			{
				int n = A.Cardinality();
				
				for(int i = 0;i < n;i += 1)
				{
					if(!B.Contains(A.data[i]))
					{
						return false;
					}
				}
				return true;
			}
		}
				
		std::string ToString() const
		{
			std::stringstream out;
			out << "{";

			for(int i = 0;i < size;i += 1)
			{
				out << data[i];
				
				if((i + 1) != size)
				{
					out << ",";
				}
			}
			out << "}";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Set<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
