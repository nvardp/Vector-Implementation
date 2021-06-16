#pragma once
#include <iostream>
#include <cassert>
template <typename T>
class My_Vector {
public:
	My_Vector()
	{
		m_size = 0;
		m_capacity = 2;
		m_buffer = new T[m_capacity];
	}
	My_Vector(std::initializer_list<T> elem)
	{
		m_size = elem.size();
		m_capacity = elem.size() + 2;
		m_buffer = new T[m_capacity];
		int counter = 0;
		for (auto& el : elem)
		{
			m_buffer[counter++] = el;
		}
	}
	My_Vector(My_Vector&& t) noexcept {
		m_capacity = t.capacity;
		m_size = t.m_size;
		m_buffer = t.buffer;
		t.buffer = nullptr;
		t.m_size = 0;
		t.capacity = 0;
	}
	~My_Vector() noexcept {
		delete[] m_buffer;
	}
	T& operator[](int index) {
		assert(index >= 0 && index < m_size);
		return m_buffer[index];
	}

public:
	void push_back(const T& element) {
		if (m_size == m_capacity)
		{
			m_capacity *= 2;
			T* temp_buffer = new int[m_capacity];
			for (int i = 0; i < m_size; ++i) //copy
			{
				temp_buffer[i] = m_buffer[i];
			}
			delete[] this->buffer; //delete old
			m_buffer = temp_buffer;
		}
		m_buffer[m_size++] = element;
	}
	void pop_back() noexcept {
		--m_size;
	}
	int size() const {
		return m_size;
	}

private:
	int m_size;
	int m_capacity;
	T* m_buffer;
};
