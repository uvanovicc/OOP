#include "container.h"

container::container(size_t initial_capacity)
	: m_size(0), m_capacity(initial_capacity)
{
	m_data = (m_capacity > 0) ? new int[m_capacity] : nullptr;
	std::cout << "Konstruktor: kapacitet = " << m_capacity << std::endl;
}

container::container(const container& other)
	: m_size(other.m_size), m_capacity(other.m_capacity)
{
	std::cout << "Copy konstruktor" << std::endl;
	m_data = (m_capacity > 0) ? new int[m_capacity] : nullptr;

	for (size_t i = 0; i < m_size; ++i)
		m_data[i] = other.m_data[i];
}

container::container(container&& other) noexcept
	: m_data(other.m_data), m_size(other.m_size), m_capacity(other.m_capacity)
{
	std::cout << "Move konstruktor" << std::endl;

	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

container::~container()
{
	std::cout << "Destruktor: oslobađam kapacitet " << m_capacity << std::endl;
	delete[] m_data;
}

void container::push_back(int value)
{
	if (m_size == m_capacity) {
		size_t new_cap = (m_capacity == 0) ? 1 : m_capacity * 2;
		reallocate(new_cap);
	}

	m_data[m_size++] = value;
}

void container::reallocate(size_t new_capacity)
{
	std::cout << "Realokacija: " << m_capacity << " -> " << new_capacity << std::endl;

	int* new_data = new int[new_capacity];

	for (size_t i = 0; i < m_size; ++i)
		new_data[i] = m_data[i];

	delete[] m_data;

	m_data = new_data;
	m_capacity = new_capacity;
}

size_t container::size() const { return m_size; }

size_t container::capacity() const { return m_capacity; }

int& container::at(size_t index)
{
	return m_data[index];
}
const int& container::at(size_t index) const
{
	return m_data[index];
}

void container::clear()
{
	m_size = 0;
}
