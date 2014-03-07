#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main(){

int n;
cin >> n;
int derecha,izquierda,iz,de;
vector<int> mesa;

for (int i=0;i<n;i++){
int a;
cin >> a;
mesa.push_back(a);
if (i==0){
    izquierda=a;
    iz=0;
}
if (i==(n-1)){
    derecha=a;
    de=n-1;
}

}
int sereja=0,dima=0;
for (int i=0;i<n;i++){

if (izquierda>derecha){
    if (i%2==0){
        iz++;
        sereja+=izquierda;
        if (iz>=0 && iz<n) izquierda=mesa.at(iz);
    }
    else{
        iz++;
        dima+=izquierda;
        if (iz>=0 && iz<n) izquierda=mesa.at(iz);
    }
}
else{
    if (i%2==0){

        sereja+=derecha;
        de--;
        if (de>=0 && de<n) derecha=mesa.at(de);
    }
    else{
        de--;
        dima+=derecha;
        if (de>=0 && de<n) derecha=mesa.at(de);
    }
}

}
cout << sereja << " " <<dima<<endl;
return 0;

}
