#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <pair <int, string> > dic;

int main (){
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        pair <int, string> p =make_pair(s.size(),s);
        dic.push_back(p);
    }
    sort(dic.begin(),dic.end());
    for(int i=0;i<dic.size();i++) cout<<dic[i].second<<endl;
    return 0;
}
