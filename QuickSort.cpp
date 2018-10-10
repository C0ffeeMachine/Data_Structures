#include <iostream>
using namespace std;

int partition(int *A,int start,int end)
{
	int pivot=A[end];
	int pIndex=start; //Set as start initially
	for(int i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex],A[end]);
	return pIndex;
}

void QuickSort(int *A,int start,int end)
{
	if(start<end)
	{
		int pIndex=partition(A,start,end);
		QuickSort(A,start,pIndex-1);
		QuickSort(A,pIndex,end);
	}
	return;
}

int main()
{
	int A[]={170, 45, 75, 90, 802, 24, 2, 66};
	QuickSort(A,0,7);
	for(int i=0;i<8;i++)
	{
		cout<<A[i]<<" ";
	}
}
