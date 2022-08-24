#pragma once
#include <iterator>
#include <cstddef>
used namespase std;

const int SIZE = 10;

class myContainer
{
private:

	int m_data[SIZE];
public:
	class Iterator {
	public:
		using iterator_category = forward_iterator_tag;
		using difference_type = ptrdiff_t;

		Iterator(int* ptr)
			: m_ptr(ptr) {}


		int& operator*() const { return *m_ptr; }
		int* operator->() { return m_ptr; }
		Iterator& operator++() {
			m_ptr++;
			return *this;
		}
		Iterator& operator++(int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}
		friend bool operator!=(const Iterator& a, const Iterator& b) { return (a.m_ptr != b.m_ptr); }
		friend bool operator==(const Iterator& a, const Iterator& b) { return (a.m_ptr == b.m_ptr); }


	private:
		int* m_ptr;
	};

	Iterator begin() { return Iterator(&m_data[0]); }
	Iterator end() { return Iterator(&m_data[SIZE]); }
};

