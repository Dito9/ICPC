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
    int n;
    cin >>n;
    if (n%2==0) {
            cout << ((n*n)/2) << endl;
    }
    else {
            cout << (((n*n)+1)/2) << endl;
    }


    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){

        if ( ( (i+j)%2)==0){
        cout << "C";
        }
        else {
        cout << ".";
        }

        }
        cout <<endl;
    }

return 0;
}
