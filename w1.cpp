#include<iostream>
#include<cstdio>
#include<string>

int c[256];

int main(){
    std::string s;getline(std::cin,s);
    for(int i =0; i < s.length(); c[s[i++]]++)
        for(int j = 0; j < 8; j++)
            printf((((j==7)?((i==s.length()-1)?"%d\n":"%d "):"%d")),(((s[i] << j) & 128)!=0));
    for(int i = 0; i < 256; i++)
        if(c[i]>0) printf(((c[i]==1)?"'%c' appeared %d time\n":"'%c' appeared %d times\n"), i, c[i]);
}
