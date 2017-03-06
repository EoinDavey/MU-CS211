#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

int c[256];
char fileNames[][8] = {"dan.txt","eng.txt","fin.txt","fre.txt","ger.txt","pol.txt","ice.txt","spa.txt","swe.txt"};
map<char, char> sym;

int main(){
    string s;
    vector<pair<double, char> > ls;
    int tot=0;
    while(getline(cin,s)){
        cout << s << endl;
        for(int i=0;i<s.length();c[s[i++]]++)
            if(s[i]!=' ')tot++;
    }
    for(int i=0;i<256;i++)
        if(c[i]>0)ls.push_back(make_pair(((double)c[i])/((double)tot),i));
    sort(ls.begin(), ls.end(), greater<pair<double, char> >());
    cout << ls.size() << endl;
    sym[ls[0].second] = ' ';
    for(int l = 0; l < 9; l++){
        ifstream inputF(fileNames[l]);
        printf("File:%s\n",fileNames[l]);
        double sTot = 0;
        char c;
        double tempIn;
        while(inputF >> c){
            inputF >> tempIn;
            sTot+=tempIn;
        }
        inputF.clear();
        inputF.seekg(0,ios::beg);
        double error = 0;
        for(int i= 1; i < 10; i++){
            inputF >> c >> tempIn;
            printf("%c : %lf, %c : %lf\n",ls[i].second, ls[i].first, c, ((tempIn)/sTot));
            error+= log(1 - (abs(ls[i].first - ((tempIn)/sTot))));
        }
        printf("%lf error : %lf characters\n",error,sTot);
        inputF.close();
    }
}
