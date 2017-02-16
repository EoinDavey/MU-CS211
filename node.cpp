struct node{
    int data,occ;
    node * l, * r;
    node(int d,char c, node * ll, node * rr){
        occ=d;
        data=c;
        l=ll;
        r=rr;
    }
};

class compare{
    public: 
        bool operator () (const node * lhs, const node * rhs) const {
            if(lhs->occ==rhs->occ) return lhs->data > rhs->data;
            return lhs->occ > rhs->occ;
        }
};
