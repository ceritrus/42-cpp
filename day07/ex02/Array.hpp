#pragma once
#include <iostream>

template <typename Type>
class Array
{
private:
	Type *_array;
	unsigned int _size;
public:
	Array();
	Array(unsigned int size);
	Array(const Array & copy);
	Array(Type *array, unsigned int size);
	~Array();

	unsigned int size() const;

	Array & operator=(const Array & rhs);
	Type & operator[](int index);
	Type & operator[](unsigned int index);

	class ConstructorException : public std::runtime_error
    {
    public:
        ConstructorException(std::string message) : std::runtime_error(message) {};
    };
	class IndexTooHighException : public std::runtime_error
    {
    public:
        IndexTooHighException(std::string message) : std::runtime_error(message) {};
    };
	class IndexTooLowException : public std::runtime_error
    {
    public:
        IndexTooLowException(std::string message) : std::runtime_error(message) {};
    };
};

template <typename Type> Array<Type>::Array() : _size(0)
{
	#ifdef DEBUG
		std::cout << "\033[33m[Array]\033[0m default constructor called" << std::endl;
	#endif
	this->_array = new Type[0];
}

template <typename Type> Array<Type>::Array(unsigned int size) : _size(size)
{
	#ifdef DEBUG
		std::cout << "\033[33m[Array]\033[0m constructor called with size " << size << std::endl;
	#endif
	if (size < 0)
		throw ConstructorException("\033[31m[Array]\033[0m size cannot be less than zero");
	else
		this->_array = new Type[size];
}

template <typename Type> Array<Type>::Array(const Array & copy) : _size(copy.size())
{
	#ifdef DEBUG
		std::cout << "\033[33m[Array]\033[0m copy constructor called" << std::endl;
	#endif
	this->_array = new Type[size()];
	for (unsigned int i = 0; i < this->size(); i++)
		this->_array[i] = copy._array[i];
}

template <typename Type> Array<Type>::Array(Type *array, unsigned int size) : _size(size)
{
	#ifdef DEBUG
		std::cout << "\033[33m[Array]\033[0m constructor called with size " << size << " and array" << std::endl;
	#endif
	if (size < 0)
		throw ConstructorException("\033[31m[Array]\033[0m size cannot be less than zero");
	else
		this->_array = new Type[size];
	if (array == NULL)
		throw ConstructorException("\033[31m[Array]\033[0m original array cannot be null");
	else
		for (unsigned int i = 0; i < this->size(); i++)
			this->_array[i] = array[i];
}

template <typename Type> Array<Type>::~Array()
{
	#ifdef DEBUG
		std::cout << "\033[33m[Array]\033[0m destructor called" << std::endl;
	#endif
	delete[] this->_array;
}

template <typename Type> unsigned int Array<Type>::size() const
{
	return this->_size;
}

template <typename Type> Array<Type> & Array<Type>::operator=(const Array<Type> & rhs)
{
	size() = rhs.size();
	this->_array = new Type[size()];
	for (unsigned int i = 0; i <this->size; i++)
		this->_array[i] = rhs._array[i];
	return this;
}

template <typename Type> Type & Array<Type>::operator[](int index)
{
	if (index < 0)
		throw IndexTooLowException("\033[31m[Array]\033[0m index cannot be less than zero");
	else if (static_cast<unsigned int>(index) >= this->size())
		throw IndexTooHighException("\033[31m[Array]\033[0m index cannot be more than or equal to the size of the array");
	else
		return this->_array[index];
}

template <typename Type> Type & Array<Type>::operator[](unsigned int index)
{
	if (index < 0)
		throw IndexTooLowException("\033[31m[Array]\033[0m index cannot be less than zero");
	else if (index >=this->size)
		throw IndexTooHighException("\033[31m[Array]\033[0m index cannot be more than or equal to the size of the array");
	else
		return this->_array[index];
}