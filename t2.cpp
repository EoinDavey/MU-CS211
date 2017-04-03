#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int N, maxLen;
string input;
vector<string> ls;

struct node{
    bool word, visited;
    node * adj[26];
    ~node(){
        for(int i = 0; i < 26; i++) if(adj[i]!=NULL) delete adj[i];
    }
};

void dfs(node * r, int used, string * s){
    if(r->visited)return;
    if(r->word)
        if(s->length() > maxLen)maxLen = s->length();
    r->visited = true;
    for(int i = 0; i < N; i++)
        if((used&(1<<i))==0)
            if(r->adj[input[i]-'a']!=NULL)
                (*s)+=input[i], dfs(r->adj[input[i]-'a'],(used|(1<<i)),s), s->erase(s->end()-1);
}

void insert(char * s, int i, node * r){
    if(i==strlen(s))
        r->word = true;
    else if(r->adj[s[i] - 'a']==NULL)
        r->adj[s[i] - 'a']= new node(), insert(s,i+1,r->adj[s[i] - 'a']);
    else insert(s,i+1,r->adj[s[i] - 'a']);
}

int main(){
    node * top = new node();
    char * buff = (char *) malloc(sizeof(char)*100);
    cin >> input;
    N = input.length();
    maxLen = 0;
    while(scanf("%s",buff)==1)
        insert(buff,0,top);
    free(buff);
    string l;
    dfs(top, 0, &l);
    delete top;
    cout << maxLen << endl;
    return 0;
}
