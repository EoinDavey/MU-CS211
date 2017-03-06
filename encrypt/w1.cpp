#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int c[256];
map<char, char> sym;

int main(){
    ifstream f("encoded.txt");
    string s;
    vector<pair<int, char> > ls;
    while(getline(f,s))
        for(int i=0;i<s.length();c[s[i++]]++){}
    for(int i=0;i<256;i++)
        if(c[i]>0)ls.push_back(make_pair(c[i],i));
    sort(ls.begin(), ls.end(), greater<pair<int, char> >());
    cout << ls.size() << endl;
    for(int i= 0; i < ls.size(); i++){
        if(getline(cin,s)){
            sym[ls[i].second] = s[0];
        } else {
            sym[ls[i].second] = ls[i].second;
        }
    }
    f.clear();
    f.seekg(0, ios::beg);
    while(getline(f,s)){
        for(int i = 0; i < s.size(); i++){
            printf("%c",sym[s[i]]);
        }
        cout << endl;
    }
    f.close();
}
