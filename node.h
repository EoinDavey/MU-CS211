struct node{
    int data,occ;
    node *l, *r;
    node(int d,char c, node * ll, node * rr);
};

class compare{
    public:
        bool operator () (const node * lhs, const node * rhs);
};

