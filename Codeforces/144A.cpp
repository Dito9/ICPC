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

int maximo(int* arr,int n){
    int ret=0;
    int pos;
    for(int i=0;i<n;i++){
        if (arr[i]>ret) {
        ret=arr[i];
        pos=i;
        }
    }
    return pos;
};

int minimo(int* arr,int n){
    int ret=101;
    int pos;
    for(int i=0;i<n;i++){
        if (arr[i]<=ret) {
        ret=arr[i];
        pos=i;
        }
    }
    return pos;

};

int main(void){
int n,read;
int* arreglo;

cin >> n;
arreglo = (int*)malloc(sizeof(int)*n);
memset(arreglo,0,sizeof(arreglo));

for (int i=0;i<n;i++){
    cin >> read;
    arreglo[i]=read;

}

int ma = maximo(arreglo,n);
int mi = minimo(arreglo,n);
int ret=0;
ret = ma;
ret+=(n-mi-1);
if(mi<ma) ret--;

cout << ret<<endl;

return 0;
}
