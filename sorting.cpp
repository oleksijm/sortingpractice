#include <iostream>
#include <cstdlib>

//version as at 28.11.2023
//source - https://www.simplilearn.com/tutorials/cpp-tutorial/sorting-in-cpp
//quicksort

#define MAX 100

int main()
{
	int n;
	int arr[MAX];
	void Quick(int arr[], int start, int end);
	int divide(int arr[], int start, int end);



	std::cout << "Enter a number N: " << std::endl;
	std::cin >> n;

	//input values in the array

	for (int i = 0; i < n; i++)
	{

		arr[i] = rand();
	}

	//output array - unsorted

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;

	}

	Quick(arr,0, (n - 1));

	std::cout << "After sorting the elements: " << std::endl;

	for(int i=0; i<n; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}

int divide(int arr[], int start, int end) {
	int pivot = arr[end];
	int index = start;

	for (int i = start; i < end; i++)
	{
		if (arr[i] < pivot)
		{
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	int temp = arr[end];
	arr[end] = arr[index];
	arr[index] = temp;

	return index;


}

void Quick(int arr[], int start, int end)
{
	if (start < end)
	{
		int d = divide(arr, start, end);
		Quick(arr, start, (d - 1));
		Quick(arr, (d + 1), end);
	}
}
