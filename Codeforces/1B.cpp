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
#include <sstream>

using namespace std;

int reconocer(string cadena){

    if (cadena.at(0)=='R'){
            if (isalpha(cadena.at(1))){
                return 1;
            }
            else{
             int pos=cadena.find('C',2);
             if (pos>1) return 0;
             else return 1;
            }

    }
    else return 1;

};

string convertir(string cadena,int tipo){
    int row=0;
    int column=0;
    string ro="";
    string conv="";
    if (tipo==0){
        int i=1;
        while (isdigit(cadena.at(i))){
            //int a = cadena.at(i)-'0';
            //row = row*10+a;
            i++;
        }
        int j=i;
        i++;
        while (i<cadena.size()){

            int a = cadena.at(i)-'0';
            column= column*10+a;
            i++;
        }
        while(column!=0){
            int res=column%26;
            char*c= (char*)malloc(sizeof(char)*2);
             if (res==0) c[0]='Z';
             else c[0]=res+'A'-1;
             c[1]='\0';

            conv.append(c);
            column=column/26;
            if (res==0) column--;

        }

        string col="";
        for(int k=(int)conv.size();k>0;k--){
            char*c= (char*)malloc(sizeof(char)*2);
            c[0]=(conv.c_str())[k-1];
            c[1]='\0';
            col.append(c);

        }

    ro=cadena.substr(1,j-1);


    return col+ro;
    }
    else{
    int i=0;

    while( isalpha(cadena.at(i))){
             char*c= (char*)malloc(sizeof(char)*2);
             c[0]=cadena.at(i);
             c[1]='\0';
             conv.append(c);
             i++;

    }
    int tam = conv.size();

    int col=0;
    int factor=1;
    while(tam!=0){
        col=col+(cadena.at(tam-1)-'A'+1)*(factor);
        factor*=26;
        tam--;
    }

    ro=cadena.substr(i,cadena.size()-1);

    stringstream ss;
    ss << col;
    string str = ss.str();
    return "R"+ro+"C"+str;

    }

}


int main(){
int n;
cin >>n;

string cadena;
for (int i=0;i<n;i++){

cin >> cadena;
int tipo=reconocer(cadena);
string imprimir=convertir(cadena,tipo);
cout << imprimir<<endl;
}

return 0;
}
