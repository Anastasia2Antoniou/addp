#include <climits> // INT_MIN
#include <iostream>
#include <random>
#include <chrono> 
#include <stdio.h>
#include<bits/stdc++.h>

#define N 1000

using namespace std;
using namespace std::chrono;

// O(n^3) (naive implementation)
int max_sub1(int a[], int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += a[k];
      }
      if (sum > max) {
        max = sum;
      }
    }
  }
  return max;
}
int max(int a, int b) { return (a > b)? a : b; } 
int max(int a, int b, int c) { return max(max(a, b), c); } 
int maxCrossingSum(int a[], int l, int m, int h) 
{  
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + a[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + a[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
    return left_sum + right_sum; 
} 
//O(n*logn)
int max_sub2(int a[], int l, int h){
 if (l == h) 
     return a[l]; 
   
   int m = (l + h)/2; 
  
   /* Return maximum of following three possible cases 
      a) Maximum subarray sum in left half 
      b) Maximum subarray sum in right half 
      c) Maximum subarray sum such that the subarray crosses the midpoint */
   return max(max_sub2(a, l, m), 
              max_sub2(a, m+1, h), 
              maxCrossingSum(a, l, m, h)); 
} 
 //O(n^2)
int max_sub3(int a[], int n)
{
    cin>>n;
    for(int i=0;i<n;i++) 
    cin>>a[i];
  
    long long max_ans;
    max_ans=a[0];
 
    for(int i=0;i<n;i++)
    {
        long long result=0;
        for(int j=i;j<n;j++)
        {
            result+=a[j];
            max_ans=max(max_ans,result);
        }
    }
    return max_ans;
}
//O(n)
int max_sub4(int a[], int n) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
int main() {
  random_device device;
  mt19937 generator(device());
  //   mt19937 generator(42); // for reproducible results
  uniform_int_distribution<int> distribution(-10000, 10000);
  int a[N];
  for (int i = 0; i < N; i++) {
    a[i] = distribution(generator);
  }
  cout << "max subarray of " << N << " values" << endl;
  auto t1 = high_resolution_clock::now(); 
  cout << "O(n^3):   " << max_sub1(a, N) << endl;
  auto t2 = high_resolution_clock::now();
  int n = sizeof(a)/sizeof(a[0]); 
  int max_sum = max_sub2(a, 0, n-1); 
  cout << "Maximum contiguous sum is %dn" << max_sum; 
  auto t3 = high_resolution_clock::now();
  cout << "O(n^2): " << max_sub3(a, N) << endl;
  auto t4 = high_resolution_clock::now();
  cout << "O(n): " << max_sub4(a, N) << endl;
  auto t5 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(t2-t1).count();
  cout << "Time elapsed: " << duration << " microseconds " << duration/1000000.0 << " seconds" << endl;
}