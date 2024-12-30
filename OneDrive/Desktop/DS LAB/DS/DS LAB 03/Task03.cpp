#include <iostream>

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
            tail->next=head;
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
            tail->next=head;
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
            tail->next=head;
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
            tail->next=head;
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
            while(curr!=tail){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<"->";
            cout<<"repeat"<<endl;
            return;
        }

        void display(Node<T>* head){
            if(head==NULL){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=head;
            while(curr!=tail){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<"->";
            cout<<"repeat"<<endl;
            return;
        }
    
        

};

int main(){

    linklist<int> list;
    list.add_node_at_tail(0);
    list.add_node_at_tail(1);
    list.add_node_at_tail(2);
    list.add_node_at_tail(3);
    list.add_node_at_tail(4);
    list.add_node_at_tail(5);

    // display circular list
    list.display();


    // insert at end
    list.add_node_at_tail(0);
    list.display();
    
    // insert at start
    list.add_node_at_head(0);
    list.display();
    
    // insert at pos
    list.add_node_at_pos(0,6);
    list.display();

    //list.delete_node_at_head();
    // list.display();
    // list.delete_node_at_tail();
    // list.display();

    // delete node at any pos
    list.delete_node_at_pos(5);
    list.delete_node_at_pos(6);
    list.delete_node_at_pos(0);
    // list.delete_node_at_pos(10);

    list.display();

    return 0;
}