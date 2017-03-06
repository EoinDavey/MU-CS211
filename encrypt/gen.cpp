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
    vector<pair<double, char> > ls;
    int tot=0;
    while(getline(f,s))
        for(int i=0;i<s.length();c[s[i++]]++, tot++){}
    for(int i=0;i<256;i++)
        if(c[i]>0)ls.push_back(make_pair(((double)c[i])/((double)tot),i));
    sort(ls.begin(), ls.end(), greater<pair<double, char> >());
    cout << ls.size() << endl;
    sym[ls[0].second] = ' ';
    for(int i= 1; i < ls.size(); i++){
        if(getline(cin,s)){
            sym[ls[i].second] = s[0];
        } else {
            sym[ls[i].second] = ls[i].second;
        }
        printf("%c : %lf -> %c\n", ls[i].second,ls[i].first,sym[ls[i].second]);
    }
    sym['m'] = '.';
    sym['#'] = ',';
    f.clear();
    f.seekg(0, ios::beg);
    while(getline(f,s)){
        for(int i = 0; i < s.size()-1; i++){
            printf("%c",sym[s[i]]);
        }
        cout << endl;
    }
    f.close();
}
