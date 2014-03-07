#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int a[1400];

bool cont(int n){
    while(n){
        int m=n%10;
        if (m==7) return true;
        n/=10;
    }
    return false;
}

bool ev(int i){
    if (i%7==0) return true;
    if (cont(i)) return true;
    return false;
}

void pre(){
    int aum=1;
    int act=0;
    for (int i=1;i<1339;i++){

        a[i]=act+aum;
        act+=aum;
        if (ev(i)) aum*=-1;

        if(a[i]<1) {
            a[i]=1337;
            act=1337;
        }
        if(a[i]>1337){
            a[i]=1;
            act=1;
        }
    }
}

int main(){

    pre();
    //for(int i=0;i<10;i++) cout<<ev(i)<<endl;
    cout<<a[7]<<endl;
    int n,m;
    cin>>n;
    while(n--) {
        cin>>m;
        cout<<a[m]<<endl;
    }
}
