int Root[N];

struct PST {

    struct node{
        int lNode=0,rNode=0;
        ll val=0;
    }Node[40*N];  // size of array N

    int nodePos=0;

    int build(int l, int r) {  // return node position
        int curNode= ++nodePos;
        if(l==r)return curNode;
        int mid=(l+r)>>1;
        Node[curNode].lNode=build(l,mid);
        Node[curNode].rNode=build(mid+1,r);
        Node[curNode].val=Node[Node[curNode].lNode].val 
                        + Node[Node[curNode].rNode].val;
        return curNode;
    }

    int upd(int preNode,int l,int r,int pos,ll val){// return node position
        int curNode= ++nodePos;
        Node[curNode]=Node[preNode];

        if(l==r){
            Node[curNode].val+=val; 
            return curNode;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            Node[curNode].lNode=upd(Node[preNode].lNode,l,mid,pos,val);
            Node[curNode].rNode=Node[preNode].rNode;
        }
        else{
            Node[curNode].lNode=Node[preNode].lNode;
            Node[curNode].rNode=upd(Node[preNode].rNode,mid+1,r,pos,val);
        }
        Node[curNode].val=Node[Node[curNode].lNode].val 
                        + Node[Node[curNode].rNode].val;
        return curNode;
    }

    ll getSum(int curNode,int l,int r,int x,int y){//i need from x to y
        if(x>y)return 0;
        if(x==l && y==r)return Node[curNode].val;
        int mid=(l+r)>>1;
        return getSum(Node[curNode].lNode,l,mid,x,min(y,mid))
              +getSum(Node[curNode].rNode,mid+1,r,max(x,mid+1),y);
    }

    int kthSmallest(int preNode,int curNode,int l,int r,ll k){
        if(l==r)return l;
        ll cnt=Node[Node[curNode].lNode].val-Node[Node[preNode].lNode].val;
        int mid=(l+r)>>1;
        if(cnt>=k) return kthSmallest(Node[preNode].lNode,Node[curNode].lNode,l,mid,k);
        else return kthSmallest(Node[preNode].rNode,Node[curNode].rNode,mid+1,r,k-cnt);
    }
};
