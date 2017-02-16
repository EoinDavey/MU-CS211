#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<map>

int c[256];
std::map<char,std::string> d;

struct node{
    int data,occ;
    node * l, * r;
    node(int d,char c, node * ll, node * rr){
        occ=d, data=c, l=ll, r=rr;
    }
};

bool comp (const node * lhs, const node * rhs){
    if(lhs->occ==rhs->occ) return lhs->data > rhs->data;
    return lhs->occ > rhs->occ;
}

void trav(node * root,std::string c){
    if(root->l != NULL)
        trav(root->l,c+"0"), trav(root->r,c+"1");
    else
        d[root->data] = c;
}

int main(){
    std::string s;getline(std::cin,s);
    for(int i=0;i<s.length();c[s[i++]]++)
        for(int j=0;j<7;j++)
            printf((((j==6)?((i==s.length()-1)?"%d\n":"%d "):"%d")),((s[i]<<j)&64)!=0);
    std::priority_queue<node *, std::vector<node *> ,decltype(&comp) > q(comp);
    for(int i=0;i<256;i++)
        if(c[i]>0)printf(((c[i]==1)?"'%c' appeared %d time\n":"'%c' appeared %d times\n"),i,c[i]), q.push(new node(c[i],i,NULL,NULL));
    node * f, * r, * n;
    while(q.size()>1)
        f = q.top(), q.pop(), r = q.top(), q.pop(), q.push(new node(f->occ + r->occ, 254,f,r));
    node * h = q.top();
    trav(h,"");
    int sm = 0;
    for(int i = 0; i < s.length(); i++)
        std::cout << d[s[i]] << " ", sm+=d[s[i]].length();
    std::cout << std::endl;
    printf("Compressed size is %d bits / %d bits = %d%%\n",sm,s.length()*7,sm*100/(s.length()*7));
}
