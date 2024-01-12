#include<iostream>
using namespace std;
void Selection_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int Min_index = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[Min_index])
            {
            Min_index = j;
            }
        }
         swap(arr[Min_index], arr[i]);
    }
   cout<<"After sorting our element is :"<<endl;
    for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}



int main()
{
    int n;
    cout<<"enter the array size :";
    cin>>n;
    int arr[n];
    cout<<"Enter the array element :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Selection_sort(arr,n);
    return 0;
}

// output is 

// enter the array size :5
// Enter the array element :
// 1
// 3
// 6
// 2 
// 6
// After sorting our element is :
// 1 2 3 6 6 