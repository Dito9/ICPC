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

vector<int> arreglo;
long long int cont=0;

long long int solve(int i,int j){
    if (arreglo.at(i)==0) return solve(i-1,j);
    else {
      if (i==0) {
            cont++;
            return 1;
      }
      int tam=j-i+1;
      if ( (j+1-tam) == 0 ) return 1;
      if ( j+1-tam > tam ) {
          int a = solve(i-1,i-1);
          a++;
          cont++;
          return a;
      }
      if ( j+1-tam < tam ) return 1;

      if ( j+1-tam == tam ){
        bool mayor = true;
        int a =0;
        int b =i;
        while (mayor){
        if (a==i) {
            cont++;
            return 1 + solve(i-1,i-1);
        }
        if (arreglo.at(a)> arreglo.at(b)){
            mayor=false;
            cont++;
            return 1+ solve(i-1,i-1);
        }

        else if (arreglo.at(a)==arreglo.at(b) ) {
            a++;
            b++;
        }

        else if (arreglo.at(a)<arreglo.at(b) ) {
            cont++;
            return 1;
        }
        }

      }

    }

}

int main(){

    string s;
    cin >>s;

    for (int i=0;i<s.size();i++){
      int val = s.at(i)-'0';
      arreglo.push_back(val);
    }
    int tam=arreglo.size();

    long long int a = solve((tam-1),(tam-1));

    cout << a<<endl;


	return 0;

}
