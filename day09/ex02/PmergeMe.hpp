#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe & operator=(PmergeMe const & rhs);

	void SetArgs(int argc, char **argv);
	void Compute();
	
private:
	std::vector<unsigned int> _vect;
	std::list<unsigned int> _list;
};

template <typename T> void MergeSort(T &container);