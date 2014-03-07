#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
bool posible(int,int,int,int,int,int);

int f (int,int,int,int);

map <int,int>mapa;

int main(){

int n,m,i,j,a,b;
cin >> n >> m >> i >> j >> a >> b;

if (i==1 && j==m ){
cout <<"0"<<endl;
return 0;
}
if (i==n && j==1 ){
cout <<"0"<<endl;
return 0;
}
if (i==n && j==m ){
cout <<"0"<<endl;
return 0;
}
if (i==1 && j==1 ){
cout <<"0"<<endl;
return 0;
}

if (!posible(n,m,i,j,a,b)){
cout <<"Poor Inna and pony!"<<endl;
return 0;
}

int rpta=10000000;

rpta=min(rpta,  f(a,b,i-1,j-1));
         rpta=min(rpta,  f(b,a,j-1,n-i));
         rpta=min(rpta,  f(a,b,n-i,m-j));
         rpta=min(rpta,  f(b,a,m-j,i-1));

if (rpta==10000000){

cout <<"Poor Inna and pony!"<<endl;
return 0;
}
else{
cout << rpta<<endl;
return 0;
}

return 0;

}

bool posible(int n ,int m,int i,int j,int a,int b){

    if ((i+a>n and i-a<1) or (j+b>m and j-b<1)) return false;

    return true;
}
int f (int a,int b,int x,int y){

    if ( x%a==0 && y%b==0){
        int c = x/a;
        int d = y/b;

        if (c%2==d%2){

            return max(c,d);
        }

    }
    return 10000000;
}
