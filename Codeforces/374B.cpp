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

int main(){

char primero,ultimo;

cin >> primero>>ultimo;


long long int contador=1;
long long int retorno=1;

while(1){
    if (cin.eof()) break;

    int valora=primero-'0';
    int valorb=ultimo-'0';
    if (valorb>9 || valorb<1){
        break;
    }
    if (valora!=9 && valorb!=9 ){

        if ( (valora+valorb)==9){
            contador++;
        }
        else{
            if (contador%2 == 0){
                retorno=retorno*1;
            }
            else{
                retorno=retorno*( (contador+1)/2);
            }
            contador=1;
        }
    }
    else {
        if (contador%2 == 0){
                retorno=retorno*1;
            }
            else{
                retorno=retorno*( (long long int)(contador+1)/2);
            }
            contador=1;
    }
    primero=ultimo;
    cin>> ultimo;
}
if (contador>1){
    if (contador%2 == 0){
                retorno=retorno*1;
            }
            else{
                retorno=retorno*( (contador+1)/2);
            }
            contador=1;
}
cout << retorno<<endl;
return 0;

}
