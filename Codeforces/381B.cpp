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
int arreglo[5000];
int main(){
memset(arreglo,0,sizeof(arreglo));
int n,maximo=0;
cin >> n;
int cont=0;
for (int i=0;i<n;i++){
int a;
cin >>a;
if (a>maximo) maximo=a;

if (arreglo[a]<2){
        arreglo[a]+=1;
        cont++;
}

}

if (arreglo[maximo]==2){
        arreglo[maximo]--;
    cont--;
}
cout <<cont<<endl;


for (int i=0;i<=maximo;i++){

    if (arreglo[i]==2){
        arreglo[i]=1;
        cout << i<<" ";
    }

}
for (int i=maximo;i>=0;i--){
    if (arreglo[i]==1){
        arreglo[i]=0;
        cout <<i<<" ";
    }
}

return 0;

}
