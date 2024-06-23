struct Node{
 
    Node *position[26];  // 0 means a,1 means b .....
    long long cntEndwith=0;
    long long cntPrefix=0;
 
    bool containsKey(char ch)
    {
        return (position[ch-'a']!=NULL);
    }
 
    Node * get(char ch)
    {
        return position[ch-'a'];
    }
 
    void put(char ch,Node * node)
    {
        position[ch-'a']=node;
    }
 
    void increaseEnd()
    {
        cntEndwith++;
    }
 
    void increasePrefix()
    {
        cntPrefix++;
    }
 
    void decreaseEnd()
    {
        cntEndwith--;
    }
 
    void decreasePrefix()
    {
        cntPrefix--;
    }
 
    long long getEnd()
    {
        return cntEndwith;
    }
 
    long long getPrefix()
    {
        return cntPrefix;
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
        for(char ch='a';ch<='z';ch++)
        {
            if(node->containsKey(ch))
            {
                del(node->get(ch));
            }
        }
        delete(node);
    }
 
    void insert(string &word){
        Node * node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();   
        }
        node->increaseEnd();
    }
 
    long long countWordsEqualTo(string &word){
        Node * node=root;
 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            else
            {
                node=node->get(word[i]);
            }
        }
        return node->getEnd();
    }
 
    int countWordsStartingWith(string &word){
        Node * node=root;
 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            else
            {
                node=node->get(word[i]);
            }
        }
        return node->getPrefix();
    }
 
    void erase(string &word){
        Node * node=root;
 
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return;
            }
            else
            {
                node=node->get(word[i]);
                node->decreasePrefix();
            }
        }
        node->decreaseEnd();
    }
    long long modified_insert(string &word){
        long long ans=0;
        Node * node=root;
        for(int i=word.size()-1;i>=0;i--)
        {
            if(!node->containsKey(word[i]))
            {
                // node->put(word[i],new Node());
                return ans;
            }
            node=node->get(word[i]);
            if(node->getEnd() >0 )
            {
                ans=(ans+dp[i])%M;
            }
            // node->increasePrefix();   
        }
        return ans;
        // node->increaseEnd();
    }
};
