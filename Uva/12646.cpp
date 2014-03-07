
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int main(){
    int a,b,c;

    while (cin >>a >> b >>c){

    if (a==b) {

        if (b==c){
            cout <<"*"<<endl;
            continue;
        }
        else {
           cout << "C"<<endl;
        }

    }
    else {

        if (b==c){
            cout <<"A"<<endl;
            continue;
        }
        else {
            cout <<"B"<<endl;
            continue;
        }

    }


    }

    return 0;

}
