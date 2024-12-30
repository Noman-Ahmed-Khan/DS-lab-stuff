#include <iostream>

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next=NULL;
        Node<T>* prev=NULL;
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
            new_node->prev=tail;
            tail=new_node;
            tail->next=head;
            head->prev=tail;
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
            new_node->prev=prev_node;

            new_node->next=next_node;
            next_node->prev=new_node;
            
        }

        void add_node_at_head(T value){
            Node<T>* new_node=new Node<T>(value);
            
            new_node->next=head;
            head->prev=new_node;
            
            head=new_node;
            
            tail->next=head;
            head->prev=tail;
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
                if(curr->next==tail){
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
            next_node->prev=prev_node;

            delete tmp_node;
        }
        
        void delete_node_at_head(void){
            if(head==NULL){
                cout<<"Linklist Does Not Rush"<<endl<<endl;
                return;
            }

            Node<T>* tmp_node=head;
            head=head->next;
            tail->next=head;
            head->prev=tail;
            
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
            head->prev=tail->next;

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
        void display_reverse(void){
            if(tail==NULL){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=tail;
            while(curr!=head){
                cout<<curr->data<<"->";
                curr=curr->prev;
            }
            cout<<curr->data<<"->";
            cout<<"repeat"<<endl;
            return;
        }

        void display_reverse(Node<T>* tail){
            if(tail==NULL){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=tail;
            while(curr!=head){
                cout<<curr->data<<"->";
                curr=curr->prev;
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
    list.display_reverse();
    cout<<endl<<endl;

    // // insert at end
    list.add_node_at_tail(-1);
    list.display();
    list.display_reverse();
    cout<<endl<<endl;

    // insert at start
    list.add_node_at_head(1);
    list.display();
    list.display_reverse();
    cout<<endl<<endl;

    // insert at pos
    list.add_node_at_pos(0,3);
    list.display();
    list.display_reverse();
    cout<<endl<<endl;

    // DELETE ADD HEAD
    list.delete_node_at_head();
    list.display();
    list.display_reverse();
    cout<<endl<<endl;

    // delete at tail
    // list.delete_node_at_tail();
    // list.display();
    // list.display_reverse();
    // cout<<endl<<endl;

    // delete node at any pos
    list.delete_node_at_pos(3);
    list.display();
    list.display_reverse();

    return 0;
}