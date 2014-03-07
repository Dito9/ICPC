#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

pair<int, string> dp[1000][1000];
pair<int, string> p, pa, pb;
string s="";

pair<int, string> run(int i, int j){

    cout << "i: "<<i<< " j: "<<j<<endl;

	if(i==j) {
            stringstream ss;
            ss << s[i];
            string aux;
            ss >> aux;
            cout <<" string: "<<aux<<endl;
            return make_pair(0,aux);
    }
	if(i>j) {
            return make_pair(0,"");
    }
	if(dp[i][j].first != -1) return dp[i][j];

	if(s[i]==s[j]){
		p = run(i+1, j-1);
        stringstream ss;
        ss<<s[i];
        string aux;
        ss>>aux;
		return dp[i][j] = make_pair(p.first, aux+p.second+aux);
	}
	pa = run(i+1,j);//iz
	pb = run(i,j-1);//de
	cout << "i "<<i+1<<" j "<<j<< " costo: "<<pa.first<<endl;
	cout << "i "<<i<<" j "<<j-1<< " costo: "<<pb.first<<endl;



	if(pa.first<pb.first){
        stringstream ss;
        ss<<s[i];
        string aux;
        ss>>aux;
        cout <<" string: "<<aux+pa.second+aux<<endl;

		return dp[i][j] = make_pair(1+pa.first, aux+pa.second+aux);
	}else{
	    stringstream ss;
        ss<<s[j];
        string aux;
        ss>>aux;
		cout <<" string: "<<aux+pb.second+aux<<endl;

        dp[i][j].first=pb.first+1;
        dp[i][j].second=aux+pb.second+aux;

        return make_pair(pb.first+1,aux+pb.second+aux);

	}
}

int main(){
	while(cin>>s){
        cout<<s<<endl;
		for(int i=0; i<s.size(); i++){
			for(int j=0; j<s.size(); j++){
				dp[i][j].first = -1;
			}
		}
		cout<<"first "<<run(0,(int)s.size()-1).first<<endl;//<<" "<<"second "<<run(0,(int)s.size()-1).second<<endl;
	}
}
