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
#include <cstring>
using namespace std;

double dist[9][9];
int dij[9];
int solucion[9][1];
pair <int,int> proximo(double dist[9][9]){
    int minimo=100000000;
    pair <int,int> rpt;
    for (int i=0; i<9;i++){
        for (int j=0;j<9;j++){

            double actual = dist[i][j];
            if (actual<minimo) {

                minimo = min((double)minimo,actual);
                rpt.second=j+1;
                rpt.first=i+1;
            }
        }
    }
return rpt;
}

int main(){

    while(1){
        memset(solucion,0,sizeof(solucion));
        memset(dist,1000000,sizeof(dist));

        vector < pair< long long int, long long int > > puntos;
        int t;
        cin>>t;
        if (t==0) break;
        for (int i=0;i<t;i++){
            dij[i+1]=i+1;
        }
        for (int i=0; i< t;i++){
        int a,b;
        cin >>a>>b;
        pair <int,int> par(a,b);
        puntos.push_back(par);
        }

        for (int i=0;i<t;i++){
            for (int j=0;j<t;j++){
                int x1,y1,x2,y2;
                x1 = puntos.at(i).first;
                y1 = puntos.at(i).second;
                x2 = puntos.at(j).first;
                y2 = puntos.at(j).second;
                dist[i][j] = sqrt( (int)pow(abs(x2-x1),2) + (int)pow(abs(y2-y1),2));
                cout <<"distancia "<< dist[i][j] <<endl;
            }
        }

        for (int i=0;i<t;i++){
            for (int j=0;j<t;j++){

        pair<int,int> rpt;
        rpt = proximo(dist);
        double distancia = dist[rpt.first][rpt.second];
        dist[rpt.first][rpt.second]=100000000;

        if (dij[rpt.first]!=dij[rpt.second]) {

                dij[rpt.first]=dij[rpt.second];
                solucion[min(rpt.first,rpt.second)][0]=max(rpt.first,rpt.second);

                }
            }
        }

        for (int i=0;i<9;i++){
            cout<<"camino: "<<solucion[i][0]<<endl;
        }
    }



return 0;

}
