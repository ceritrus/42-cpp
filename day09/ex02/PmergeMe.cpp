#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	SetArgs(argc, argv);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_vect = src._vect;
		this->_list = src._list;
	}
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_vect = src._vect;
		this->_list = src._list;
	}
	return *this;
}

void PmergeMe::SetArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Invalid arguments");
	for (int i = 1; i < argc; i++)
	{
		if (atoi(argv[i]) < 0)
			throw std::invalid_argument("Invalid arguments");
		_vect.push_back(atoi(argv[i]));
		_list.push_back(atoi(argv[i]));
	}
}

void PmergeMe::Compute()
{

	// Print before
	std::cout << "Before: ";
	if (_vect.size() < 6)
	{
		for (std::vector<unsigned int>::iterator it = _vect.begin(); it != _vect.end(); it++)
			std::cout << *it << " ";
	}
	else
	{
		for (std::vector<unsigned int>::iterator it = _vect.begin(); it != _vect.begin() + 5; it++)
			std::cout << *it << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;

	// Sort vector and note time
	clock_t stopwatch = clock();
	MergeSort(_vect);
	clock_t timea = clock() - stopwatch;

	// Sort list and note time
	stopwatch = clock();
	MergeSort(_list);
	clock_t timeb = clock() - stopwatch;

	// Print after
	std::cout << "After: ";
	if (_vect.size() < 6)
	{
		for (std::vector<unsigned int>::iterator it = _vect.begin(); it != _vect.end(); it++)
			std::cout << *it << " ";
	}
	else
	{
		for (std::vector<unsigned int>::iterator it = _vect.begin(); it != _vect.begin() + 5; it++)
			std::cout << *it << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;

	// Print time
	float clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector : " << (float)timea / clocks_per_ms << " ms" << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << (float)timeb / clocks_per_ms << " ms" << std::endl;
}

template <typename T> void MergeSort(T &container)
{
	// If container is empty or has only one element, it is sorted
	if (container.size() <= 1)
		return;

	// Split container into two halves
	typename T::iterator middle = container.begin();
	std::advance(middle, container.size() / 2);
	T left(container.begin(), middle);
	T right(middle, container.end());

	// Sort the two halves recursively
	MergeSort(left);
	MergeSort(right);

	// Merge the two sorted halves
	container.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(container));
}
