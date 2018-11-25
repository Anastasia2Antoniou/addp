#include <iostream>
using namespace std;

int main(){
    int a, r, i;
   cin>>a>>i;
    r = a * i;
    while((double)r/(double)a > i-1){
        r--;
    }
    cout<<r+1;
}