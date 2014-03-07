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
long long int repB[1001];
long long int finB[1001];
int main(void){
    memset(repB,0,sizeof(repB));
    memset(finB,0,sizeof(finB));

    long long int a,b,w,x,c;
    cin >> a>>b>>w>>x>>c;
    long long int cont=0;
    long long int repBC=0;
    long long int finalB=0;
    bool iteracion=false;
    bool flag=false;
    if (b<x && c>a){
        iteracion=true;
        while(b<x){
            c--;
            a--;
            b=w-(x-b);
            cont++;
        }
    }

    while(c>a){
            cout <<"c: "<<c <<" a: "<<a<<endl;
        iteracion=true;
        if (b>=x){
          int repeticion = b/x;
          cont+=repeticion;
          c=c-repeticion;
          b=b-(repeticion*x);
        }
        else{
            int dp = b;
            if (repB[b]==0) {
                repBC=0;
                while (b<x){
                    repBC++;
                    b=w-(x-b);
                }
                repB[dp]=repBC;
                finB[dp]=b;
                flag=true;
            }

            c-= repB[dp];
            a-= repB[dp];
            b=finB[dp];
            cont+=repB[dp];
        }
    }
    if (c<a && iteracion ) cont=cont - abs(c-a);

    printf("%d\n",cont);
    return 0;
}
