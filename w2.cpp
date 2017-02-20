#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<map>
#include<algorithm>

int c[256];
std::map<char,std::string> d;

struct node{
    int data,occ;
    node * l, * r;
    node(int d,char c, node * ll, node * rr) : occ(d), data(c), l(ll), r(rr){}
};

bool comp (const node * lhs, const node * rhs){
    if(lhs->occ != rhs->occ) return lhs->occ > rhs->occ;
    return lhs->data > rhs->data;
}

void trav(node * root,std::string c){
    if(root->l != NULL)
        trav(root->l,c+"0"), trav(root->r,c+"1");
    else
        d[root->data] = c;
}

int main(){
    std::string s;
    getline(std::cin,s);
    for(int i=0;i<s.length();i++)c[s[i]]++;
    std::priority_queue<node *, std::vector<node *> ,decltype(&comp) > q(comp);
    for(int i=0;i<256;i++)
        if(c[i]>0)q.push(new node(c[i],i,NULL,NULL));
    node * f, * r;
    while(q.size()>1)
        f = q.top(), q.pop(), r = q.top(), q.pop(), q.push(new node(f->occ + r->occ, ((f->data < r->data) ? f->data: r->data),f,r));
    trav(q.top(),"");
    for(int i = 0; i < s.length(); i++)
        std::cout << d[s[i]];
    std::cout << "\n";
}
