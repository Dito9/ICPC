#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <ctime>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define sz size

using namespace std;

map <int,int> mapa1;
map <int,int> mapa2;

int main(){
    int test;
    cin >> test;

    while (test--){
        mapa1.clear();
        mapa2.clear();
        int n,m;
        cin >> n>>m;

        for (int i=0;i<n;i++){
           int a;
           cin >>a;

           if (mapa1.count(a)==0) {
            mapa1[a]=1;
           }
           else{
            mapa1[a]++;
           }

        }

        for (int i=0;i<m;i++){

           int a;
           cin >>a;
           if (mapa2.count(a)==0) {
            mapa2[a]=1;
           }
           else{
            mapa2[a]++;
           }
        }

        map<int,int>::iterator it;
        int contador=0;

/*            for (it=mapa1.begin();it!=mapa1.end();it++){
                cout <<"valor: " << it->first << " cantidad: " << mapa1[it->first]<<endl;
            }

            for (it=mapa2.begin();it!=mapa2.end();it++){

                cout <<"valor: " << it->first << " cantidad: " << mapa2[it->first]<<endl;
            }
*/
            for (it=mapa1.begin();it!=mapa1.end();it++){
                if ( mapa2.count(it->first)==0){
                    contador += ( mapa1[it->first]);
                    mapa1[it->first]=0;
                }
                else {
                    contador += abs( mapa1[it->first] - mapa2[it->first]);
                    mapa1[it->first]=0;
                    mapa2[it->first]=0;
                }
            }

            for (it=mapa2.begin();it!=mapa2.end();it++){

                if ( mapa1.count(it->first)==0){
                    contador += ( mapa2[it->first]);
                    mapa2[it->first]=0;
                }
                else {
                    contador += abs( mapa1[it->first] - mapa2[it->first]);
                    mapa1[it->first]=0;
                    mapa2[it->first]=0;
                }
            }

            cout << contador<<endl;
    }
	return 0;

}

