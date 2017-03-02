#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N;
string input;
vector<string> ls;

struct node{
    bool word, visited;
    node * adj[26];
    ~node(){
        for(int i = 0; i < 26; i++)
            if(adj[i]!=NULL) delete adj[i];
    }
};

void dfs(node * r, int used, string * s){
    if(r->visited)return;
    if(r->word)
         ls.push_back(string(*s));
    r->visited = true;
    for(int i = 0; i < N; i++)
        if((used&(1<<i))==0)
            if(r->adj[input[i]-'a']!=NULL){
                (*s)+=input[i];
                dfs(r->adj[input[i]-'a'],(used|(1<<i)),s);
                s->erase(s->end()-1);
            }
}

void insert(string * s, int i, node * r){
    if(i>=s->length()-1){
        r->word = true;
        return;
    }
    if(r->adj[s->at(i) - 'a']==NULL)
        r->adj[s->at(i) - 'a']= new node();
    insert(s,i+1,r->adj[s->at(i) - 'a']);
}

int main(){
    ifstream file ("dictionary.txt");
    node * top = new node();
    while(getline(file, l))
        insert(&l,0,top);
    cin >> input;
    N = input.length();
    input="";
    dfs(top, 0, &input);
    delete top;
    file.close();
    sort(ls.begin(),ls.end(), [](string lhs, string rhs){if(lhs.length()==rhs.length())return lhs < rhs; else return lhs.length() > rhs.length(); });
    for(int i = 0; i < 10 && i < ls.size(); i++)
        cout << ls[i] << endl;
    return 0;
}
