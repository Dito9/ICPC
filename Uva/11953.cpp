#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

char arreglo[100][100];

int main(){
int test;
int caso=0;
cin >> test;
while(test--){
memset(arreglo,'.',sizeof(arreglo));
caso++;
int n;
cin >>n;
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >>c;
      arreglo[i][j]=c;
    }
}
int cont=0;
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){

    if (arreglo[i][j]=='x'){
        cont++;
        for (int a=j+1;a<n;a++){
            if (arreglo[i][a]=='@' || arreglo[i][a]=='x' ) {
                arreglo[i][a]='.';
                continue;
            }
            if (arreglo[i][a]=='.') break;
        }

        for (int a=j-1;a>=0;a--){
            if (arreglo[i][a]=='@' || arreglo[i][a]=='x' ) {
                arreglo[i][a]='.';
                continue;
            }
            if (arreglo[i][a]=='.') break;
        }

        for (int b=i-1;b>=0;b--){
            if (arreglo[b][j]=='@' || arreglo[b][j]=='x' ) {
                arreglo[b][j]='.';
                continue;
            }
            if (arreglo[b][j]=='.') break;
        }

        for (int b=i+1;b<n;b++){
            if (arreglo[b][j]=='@' || arreglo[b][j]=='x' ) {
                arreglo[b][j]='.';
                continue;
            }
            if (arreglo[b][j]=='.') break;
        }
      }
    }
}

cout << "Case "<<caso<<": "<<cont<<endl;

}


return 0;

}
