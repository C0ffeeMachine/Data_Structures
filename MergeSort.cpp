#include <iostream>
#include <cstdlib>
using namespace std;

void Merge(int *A,int *L,int leftCount,int *R,int rightCount)
{
	int i=0,j=0,k=0;
	while (i<leftCount && j<rightCount)
	{
		if(L[i]<R[j])
		{
			A[k]=L[i];
			i++;
			k++;
		}
		else
		{
			A[k]=R[j];
			j++;
			k++;
		}
	}
	while(i<leftCount)
	{
		A[k]=L[i];
		k++;
		i++;
	}
	while(j<rightCount)
	{
		A[k]=R[j];
		j++;
		k++;
	}
	return;
}

void MergeSort(int *A,int n)
{
	int mid,i,*L,*R;
	if(n<2)return;
	mid=n/2;
	/*L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int));*/
	L=new int(mid*sizeof(int));
	R=new int((n-mid)*sizeof(int));
	for(i=0;i<mid;i++)
	{
		L[i]=A[i];
	}
	for(i=mid;i<n;i++)
	{
		R[i-mid]=A[i];
	}
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,mid,R,n-mid);
	free(L);
	free(R);
	return;
}

int main()
{
	int A[]={170, 45, 75, 90, 802, 24, 2, 66};
	MergeSort(A,8);
	for(int i=0;i<8;i++)
	{
		cout<<A[i]<<" ";
	}
}
