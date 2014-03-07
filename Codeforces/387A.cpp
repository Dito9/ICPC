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
    int h,s;
    int h1,s1;
    char c;
    char c1;
    cin >> h >> c >>s;
    cin >> h1 >>c1 >> s1;

    int hf,sf;

    hf = h-h1;
    sf= s-s1;

    while (hf<0 || sf<0){

        if (sf<0) {
                sf=60+sf;
                hf--;
        }

        if (hf<0) hf=24+hf;

    }

    if (hf>9) {
        cout << hf << ":";
    }
    else {
        cout <<"0" << hf<<":";
    }
    if (sf>9){
        cout << sf<<endl;
    }
    else {
        cout << "0"<<sf<<endl;

    }

	return 0;
}
