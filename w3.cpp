#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;

bool comp(string lhs, string rhs){
    char mxl, mxr;
    mxl = lhs[0];
    mxr=rhs[0];
    for(int i= 0;i < lhs.size(); i++){
        if(lhs[i] > mxl)mxl=lhs[i];
    }
    for(int i= 0;i < rhs.size(); i++){
        if(rhs[i] > mxr)mxr=rhs[i];
    }
    if(mxr != mxl) return mxr > mxl;
    else return lhs < rhs;
}

vector<string> a;

void qSort(int L, int R){
    if(L>=R-1) return;
    int r = (rand() % (R-L)) + L;
    string t = a[r];
    a[r] = a[L];
    a[L] = t;
    string pivot = a[L];
    int store = L+1;
    for(int i = store; i < R; i++){
        if(comp(a[i],pivot)){
            t = a[i];
            a[i] = a[store];
            a[store++] = t;
        }
    }
    a[L] = a[store-1];
    a[store-1] = pivot;
    qSort(L, store-1);
    qSort(store,R);
}

int main(){
    int N; cin >> N;
    string temp;
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        cin >> temp;
        a.push_back(temp);
    }
    qSort(0,N);
    for(int i = 0; i < N; i++){
        cout << a[i] << endl;
    }
}
