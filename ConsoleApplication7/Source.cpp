#include <iostream>
using namespace std;
void Quicksort(int *array, int start, int end)
{
	int pivot1 = array[start], pivot2 = array[end];
	if (end > start)
	{
		if (pivot1 > pivot2)
		{
			swap(array[start], array[end]);
			pivot1 = array[start];
			pivot2 = array[end];
		}
		int i = start + 1, j = end - 1, k = i;
		while (k <= j)
		{
			if (array[k] < pivot1)
			{
				swap(array[k], array[i]);
				i++;
			}
			else if (array[k] >= pivot2)
			{
				while (array[j] > pivot2 && k < j)
					j--;
				swap(array[k], array[j]);
				j--;
				if (array[k] < pivot1)
				{
					swap(array[k], array[i]);
					i++;
				}
			}
			k++;
		}
		
		j++;
		i--;
		swap(array[start], array[i]);
		swap(array[end], array[j]);
		Quicksort(array, start, i - 1);
		Quicksort(array, i + 1, j - 1);
		Quicksort(array, j + 1, end);
	}
}
void partial(int* array, int start, int end)
{
	if (start < end)
	{
		int pivot_ndex = partition(array, start, end);
		Quicksort(array, start, pivot_ndex - 1);
		Quicksort(array, pivot_ndex + 1, end);
	}
}

int partition(int* array, int start, int end)
{
	int pivot_ndex = start;
	int pivot1 = array[end];
	for (int i = start; i < end; i++)
	{
		if (array[i] <= pivot1)
		{
			swap(array[i], array[pivot_ndex]);
			pivot_ndex++;
		}
	}
	swap(array[pivot_ndex], array[end]);
	return pivot_ndex;
}



int main()
{
	int size;
	int *array = (int*)malloc(size * sizeof(int));
	
	cout << "enter the array length" << endl;
	cin >> size;
	
	for (int i = 0; i < size; i++)
	{
		cout << "Element number " << i + 1 <<" of the array\n";
		cin >> array[i];
	}
	cout << "1- For dual pivot Quick sort " << endl;
	cout << "2- For partial Quick sort " << endl;
	char c;
	cin >> c;
	switch (c)
	{
	case 1:
		Quicksort(array, 0, size - 1);
		cout << "sorted array : \n";
		for (int i = 0; i < size; i++)
		{
			cout << array[i]<<"		";
		}
		cout << endl;
		break;
	case 2:
		int starts, ends;
		cout << "Please Enter You Start and end\n";
		cout << "Start index  is " << endl;
		cin >> starts;
		cout << "End index  is " << endl;
		cin >> ends;
		partial(array, starts, ends - 1);
		cout << "partial Quicksorted array\n";
		for (int i = starts; i < ends; i++)
		{
			cout << array[i]<<"		";
		}
		cout << endl;
		break;
	}
	
	return 0;
}