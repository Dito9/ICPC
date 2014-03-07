#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

long int fun(long int n,long int k,long int a, string op,vector<long int> arr){
        long int res;
        if (op.compare("OR")==0){

                    for (long int j=0;j<n;j++){
                        if (j==0) res=arr.at(j);
                        else res= res | arr.at(j);
                    }
                res = a|res;

        }
        else if (op.compare("AND")==0){


                    for (long int j=0;j<n;j++){
                        if (j==0) res=arr.at(j);
                        else res= res & arr.at(j);
                    }
                res = a & res;

        }
        else if (op.compare("XOR")==0){

                    for (long int j=0;j<n;j++){
                        if (j==0) res=arr.at(j);
                        else res= res ^ arr.at(j);
                    }
            if ((k)&1==1) res=res;
            else res=0;

            res = a ^ res;

        }
    return res;
}

int main(){

long int t,n,k,a;
vector<long int> arr;

cin >> t;

for (long int i=0;i<t;i++){

    cin >> n >> k >> a;
    long int valora;

    for (long int j=0;j<n;j++){
    cin >>valora;
    arr.push_back(valora);
    }

    string op;
    cin >>op;

    long int res=fun(n,k,a,op,arr);

    cout<<res<<endl;
    arr.clear();
}

return 0;
}
