#include <bits/stdc++.h>
using namespace std;

void heapify(int *A,int n,int i)
{
	int largest,l,r;
	largest=i;
	l=2*i+1;
	r=2*i+2;
	
	if(l<n && A[l]>A[largest])
	{
		largest=l;
	}
	
	if(r<n && A[r]>A[largest])
	{
		largest=r;
	}
	
	if(largest!=i)
	{
		swap(A[largest],A[i]);
		heapify(A,n,largest);
	}
}

void heapSort(int *A,int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(A,n,i);
	}
	
	for(int i=n-1;i>=0;i--)
	{
		swap(A[0],A[i]);
		heapify(A,i,0);
	}
}

void printArray(int *A,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}

int main()
{
	int A[]={12, 11, 13, 5, 6, 7};
	heapSort(&A[0],5);
	printArray(A,5);
	return 0;
}
