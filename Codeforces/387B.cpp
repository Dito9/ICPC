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


int main(){
    vector<int>  concurso;
    vector<int>  problemas;

    int n,m;
    cin >>n>>m;

    for (int i=0;i<n;i++){
        int a;
        cin >>a;
        concurso.push_back(a);
    }
    for (int i=0;i<m;i++){
        int a;
        cin >>a;
        problemas.push_back(a);
    }
    int usan=0;
    int necesario= concurso.size();

    sort(concurso.begin(),concurso.end());
    sort(problemas.begin(),problemas.end());
    int j=0;
    for (int i=0;i<problemas.size();i++){
        if (j<necesario){
        if (problemas.at(i)>=concurso.at(j)){
            j++;
            usan++;
        }
        }
        else break;

    }
    cout << (necesario-usan)<<endl;
	return 0;
}
