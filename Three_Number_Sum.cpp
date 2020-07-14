#include <bits/stdc++.h>
using namespace std;

//O(N^2) TIME APPROACH
//O(N) SPACE
void Three_Number_Sum(int *arr,int TargetSum,int n)
{

  sort(arr,arr+n);  // O(Nlog N) time.
  int Current_Number,Current_Sum;
  int *left,*right;

  for(int i=0;i<n-2;i++)   //Outer loop to manipulate Current_Number left and right pointer.
  {
    Current_Number = arr[i];
    left = arr + (i+1);
    right = arr + (n-1);
    while(left < right)  // Inner loop to move left and right pointer according Current_Sum.
    {
      Current_Sum = Current_Number + *left + *right;
      if(Current_Sum == TargetSum)
      {
        cout<<Current_Number<<" "<<*left<<" "<<*right<<endl; // Printing Result.
        left++;right--;
      }

      if(Current_Sum > TargetSum)
        right--;
      else if(Current_Sum < TargetSum)
        left++;
    }
  }
  return;

}

int32_t main()
{

    int n;   //Taking no. of elements.
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int TargetSum;
    cin>>TargetSum;
    Three_Number_Sum(arr,TargetSum,n);

    //Deleting dynamically allocated arr
    delete []arr;

    return 0;
}
