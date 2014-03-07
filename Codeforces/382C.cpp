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

int main(void){

    int t;
    bool flag=true;
    cin >>t;
    vector<int> inicial;

    vector<int> Medio;

    int posicionIni=0;
    int posicionFin=t-1;
    for (int i=0; i<t;i++){
        int a;
        cin >> a;
        inicial.push_back(a);
    }
    sort(incial.begin(),inicial.end());

    if (t>2){
        int a=inicial.at( inicial.size()-1 ) - inicial.at( inicial.size()-2 ) ;
        int b=inicial.at(1)-inicial.at(0);
        int serie;
        if (a==b) serie=a;
        else {


        }


        for (int i=0; i< inicial.size()-1;i++){

        }

    }

return 0;
}
