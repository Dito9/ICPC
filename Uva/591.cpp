#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
    int caso=1;
    while(1){
        int blocks;
        cin >> blocks;
        if (blocks==0) break;

        vector<int> vec;
        int suma=0;
        for (int i=0;i<blocks;i++){
            int lec;
            cin>> lec;
            suma+=lec;
            vec.push_back(lec);

        }

        int pared = suma/blocks;
        int mov=0;
        for (int i=0; i<vec.size();i++){

            if ( vec.at(i)> pared ) mov+=(vec.at(i)-pared);
        }
        cout<<"Set #"<<caso<<endl<<"The minimum number of moves is "<<mov<<"."<<endl;
        cout<<endl;
        caso++;
    }
    return 0;
}
