#include<iostream>
#include<algorithm>

using namespace std;
void printarr(int a[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int partion(int a[],int left,int right)
{
	int key=a[left];
	int i=left,j=right;
    int temp;
	while(i<j)
	{
		while(i<j && a[j]>key) j--;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		while(i<j && a[i]<=key) i++;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}

	return  i;
}

int partion1(int a[],int left,int right)
{
	int i=left,j=right;
	int temp;
	int v=a[left];

	while(i<j)
	{
       while(a[j]>v) j--;
	   while(a[i]<=v) 
	   { 
		   if(i==j) break;	
		   i++;		  	   
	   }

	   if(i>=j) break;
       temp=a[i];
	   a[i]=a[j];
	   a[j]=temp;
	}
	a[left]=a[i];
	a[i]=v;

	return i;
}
void quicksort(int a[],int l,int r)
{
	if(l>=r)
		return;
	int i=partion1(a,l,r);
	quicksort(a,l,i-1);
	quicksort(a,i+1,r);
}


int main()
{
	int a[8]={4,2,1,5,3,7,8,6};
	int b[3]={3,1,2};

	int t[9]={1,2,3,4,0,5,8,0,8};

	quicksort(b,0,2);
    printarr(b,3);

    quicksort(a,0,7);
    printarr(a,8);

	quicksort(t,0,8);
    printarr(t,9);
	return 0;
}