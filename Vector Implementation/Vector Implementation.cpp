#include <iostream>
template <typename T>
class My_Vector {
public:
	My_Vector()
	{
		size = 0;
		capacity = 2;
		buffer = new int[capacity];
	}
	My_Vector(int first_element)
	{
		size = 0;
		capacity = 2;
		buffer = new int[capacity];
		buffer[0] = first_element;
	}
	
	~My_Vector()
	{
		delete[] buffer;
	}
	void push_Back(int element)
	{
		if (size == capacity)
		{
			capacity *= 2;
			T* temp_buffer = new int[capacity];
			for (int i = 0; i < size; ++i) //copy
			{
				temp_buffer[i] = buffer[i];
			}
			delete[] this->buffer; //delete old
			buffer = temp_buffer;
		}
		buffer[size++] = element;
	}
	
	void Pop_back()
	{
		--size;
	}

	private:
	int size;
	int capacity;
	T* buffer;
	
};



int main()
{

}