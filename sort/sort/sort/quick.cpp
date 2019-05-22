#include<iostream>
#include<vector>
using namespace std;

int partion(vector<int>& v,int left,int right)
{
  int begin = left;
  int end = right;
  int temp = v[right];
  while(begin<end)
  {
    while(begin<end && v[begin]<= temp)
      begin++;
    while(begin<end && v[end]>=temp)
      end--;
    swap(v[begin],v[end]);
  }
  swap(v[right],v[begin]);
  return begin;
}
void quick_sort(vector<int>& v,int left,int right)
{
  if(left<right)
  {
    int index = partion(v,left,right);
    quick_sort(v,left,index-1);
    quick_sort(v,index+1,right);
  }
}
int main()
{
  vector<int> v{1,4,9,8,7,10,6,5,3,2};
  quick_sort(v,0,9);
  for(auto a : v)
    cout<<a<<" ";
  cout<<endl;
  return 0;
}

