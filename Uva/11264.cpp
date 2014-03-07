#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;

int main(){

    int t;
    cin >>t;
    while(t--){
        vector<long long int > monedas;
        long long int c,m;
        cin >>c;
        for (int i=0;i<c;i++){
            cin >>m;
            long long int par;
            par=m;
            monedas.push_back(par);
        }

        int maximo=0;
        int cont=0;
        for (int i=0;i<c;i++){
        if ( (i==c-1) || (maximo+monedas.at(i)<monedas.at(i+1))){
            cont ++;
            maximo+=monedas.at(i);
        }
        }
        cout << cont<<endl;
        monedas.clear();

    }
    return 0;

}
