// Time = O(log N) for both updation and queries;
// Space = O(N)  

#include <bits/stdc++.h>
using namespace std;

void buildtree(int *arr,int *tree,int start,int end,int node)
{

  if(start == end)
  {
    tree[node] = arr[start];
    return;
  }
  int mid = (start+end)/2;
  buildtree(arr,tree,start,mid,2*node);
  buildtree(arr,tree,mid+1,end,2*node+1);

  tree[node] = tree[2*node] + tree[2*node + 1];
}

void updatetree(int *arr,int *tree,int start,int end,int node,int idx,int value)
{
  if(start == end)
  {
    arr[idx] = value;
    tree[node] = value;
    return;
  }
  int mid = (start+end)/2;
  if(idx > mid)
  {
    updatetree(arr,tree,mid+1,end,2*node+1,idx,value);
  }
  else
  {
    updatetree(arr,tree,start,mid,2*node,idx,value);
  }
  tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int *tree,int start,int end,int node,int left,int right)
{
  //completely outside
  if(start > right || end < left)
    return 0;

  //completely inside
  if(start >= left && end <= right)
    return tree[node];

  //partially inside
  int mid = (start+end)/2;
  int ans1 = query(tree,start,mid,2*node,left,right);
  int ans2 = query(tree,mid+1,end,2*node+1,left,right);
  return ans1+ans2;

}

int32_t main()
{
    
    int arr[] = {1,2,3,4,5};

    int *tree = new int[10];

    buildtree(arr,tree,0,4,1); //Building Segment Tree
    for(int i=1;i<10;i++) //prints Segment Tree
      cout<<tree[i]<<" ";
    cout<<endl;

    updatetree(arr,tree,0,4,1,2,10); //Update Tree from arr[2] = 2 to arr[2] = 10
    for(int i=1;i<10;i++) //prints Segment Tree after update.
      cout<<tree[i]<<" ";
    cout<<endl;

    int ans = query(tree,0,4,1,2,4); //Get the Sum from interval arr(2,4).
    cout<<ans<<endl;  //prints 19 sum(arr(2,4))
  
    return 0;    
    
}
