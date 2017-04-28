#include<cstdio>
#include<queue>
#include<vector>
typedef long long ll;

using namespace std;

priority_queue<ll> q;
vector<ll> right;
vector<ll> left;
vector<ll> trash;
int N;
const int mx_n = 44;
ll a[mx_n];
ll mn_dif;
bool final = false;

void rec(){
    if(q.size()==1){
        right.push_back(q.top());
        return;
    } 
    int v1 = q.top(); q.pop();
    int v2 = q.top(); q.pop();
    int dif = v1-v2;
    q.push(dif);
    if(dif < mn_dif)
        mn_dif = dif;
    if(final){
        if(dif!=mn_dif)
            rec();
        else
            right.push_back(dif);
        bool found = false;
        for(int i = 0; i < right.size()&&!found; i++){
            if(right[i]==dif){
                right.erase(right.begin() + i);
                found = true;
                right.push_back(v1);
                left.push_back(v2);
            }
        }
        for(int i = 0; i < left.size()&&!found; i++){
            if(left[i]==dif){
                left.erase(left.begin() + i);
                found = true;
                left.push_back(v1);
                right.push_back(v2);
            }
        }
    } else 
        rec();
}

int main(){
    scanf("%d",&N);
    int out[N];
    for(int i =0; i < N; i++){
        scanf("%lld",&a[i]);
        mn_dif+=a[i];
        q.push(a[i]);
        out[i] = 0;
    }
    rec();
    while(!q.empty())q.pop();
    final = true;
    left.clear();
    right.clear();
    ll lsum,rsum;
    lsum=rsum=0;
    for(int i = 0; i < N; i++){
        q.push(a[i]);
    }
    rec();
    printf("Left:");
    for(int i = 0; i < left.size(); i++){
        printf(" %lld",left[i]);
        lsum+=left[i];
        for(int j = 0; j < N; j++){
            if(out[j]==0&&a[j]==left[i]){
                out[j]=1;
                break;
            }
        }
    }
    printf("\nRight:");
    for(int i = 0; i < right.size(); i++){
        printf(" %lld",right[i]);
        rsum+=right[i];
        for(int j = 0; j < N; j++){
            if(out[j]==0&&a[j]==right[i]){
                out[j]=-1;
                break;
            }
        }
    }
    printf("\nright: %lld, left: %lld, dif: %lld\n",rsum,lsum, lsum-rsum);
    for(int i = 0; i < N; i++){
        printf("%d,",out[i]);
    }
    return 0;
}
