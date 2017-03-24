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
    for(int i =32; i < 127; i++)
        sym[i] = i;
    char a,b;
    a = 'r';
    b = ' ';
    do{
        sym[a] = b;
        f.clear();
        f.seekg(0, ios::beg);
        while(getline(f,s)){
            for(int i = 0; i < s.size(); i++){
                printf("%c",sym[s[i]]);
            }
            cout << endl;
        }
    } while(cin >> a >> b);
    f.close();
}
