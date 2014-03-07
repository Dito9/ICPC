#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;
char matriz[60][60];
int rptR=0;
int rptC=0;
char solve(int fila,int columna){
    char rpt='N';

    char lectura;
    while(1){
        cin >> lectura;

        if (lectura=='Q') break;

        if ( lectura=='R' || lectura=='L' ){
            if (lectura =='R' && rpt=='N') rpt='E';
            else if (lectura =='R' && rpt=='S') rpt='W';
            else if (lectura =='R' && rpt=='E') rpt='S';
            else if (lectura =='R' && rpt=='W') rpt='N';
            else if (lectura =='L' && rpt=='N') rpt='W';
            else if (lectura =='L' && rpt=='S') rpt='E';
            else if (lectura =='L' && rpt=='E') rpt='N';
            else if (lectura =='L' && rpt=='W') rpt='S';
        }
        if ( lectura=='F'){
            if (rpt=='N'){
                if (matriz[fila-1][columna]!='*') fila--;
            }
            if (rpt=='S') if (matriz[fila+1][columna]!='*') fila++;
            if (rpt=='E') if (matriz[fila][columna+1]!='*') columna++;
            if (rpt=='W') if (matriz[fila][columna-1]!='*') columna--;
        }
    }
    rptR=fila;
    rptC=columna;
    return rpt;
}

int main(){
int rows,column;
int rowss,columns;
int test;
scanf("%d",&test);

while(test--){
scanf("%d %d",&rows,&column);
char cambio;
scanf("%c",&cambio);
rptR=0;
rptC=0;
for(int i=0;i<rows;i++){
        for (int j=0;j<column;j++){
            char cadena;
            scanf("%c",&cadena);
            matriz[i][j]= cadena;
        }
        scanf("%c",&cambio);
}
cin >> rowss >> columns;

char rpt = solve(rowss-1,columns-1);

cout << rptR+1<<" " << rptC+1 <<" "<< rpt<<endl;
if (test) cout <<endl;
}
return 0;
}
