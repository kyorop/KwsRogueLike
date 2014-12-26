#include "HeapSort.h"
#include "IDrawable.h"

void MakeHeap(std::vector<std::shared_ptr<IDrawable>>& list)
{
	size_t size = list.size();
	for (size_t i = 0; i < size; i++)
	{
		size_t i_child = i;
		size_t i_parent = abs(static_cast<int>(i)-1) / 2;
		while (list[i_parent]->GetLayer() < list[i_child]->GetLayer())
		{
			swap(list[i_parent], list[i_child]);
			i_child = i_parent;
			i_parent = abs(static_cast<int>(i_parent)-1) / 2;
		}
	}
}

void ReapairHeap(std::vector<std::shared_ptr<IDrawable>>& heap, const int i_end)
{
	int i_parent = 0;
	int i_left = 1;
	int i_rigth = 2;
	while (i_left <= i_end || i_rigth <= i_end)
	{
		if (i_rigth <= i_end)
		{
			int i_bigger = i_left;
			if (heap[i_left]->GetLayer() < heap[i_rigth]->GetLayer())
				i_bigger = i_rigth;

			if (heap[i_parent]->GetLayer() < heap[i_bigger]->GetLayer())
			{
				swap(heap[i_parent], heap[i_bigger]);
				i_parent = i_bigger;
				i_left = i_parent * 2 + 1;
				i_rigth = i_parent * 2 + 2;
			}
			else
				return;
		}
		else if (i_left <= i_end)
		{
			if (heap[i_parent]->GetLayer() < heap[i_left]->GetLayer())
			{
				swap(heap[i_parent], heap[i_left]);
			}
			else
				return;
		}
	}
}

void KwsRogueLike::Util::Image::DoHeapSort(std::vector<std::shared_ptr<IDrawable>>& heap)
{
	size_t size = heap.size();

	if (size <= 1)
		return;

	MakeHeap(heap);

	for (size_t i = size - 1; i > 0; --i)
	{
		swap(heap[0], heap[i]);
		ReapairHeap(heap, i - 1);
	}
}