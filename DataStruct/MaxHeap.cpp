#include <vector>
#include <cmath>

class MaxHeap
{
private:
	std::vector<int> heap;
	void maxHeapify();

public:
	MaxHeap();
	~MaxHeap();
	void insert(int value);
	int extractMax();
	int height();
	int count();
	void print();
};

void MaxHeap::maxHeapify()
{
	int n = this->count() - 1;
	while (n > 0 && this->heap[(n - 1) / 2] < this->heap[n])
	{
		std::swap(this->heap[(n - 1) / 2], this->heap[n]);
		n = (n - 1) / 2;
	}
}

MaxHeap::MaxHeap()
{
}

MaxHeap::~MaxHeap()
{
}

void MaxHeap::insert(int value)
{
	this->heap.emplace_back(value);
	this->maxHeapify();
}

int MaxHeap::extractMax()
{
	int root = this->heap[0];

	this->heap[0] = this->heap[this->count() - 1];
	this->heap.pop_back();

	int k = 0;
	while ((2 * k + 1) < this->count())
	{
		int nextIdx = 2 * k + 1;
		if (2 * (k + 1) < this->count() && this->heap[2 * (k + 1)] > this->heap[nextIdx])
		{
			nextIdx = 2 * (k + 1);
		}

		if (this->heap[nextIdx] > this->heap[k])
		{
			std::swap(this->heap[nextIdx], this->heap[k]);
		}

		k = nextIdx;
	}

	return root;
}

int MaxHeap::height()
{
	return std::floor(log2(this->count()))+1;
}

int MaxHeap::count()
{
	return this->heap.size();
}

void MaxHeap::print()
{
	for (auto i : this->heap)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}