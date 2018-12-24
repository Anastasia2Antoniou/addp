#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <set>
#include <iterator>
#include <unordered_set>
#include <bits/stdc++.h> 

#define N 10000

using namespace std;
using namespace std::chrono;



 void printFilter(int A[N], int n)
    {
         unordered_set<int> intSet;
         unordered_set<int> filter;
        for(int i=0; i<n;i++)
        {
             if(intSet.find(A[i]) == intSet.end())
                intSet.insert(A[i]);
                else
                filter.insert(A[i]);
        }
         cout << "Filter item are : ";
         unordered_set<int> :: iterator itr;
         for(itr = filter.begin(); itr !=filter.end();itr++)
         cout << *itr << " ";
    }


int main(){
    long seed = time(NULL);
    mt19937 mt(seed);
    uniform_int_distribution<int> dist(0,100000);
    int A[N];
    for(int i=0;i<N;i++){
        A[i] =  dist(mt);
        // cout << A[i] << endl;
    }
    
    auto t1 = high_resolution_clock::now();
    vector<int> v;
    for(int i=0;i<N;i++){
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
     
     set<int, greater <int> > s;
     s.insert(100);
     s.insert(250);
     s.insert(400);
     s.insert(800);
     s.insert(1500);
     s.insert(4000);
     s.insert(5000);

     set<int, greater <int> > :: iterator itr;
     cout << "\nThe set s is : ";
     for(itr = s.begin(); itr !=s.end();itr++)
     {
         cout << '\t' << *itr;
     }
     cout <<endl;

    
        int c=0;
        for(int i=0;i<10000000;i++){
          int x = dist(mt);
          bool f =  binary_search(v.begin(), v.end(), x);
           if (!f)    
              c++;
        }
    cout << "Items not found " << c << endl;
    auto t2 = high_resolution_clock::now();
    cout << "Elapsed time " << (t2-t1).count() / 1E9 << endl; 
    cout << " -----------------------" << endl;;
    auto t3 = high_resolution_clock::now();
    cout << "Elapsed time " << (t3-t1).count() / 1E9 << endl;
    cout << "************************" << endl;
    int n = sizeof(A) / sizeof(int);
    auto t4 = high_resolution_clock::now();
    cout << "Elapsed time " << (t4-t1).count() / 1E9 << endl;
    return 0;
} 