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

using namespace std;

vector <int> rope;
int main(){

    int n;
    int l,r;
    cin >> n;
    cin >> l>>r;

    for (int i=0;i<100;i++){
            rope.push_back(0);
    }

    for (int i=l;i<r;i++){
            rope.at(i)=1;
    }

    for (int i=1;i<n;i++){
        cin >> l>>r;
        for (int j=l;j<r;j++){
            rope.at(j)=0;
        }
    }
    int cont=0;
    for (int i=0;i<rope.size();i++){
        if (rope.at(i)==1) cont++;
    }
    cout << cont<<endl;

    return 0;
}



