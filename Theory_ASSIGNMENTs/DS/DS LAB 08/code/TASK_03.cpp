#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node{
    public:
        int key;
        Node<T>* left;
        Node<T>* right;
        Node(int _key) : key(_key), left(nullptr), right(nullptr){}
};

#include <iostream>
using namespace std;

template<typename T1,typename T2,typename T3>
class Triplet {
    public:
    T1 first;
    T2 second;
    T3 third;

    Triplet(T1 _first, T2 _second, T3 _third) : first(_first), second(_second), third(_third) {}
};


template<typename T>
class BinarySearchTree{
    private:
        Node<T>* root;
    public:
        BinarySearchTree() : root(nullptr){};

        Node<T>* getRoot(){
            return root;
        }

        void addNode(T key) {
            addNode(new Node<T>(key), root);
        }

        void addNode(Node<T>* newNode,Node<T>*& root) {
            if (!root){
                root=newNode; 
                return;
            }
            if (newNode->key==root->key) return;

            if (newNode->key<root->key) addNode(newNode, root->left);
            else addNode(newNode, root->right);
           
            return;
        }

        void print_current_level(Node<T>* root,int level){
            if(!root) return;
            if(level==0) cout<<root->key<<" ";
            else if(level>0){
                print_current_level(root->left,level-1);
                print_current_level(root->right,level-1);
            }
        }
       int max(int i,int j,int k=0){
            int tmp=(j>k)? j:k;
            return (i>tmp)? i:tmp; 
       }       

        int height(Node<T>* root){
            if (!root) return -1;
                return max(height(root->left),height(root->right))+1;
            
        }
        
        void display_levelorder(){
            display_levelorder(root);
        }
        void display_levelorder(Node<T>* root){
            int h= height(root);
            for(int i=0 ; i<=h ; i++){
                print_current_level(root,i);
                cout<<endl;
            }
        }

        Triplet<bool,int,string> search(T val){
            return search(root,val,0,"");
        }

        Triplet<bool,int,string> search(Node<T>* root,T val,int rootlevel,string child=""){
            if(!root) return Triplet<bool,int,string>(false,-1,"");

            Triplet<bool,int,string> left=search(root->left,val,rootlevel+1,"left");
            Triplet<bool,int,string> right=search(root->right,val,rootlevel+1,"right");

            bool check=(root->key==val) || left.first || right.first; 
            int level=(root->key==val)? rootlevel:(left.first)? left.second:(right.first)? right.second:-1;
            string currentChild=(root->key==val)? child:(left.first)? left.third:(right.first)? right.third:"";

            return Triplet<bool,int,string>(check,level,currentChild);
            
        }
};





int main() {
    BinarySearchTree<int> tree;
    tree.addNode(25);
    tree.addNode(20);
    tree.addNode(36);
    tree.addNode(10);
    tree.addNode(22);
    tree.addNode(30);
    tree.addNode(40);
    tree.addNode(1);
    tree.addNode(11);
    tree.addNode(21);
    tree.addNode(24);
    tree.addNode(50);
    tree.addNode(31);
    tree.addNode(29);
    tree.addNode(39);

    int searchValue;
    cout<<"INPUT VALUE TO SEARCH: ";
    cin>>searchValue;

    Triplet<bool, int, string> result = tree.search(searchValue);

    cout<<endl<<"Tree structure (level order):"<<endl;
    tree.display_levelorder();

    if (result.first) {
        cout<<"Value "<<searchValue<<" found at level "<<result.second<<" going "<<result.third<<" from root."<<endl;
    }else{
        cout<<"Value "<<searchValue<<" not found. Adding to the tree..."<<endl;
        tree.addNode(searchValue);
        cout<<endl<<"Tree structure (level order):"<<endl;
        tree.display_levelorder();

        result=tree.search(searchValue);
        cout<<"Value "<<searchValue<<" added to the tree and found at level "<<result.second<<" going "<<result.third<<" from root."<<endl;
    }


    return 0;
}