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
vector<string> nombres;
nombres.push_back("");
nombres.push_back("Sheldon");
nombres.push_back("Leonard");
nombres.push_back("Penny");
nombres.push_back("Rajesh");
nombres.push_back("Howard");
long long int n;
cin >> n;

int i=0;
int numero=5;
int cola=1;
int numeroant;
while (numero<n){
    numeroant=numero;
    cola*=2;
    numero=numero+5*cola;
    i++;
}

if (i!=0) n=n-numeroant;
//cola de 2; p =1 numero = 10;

if ( n>0 && n<=cola) cout << nombres[1]<<endl;

else if ( n>cola && n<=cola*2) cout << nombres[2]<<endl;

else if ( n>cola*2 && n<=cola*3) cout << nombres[3]<<endl;

else if ( n>cola*3 && n<=cola*4) cout << nombres[4]<<endl;

else if ( n>cola*4 && n<=cola*5) cout << nombres[5]<<endl;

return 0;
}
