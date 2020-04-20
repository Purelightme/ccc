#include <stdio.h>
 
/* 函数声明 */
double getAverage(int arr[], int size);
 
int main()
{
   /* 带有 5 个元素的整型数组 */
   int balance[3] = {3, 4, 3};
   double avg;
 
   /* 传递一个指向数组的指针作为参数 */
   avg = getAverage( balance, 3 ) ;
 
   /* 输出返回值 */
   printf( "平均值是： %f \n", avg );
    
   return 0;
}
 
double getAverage(int arr[], int size)
{
  int    i;
  double avg;
  double sum=0;
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
  }
 
  avg = sum / size;
 
  return avg;
}