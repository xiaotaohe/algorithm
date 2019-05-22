#include<iostream>
#include<vector>
using namespace std;

void AdjustDown(vector<int>& v,int parent,int size)
{
  int child = parent*2+1;
  while(child<size)
  {
    if(child+1<size && v[child+1]>v[child])
      child++;
    if(v[child]>v[parent])
    {
      swap(v[child],v[parent]);
      parent = child;
      child = parent*2+1;
    }
    else 
      break;
  }
}
void heap_sort(vector<int>& v)
{
  //1.建堆,从第一个非叶子节点开始向下调整
  for(int i = (v.size()-2)/2;i>=0;i--)
    AdjustDown(v,i,v.size());
  //2.排序
  for(int i = v.size()-1;i>0;i--)
  {
    swap(v[i],v[0]);
    AdjustDown(v,0,i);
  }
}
int main()
{
  vector<int> v{1,5,6,10,9,8,3,4,7,5};
  heap_sort(v);
  for(auto a : v)
    cout<<a<<" ";
  cout<<endl;
}
