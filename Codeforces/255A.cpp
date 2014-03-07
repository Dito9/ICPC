#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
string maximo(int arr[3]){
    if (arr[0] > arr[1]){
            if (arr[0]>arr[2]){
                return "chest";
            }
            else {
                return "back";
            }
    }
    else {
        if (arr[1]>arr[2]){
                return "biceps";
            }
            else {
                return "back";
            }

    }

};

int main(){
int arr[3]={0};
int n,read;
cin >> n;

for (int i=0;i<n;i++){
    cin >>read;
    arr[i%3]+=read;

}
string res = maximo(arr);

cout << res <<endl;

return 0;
}
