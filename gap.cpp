#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;

using namespace std;

vector<ll> num;
int N;

int main(){
    cin >> N;
    ll in;
    for(int i =0; i < N; i++){
        scanf("%lld",&in);
        num.push_back(in);
    }
    while(num.size() > 1){
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++)
            printf("%lld ",num[i]);
        printf("\n");
        ll mn; bool mnb = false;
        int m_pos;
        for(int i = 0; i < num.size()-1; i++)
            if((num[i+1]-num[i]) < mn || !mnb)
                mn = num[i+1]-num[i], mnb=true, m_pos=i;
        num.erase(num.begin()+m_pos);
        num.erase(num.begin()+m_pos);
        num.push_back(mn);
    }
    cout << num[0] << endl;
    return 0;
}
