#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *s,int *t)
{
	int temp;
	temp=*s;
	*s=*t;
	*t=temp;
}
int find_max(int a[],int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(max<=a[i])
			max=a[i];
	}
	return max;
}
void bubblesort(int a[],int n)
{
	bool swapped;
	for(int i=0;i<n;i++)
	{
		swapped=false;
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
		{
			break;
		}
	}

}
void selectionsort(int a[],int n)
{
	int min_index;
	for(int i=0;i<n-1;i++)
	{
		min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[min_index]>a[j])
			{
				min_index=j;
			}
		}
		swap(&a[min_index],&a[i]);
	}
}
void insertionsort(int a[],int n)
{
	int k,j;
	for(int i=1;i<n;i++)
	{
		k=a[i];
		j=i-1;
		for(j=i-1;j>=0 && a[j]>k ;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=k;
	}
}
void merge(int a[],int left,int mid,int right)  // function for merging the sorted array using merge sort algorithm
{
	int i,j,k;
	int nl,nr;   //size of left and right array
	nl= mid-left+1;
	nr=right-mid;

	int L[nl],R[nr];
	for(i=0;i<nl;i++)
	{
		L[i]=a[left+i];
	}
	for(j=0;j<nr;j++)
	{
		R[j]=a[mid+1+j];
	}

	i=0,j=0,k=left;
	while(i<nl && j <nr)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		a[k]=R[j];
		j++;
		k++;
	}

}
void mergesort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid = (right+left)/2;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);

	}
}
int make_partition(int a[],int low,int high)
{
	int pivot = a[high];
	int i= (low-1);
	for(int j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return(i+1);
}
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int p;
		p=make_partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
}
void make_heap(int a[],int n,int i)
{
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left] > a[max])
	{
		max=left;
	}
	if(right<n && a[right] > a[max])
	{
		max=right;
	}

	if(max!=i)
	{
		swap(&a[i],&a[max]);
		make_heap(a,n,max);
	}
}
void heapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		make_heap(a,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);
		make_heap(a,i,0);
	}
	
}
void countsort(int a[],int n,int exp)
{
	int new_array[n];
	int i,count_array[10]={0};
	for(i=0;i<n;i++)
	{
		count_array[(a[i]/exp)%10]++;
	}

	for(i=1;i<10;i++)
	{
		count_array[i]+=count_array[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		new_array[count_array[(a[i]/exp)%10]-1] = a[i];
		count_array[(a[i]/exp)%10]--;
	}
	for (i=0;i<n;i++)
        a[i]=new_array[i];
}
void radixsort(int a[],int n)
{
	int max;
	max=find_max(a,n);
	for(int exp=1;max/exp>0;exp*=10)
	{
		countsort(a,n,exp);
	}

}
void sorting(int a[],int n,int value)
{
	switch(value)
	{
		case 1:
		cout<<"Using Bubble Sort Algorithm ";
		bubblesort(a,n);
		break;

		case 2:
		cout<<"Using Selection Sort Algorithm ";
		selectionsort(a,n);
		break;

		case 3:
		cout<<"Using Insertion Sort Algorithm ";
		insertionsort(a,n);
		break;
		case 4:
		cout<<"Using Merge Sort Algorithm ";
		mergesort(a,0,n-1);
		case 5:
		cout<<"Using Quick Sort Algorithm";
		quicksort(a,0,n-1);
		case 6:
		cout<<"Using Heap Sort Algorithm";
		heapsort(a,n);
		case 7:
		cout<<"Using Radix Sort Algorithm";
		radixsort(a,n);
		default:
		break;
	}
}
int main()
{
	while(1)
	{

		int value;
		cout<<"Select Sorting Algorithm to use (for e.g. Press 1 for Bubble Sort";
		cout<<"\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7. Radix Sort\n8. Exit\n";
		cin>>value;
		if(value==8)
		{
			exit(1);
		}
		cout<<"Enter Size Of Array:- ";
		int n;
		cin>>n;
		int a[n];
		cout<<"Enter the Elements of Array:-   ";
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sorting(a,n,value);
		cout<<" sorted Array is:-\t";
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<"  ";
		}
	}
}
