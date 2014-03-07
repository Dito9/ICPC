#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int l=5600,w=4500 ,d=2500,k=700;
int suma=12500;

int main(){
int test;
cin >> test;
int cont=0;
while(test--){
    long double l1,w1,d1,k1;
    cin >> l1>>w1>>d1>>k1;

    int l2=l1*100;
    int w2=w1*100;
    int d2=d1*100;
    int k2=k1*100;
    if ( ((l2<=l && w2<=w && d2<=d) || (l2+w2+d2<=suma))&& k2<=k ) {
        cont++;
        cout <<"1"<<endl;
    }
    else{
    cout << "0"<<endl;
    }
}
cout << cont << endl;

return 0;
}
