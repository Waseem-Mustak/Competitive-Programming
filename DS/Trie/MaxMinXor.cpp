struct Node{
 
    Node *position[2];  // 0 means 0,1 means 1 .....
 
    bool containsKey(int bit)
    {
        return (position[bit]!=NULL);
    }
 
    Node * get(int bit)
    {
        return position[bit];
    }
 
    void put(int bit,Node * node)
    {
        position[bit]=node;
    }
};
 
class Trie{
 
private:
    Node *root;
public:
 
    Trie(){
        root= new Node();
    }

    ~Trie(){
        del(root);
    }
    void del(Node *node)
    {
        for(int i=0;i<2;i++)
        {
            if(node->containsKey(i))
            {
                del(node->get(i));
            }
        }
        delete(node);
    }
 
    void insert(int num){
        Node * node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getMaxXor(int num){
        Node * node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(node->containsKey(1-bit))
            {
                maxNum=(maxNum|(1<<i));
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
    int getMinXor(int num){
        Node * node=root;
        int minNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&1);
            if(!node->containsKey(bit)) // ei bit na thake
            {
                minNum=(minNum|(1<<i));
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return minNum;
    }
};
