#include <iostream>
#include <cmath>
using namespace std;
int maxsum(int arr[], int size);
int fact(int num);
int main()
{
	int size = 6;
	int arr[] = { 4,-5,10,0,-3,4 };
	cout << maxsum(arr, size);
	
}
int fact(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		return num + fact(num - 1);
	}


}
int maxsum(int arr[], int size)
{
	int index = 0;
	int* sums = new int[fact(size)];
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (i == j)
			{
				sums[index] = arr[i];
			}
			else
			{
				sums[index] = arr[i] + arr[j];
			}
			index++;
		}
	}
	int temp = 0;
	for (int i = fact(size); i < fact(size) + size; i++)
	{
		sums[i] = arr[temp];
		temp++;
	}

	int x=sums[0];
	for (int i = 0; i < fact(size); i++)
	{
		if (sums[i] > x)
		{
			x = sums[i];
		}
	}
	return x;

	delete[] sums;

}