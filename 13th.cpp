#include<iostream>
using namespace std;
void insertion_Sort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    //printing loop
    cout<<"Sorted Array:";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={3,2,5,4,1,6,7,9};
    int size = 8;
    cout<<"Original Array:";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertion_Sort(arr,size);
    return 0;
}

// output is 
// Original Array:3 2 5 4 1 6 7 9 
// Sorted Array:1 2 3 4 5 6 7 9