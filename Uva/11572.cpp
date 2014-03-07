#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
    int test;
    cin >> test;
    for (int i=0; i<test; i++){
       map < long long int, long long int> mapa;
       long long int longitud;
       cin >> longitud;
       long long int ini =0;
       long long int respuesta=1;
       long long int maximo=0;

       for(long long int j=1;j<=longitud;j++){
            long long int parentesis;
            int identificador;
            cin >> identificador;

            if (mapa[identificador]==0) {
                mapa[identificador]=j;
            }
            else {
                ini = max(ini,mapa[identificador]);
                mapa[identificador]=j;
            }

            parentesis = j-ini ;

            if (parentesis > maximo) {
                    maximo =parentesis;
            }
       }

       cout<< maximo<<endl;

    }
    return 0;
}
