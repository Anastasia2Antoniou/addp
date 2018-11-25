#include <iostream>
#include<set>

using namespace std;

int main(){
    int a, b;
    string city;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        set<string>aset;
        for(int j=0;j<b;j++){
            cin>>city;
            aset.insert(city);
        }
        cout<<aset.size()<<endl;
    }
}