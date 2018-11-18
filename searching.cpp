#include<cmath>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
void linearsearch(int a[],int n,int key)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			cout<<"key element is present at index :  "<<i<<endl;
		}
	}
}
int binarysearch(int a[],int left,int right,int key)
{
	
	if(right>=left)
	{
		int mid=(left+right)/2;
		if(a[mid]==key)
		{
			cout<<"key element is present at index :  "<<mid<<endl;
		}
		if(a[mid]>key)
			return binarysearch(a,left,mid-1,key);
		if(a[mid]<key)
			return binarysearch(a,mid+1,right,key);
	}
}
int jump_search(int a[], int n, int key) 
{
    int s= sqrt(n); 
    int last= 0; 
    while (a[min(s, n)-1] < key) 
    {
        last = s; 
        s += sqrt(n); 
        if (last >= n) 
            return -1; 
	}
    while (a[last] < key) 
    { 
        last++; 
        if (last == min(s, n)) 
            return -1; 
	}
    if(a[last]==key)
	{
		return last;
	}
  
    return -1; 
}
int interpolation_search(int arr[], int n, int x) 
{
    int low = 0, high = (n - 1); 
    while (low <= high && x >= arr[low] && x <= arr[high]) 
    {
        int position = low + (((double)(high-low) / 
              (arr[high]-arr[low]))*(x - arr[low])); 
        if (arr[position] == x) 
            return position; 
        if (arr[position] < x) 
            low = position + 1; 
        else
            high = position - 1; 
    } 
    return -1; 
} 
void Searching(int a[],int n,int key,int value)
{
	switch(value)
	{
		case 1:
		cout<<"Using Linear Search Algorithm ";
		linearsearch(a,n,key);
		break;
		case 2:
		cout<<"Using Binary Search Algorithm ";
		binarysearch(a,0,n-1,key);
		break;
		case 3:
		cout<<"Using Jump Search Algorithm ";
		cout<<"key element is present at index :  "<<jump_search(a,n,key)<<endl;
		break;
		case 4:
		cout<<"Using Interpolation Search Algorithm ";
		cout<<"key element is present at index :  "<<interpolation_search(a,n,key)<<endl;
		break;
		default:
		break;
	}
}
int main()
{
	while(1)
	{

		int value;
		cout<<"Select Searching Algorithm to use (for e.g. Press 1 for Linear Search)";
		cout<<"\n1. Linear Search\n2. Binary Search\n3. Jump Search\n4. Interpolation Search\n5. Exit\n";
		cin>>value;
		if(value==5)
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
		int key;
		cout<<"enter the key to be Search :   ";
		cin>>key;
		Searching(a,n,key,value);
	}
}
