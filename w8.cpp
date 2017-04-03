#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

struct state{
    int n, s;
    state(int _n, int _s) : n(_n), s(_s){}
    state(){}
    bool operator < (state r) const {
        if(n!=r.n) return n < r.n;
        return s < r.s;
    }
    bool operator == (state r) const {
        return (n==r.n&&s==r.s);
    }
};

const int mx_n = 44;
int N;
int tgt;
int res;
int a[mx_n];
map<state,int> memo;

int cost(int s){
    return s-tgt;
}

int dp(int cur, int sum){
    state s = state(cur,sum);
    map<state,int>::iterator i = memo.find(s);
    if(i!=memo.end())
        return memo[s];
    if(cur == N)
        return memo[s] = cost(sum);
    if(a[cur]==-1)
        return memo[s] = dp(cur+1,sum);
    int take = dp(cur+1, sum+a[cur]);
    int leave = dp(cur+1,sum);
    int ans = (abs(take) < abs(leave)) ? take : leave;
    memo[s] = ans;
    return ans;
}

void print(int cur, int sum){
    if(cur==N)
        return;
    if(memo[state(cur+1,sum+a[cur])]==res){
        printf("%d ",a[cur]);
        print(cur+1,sum+a[cur]);
    } else 
        print(cur+1,sum);
}

int main(){
    cin >> N;
    int sum = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    tgt = (sum+1)/2;
    printf("tgt:%d\n",tgt);
    int min = sum;
    int ans;
    int temp;
    res = dp(0,0);
    print(0,0);
    cout << endl;
    /*for(int i = 0; i < N; i++){
        memo.clear();
        temp = a[i];
        a[i] = -1;
        res = dp(0,0);
        printf("Ignoring %d gives %d\n",temp,res);
        if(res < min)
            min = res,ans=i;
        a[i] = temp;
    }
    printf("%d, %d\n",min,ans);*/
    return 0;
}
