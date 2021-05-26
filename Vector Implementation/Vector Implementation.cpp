#include <iostream>
#include <cassert>
template <typename T>
class My_Vector {
public:
	My_Vector()
	{
		m_size = 0;
		capacity = 2;
		buffer = new T[capacity];
	}
	My_Vector(std::initializer_list<T> elem)
	{
		m_size = elem.size();
		capacity = elem.size()+2;
		buffer = new T[capacity];
		int counter = 0;
		for (auto& el : elem)
		{
			buffer[counter++] = el;
		}
	}
	My_Vector(My_Vector&& t)
	{
		capacity = t.capacity;
		m_size = t.m_size;
		buffer = t.buffer;
		t.buffer = nullptr;
		t.m_size = 0;
		t.capacity = 0;
	}
	~My_Vector()
	{
		delete[] buffer;
	}
	int& operator[](int index)
	{
		assert(index >= 0 && index < m_size);
		return buffer[index];
	}
	void push_Back(const T& element)
	{
		if (m_size == capacity)
		{
			capacity *= 2;
			T* temp_buffer = new int[capacity];
			for (int i = 0; i < m_size; ++i) //copy
			{
				temp_buffer[i] = buffer[i];
			}
			delete[] this->buffer; //delete old
			buffer = temp_buffer;
		}
		buffer[m_size++] = element;
	}
	
	void Pop_back()
	{
		--m_size;
	}
	int size() const
	{
		return m_size;
	}
	private:
	int m_size;
	int capacity;
	T* buffer;
	
};



int main()
{
	My_Vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 9 };
	std::cout << vec[99];
}