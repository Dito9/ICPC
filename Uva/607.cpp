#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;


pair<int,int> dp[1001][501];

pair <int,int> sum(pair<int,int>a,pair<int,int>b){

return make_pair(a.first+b.first,a.second+b.second);

}
pair <int,int> minimo (pair<int,int>a,pair<int,int>b){

    if (a.first<b.first) return a;
    else {

        if (a.first==b.first) {

            if (a.second<=b.second) return a;
            else return b;

        }else return b;
    }

}
int contenedor;
int castigo;
int lecturas;
int topics[1000];

pair <int,int> solve(int lectura,int capacidadRes,int cantidad){

    if (cantidad>lecturas || topics[lectura]==0 ) {
        int agregar=0;
        if (capacidadRes <= 10 ) {agregar=-castigo;
            (capacidadRes==0) ? agregar=agregar*0:agregar;
        }
        else{
          agregar = (capacidadRes-10) * (capacidadRes-10);
        }
        return make_pair(0,agregar);
    }
    if (topics[lectura]>capacidadRes){

        if (capacidadRes<=10) return sum (make_pair(1,-castigo *((capacidadRes==0)? 0:1 )), (dp[lectura][contenedor].first!=-1)? dp[lectura][contenedor]:dp[lectura][contenedor]=solve(lectura,contenedor,cantidad+1));
        else{
            return sum(make_pair(1,(capacidadRes-10)*(capacidadRes-10)),(dp[lectura][contenedor].first!=-1)? dp [lectura][contenedor]:dp[lectura][contenedor]=solve(lectura,contenedor,cantidad+1));
            }
    }
    else{
        pair <int ,int > a;
        (dp[lectura+1][capacidadRes-topics[lectura]].first!=-1) ? a=dp[lectura+1][capacidadRes-topics[lectura]] :a = solve(lectura+1,capacidadRes-topics[lectura],cantidad);

        pair <int ,int > b;
        (dp[lectura][contenedor].first!=-1)? b = dp[lectura][contenedor] : b = solve(lectura,contenedor,cantidad+1);
        int  agregar;

        if (capacidadRes>10) agregar = (capacidadRes-10)*(capacidadRes-10);
        else{
            capacidadRes==0 ? agregar=0:agregar=-castigo;
        }
        return  minimo(a ,sum(b,make_pair(1,agregar)));
    }

}

int main(){
    int test=0;
    int flag=1;
    while(1){
        test++;
        int n;
        cin >> n;
        if (n==0) break;
        memset(topics,0,sizeof(topics));

        for (int i=0;i<n;i++){
            for (int j=0;j<501;j++){
                dp[i][j]=make_pair(-1,-1);
            }

        }
        memset(dp,-1,sizeof(dp));
        lecturas=n;
        int l,c;
        cin >> l>>c;
        contenedor=l;
        castigo=c;
        int clasesTot=1;
        int acumulador=0;
        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            acumulador = acumulador + a;
            if (acumulador>contenedor){
                clasesTot++;
                acumulador=a;
            }
            topics[i]=a;
        }
        lecturas=clasesTot;
        pair<int,int> minimo = solve(0,l,0);
        int ca=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<501;j++){
                pair <int,int> a = dp[i][j];
                if (a.first!=-1) ca++;
            }
        }

        if (flag){
            flag=0;
        }else cout <<endl;

        cout <<"Case "<<test<<":"<<endl;
        cout <<"Minimum number of lectures: "<<minimo.first+1 <<endl;
        cout <<"Total dissatisfaction index: "<<minimo.second << endl;

    }

    return 0;
}
