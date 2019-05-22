#include<stdio.h>
#include<stdlib.h>

void meger(int* arr,int* temp,int left,int index,int right)
{
  int b1 = left,e1 = index;
  int b2 = index+1,e2 = right;
  int k = 0;
  //合并
  while(b1<=e1&&b2<=e2)
  {
    if(arr[b1]<arr[b2])
    {
      temp[k++] = arr[b1++];
    }
    else 
      temp[k++] = arr[b2++];
  }
  while(b1<=e1)
    temp[k++] = arr[b1++];
  while(b2<=e2)
    temp[k++] = arr[b2++];
  //放回数组
  k = 0;
  for(int i = left;i<=right;i++)
    arr[i] = temp[k++];
}

void meger_sort(int* arr,int* temp,int left,int right)
{
  if(left<right)
  {
    int index = (left+right)>>1;
    meger_sort(arr,temp,left,index);
    meger_sort(arr,temp,index+1,right);
    meger(arr,temp,left,index,right);
  }
}

int main()
{
  int arr[10] = {1,4,5,3,2,10,9,7,8,6};
  int* temp = (int*)malloc(sizeof(int)*10);
  meger_sort(arr,temp,0,9);
  free(temp);
  for(int i = 0;i<10;i++)
    printf("%d ",arr[i]);
  printf("\n");
  return 0;
}
