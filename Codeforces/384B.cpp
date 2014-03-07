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
int arreglo[1000][100];
vector< pair<int,int> > pares;

int main(void){
    int a,b,c;
    cin >>a>>b>>c;
    for(int i=0;i<a;i++){
        for (int j=0;j<b;j++){
            int x;
            cin >> x;
            arreglo[i][j] = x;
        }
    }

    int minimo=1000001;
    int maximo=0;
    if (c==0){
    for (int m=0;m<a;m++){
        int a1,b1;
        for (int i=0;i<(b-1);i++){
            for (int j=i+1;j<b;j++){
                if ( (arreglo[m][j]<minimo) && (arreglo[m][j]<arreglo[m][i] ) ){
                a1=i;
                b1=j;
                minimo=arreglo[m][j];
                }
            }

            if (minimo!=1000001) {pares.push_back(make_pair(a1,b1));

            for (int x=0;x<a;x++){

               if (arreglo[x][a1]>arreglo[x][b1]){
                    swap(arreglo[x][a1],arreglo[x][b1]);
               }
            }

          }
           minimo=1000001;
        }

    }
}
else {

        for (int m=0;m<a;m++){
        int a1,b1;
        for (int i=0;i<(b-1);i++){
            for (int j=i+1;j<b;j++){
                if ( (arreglo[m][j]>maximo) && (arreglo[m][j]>arreglo[m][i] ) ){
                a1=i;
                b1=j;
                maximo=arreglo[m][j];
                }
            }

            if (maximo!=0) {pares.push_back(make_pair(b1,a1));

            for (int x=0;x<a;x++){

               if (arreglo[x][a1]<arreglo[x][b1]){
                    swap(arreglo[x][a1],arreglo[x][b1]);
               }
            }

          }
           maximo=0;
        }

    }
}
    cout << pares.size()<<endl;
    for (int i=0; i< pares.size();i++){
        cout << pares.at(i).first+1 << " " << pares.at(i).second+1<<endl;
    }

    return 0;

}


