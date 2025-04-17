class LRUCache {
public:
class Node{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};
    int tot_cap;
    Node *oldest;
    Node *latest;
    unordered_map<int,Node*>table;
    LRUCache(int capacity) {
        tot_cap=capacity;
        oldest=new Node(-1,0);
        latest=new Node(-1,0);
        oldest->next=latest;
        latest->prev=oldest;
        table={};
    }

    void insert(Node *node){
        Node *prev=latest->prev;
        Node *next=latest;
        prev->next=node;
        next->prev=node;
        node->prev=prev;
        node->next=next;
    }

    void remove(Node *node){
        Node *prev=node->prev;
        Node *next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    
    int get(int key) {
        // cout<<"get->"<<key<<endl;
        if(table.find(key)!=table.end()){
            Node *node=table[key];
            if(node) cout<<node->value<<endl;
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<"put->"<<key<<","<<value<<endl;
        if(table.find(key)!=table.end()){
            remove(table[key]);
        }
        Node *node=new Node(key,value);
        table[key]=node;
        insert(node);
        if(table.size()>tot_cap){
            Node *lru=oldest->next;
            remove(lru);
            table.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */