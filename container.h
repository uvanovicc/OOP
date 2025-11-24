#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
class container {
public:

	explicit container(size_t initial_capacity = 0);

	container(const container& other);

	container(container&& other) noexcept;

	~container();

	void push_back(int value);
	size_t size() const;
	size_t capacity() const;
	int& at(size_t index);
	const int& at(size_t index) const;
	void clear();

private:
	int* m_data;
	size_t m_size;
	size_t m_capacity;

	void reallocate(size_t new_capacity);
};

#endif