
# include <iostream>

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next=NULL;
        Node(int value=0):data(value){};
};
 

template <typename T>
class linklist{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        linklist() : head(NULL), tail(head){}
        linklist(int value) : head(new Node<T>(value)), tail(head){}

        void add_node_at_tail(T value){
            Node<T>* new_node=new Node<T>(value);
            if(head==NULL){
                head=new_node;
                tail=head;
                return;
            }
            tail->next=new_node;
            tail=new_node;
            tail->next=nullptr;
        }

        void add_node_at_pos(T value,int pos){
            Node<T>* new_node=new Node<T>(value);
            if(head==NULL){
                head=new_node;
                tail=head;
                return;
            }
            if(pos==0){
                add_node_at_head(value);
                return;
            }
            int count=0; Node<T>* curr=head;
            while(count<pos-1 && curr!=tail){
                if(curr==tail){
                    cout<<"Error Wrong Position";
                    return;
                }
                curr=curr->next;
                count++;
            }
            if(curr==tail){
                add_node_at_tail(value);
                return;
            }

            Node<T>* prev_node=curr;
            Node<T>* next_node=curr->next;
            
            prev_node->next=new_node;
            new_node->next=next_node;
            
        }

        void add_node_at_head(T value){
            Node<T>* new_node=new Node<T>(value);
            new_node->next=head;
            head=new_node;
            return;
        }

        void delete_node_at_pos(int pos){
            if(head==NULL){
                cout<<"Linklist Does Not Rush"<<endl;
                return;
            }
            if(pos==0){
                delete_node_at_head();
                return;
            }
            int count=0; Node<T>* curr=head;
            while(count<pos-1){
                if(curr==tail){
                    cout<<"Error Wrong Position";
                    return;
                }
                curr=curr->next;
                count++;
            }
            if(curr->next==tail){
                delete_node_at_tail();
                return;
            }
            Node<T>* prev_node=curr;
            Node<T>* tmp_node=curr->next;
            Node<T>* next_node=curr->next->next;
            prev_node->next=next_node;

            delete tmp_node;
        }
        

        void delete_node_at_head(void){
            if(head==NULL){
                cout<<"Linklist Does Not Rush"<<endl;
                return;
            }

            Node<T>* tmp_node=head;
            head=head->next;
            delete tmp_node;
        }

        void delete_node_at_tail(void){
            if(head==NULL){
                cout<<"Linklist Does Not Rush"<<endl;
                return;
            }

            Node<T>* tmp_node=tail;
            Node<T>* curr=head;
            while(curr->next!=tail){
                curr=curr->next;
            }
            tail=curr;
            tail->next=nullptr;
            delete tmp_node;
        }
       
        Node<T>* get_head(void){
            return head;
        }
        
        Node<T>* get_tail(void){
            return tail;
        }

        
        void set_tail(Node<T>* tail){
            this->tail=tail;
            return;
        }        
        void set_head(Node<T>* head){
            this->head=head;
            return;
        }
        
        void display(void){
            if(head==NULL){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=head;
            while(curr->next!=nullptr){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<"->";
            cout<<"nullptr"<<endl;
            return;
        }
};


template <typename T>
int search(Node<T>* head, T value){
    if(!head) return -1;
    if(head->data==value) return 0;
    int count=search(head->next,value);
    return ++count; 
}



int main(){

    linklist<int> list;
    list.add_node_at_tail(0);
    list.add_node_at_tail(1);
    list.add_node_at_tail(2);
    list.add_node_at_tail(3);
    list.add_node_at_tail(4);
    list.add_node_at_tail(5);
    list.add_node_at_tail(6);
    list.add_node_at_tail(7);
    list.add_node_at_tail(8);
    list.add_node_at_tail(9);
    list.add_node_at_tail(10);
    
    list.display();
    cout<<"Number At Index: "<<search(list.get_head(),6);
 
    return 0;
}