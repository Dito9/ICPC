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

int main(){
    long long int t;
    cin >> t;
    while (t--){
        long long int n,l,r;
        cin >> n>>l>>r;
        long long int des = r-l;
        if (n<l) {cout << "No"<<endl;
            continue;
        }
        else {
            if (n>=l && n <=r) cout << "Yes"<<endl;
            else {
            long long int x = n/l;
            long long int diff = n%l;
//          cout <<"dif: "<< diff << " des "<< des<<endl;
            if (diff <= (des*x)) cout << "Yes"<<endl;
            else cout << "No"<<endl;
            }
        }
    }

    return 0;
}



