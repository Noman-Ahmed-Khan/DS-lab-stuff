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
        }

        void add_node_at_head(T value){
            Node<T>* new_node=new Node<T>(value);
            new_node->next=head;
            head=new_node;
            return;
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
        
        Node<T>* order_even_odd(void){
            linklist<T> even_list;
            linklist<T> odd_list;
            Node<T>* curr=head;

            while(curr!=NULL){
                if(curr->data%2==0){
                    even_list.add_node_at_tail(curr->data);
                } else {
                    odd_list.add_node_at_tail(curr->data);
                }
                curr=curr->next;
            }
            Node<T>* even_tail=even_list.get_tail();
            Node<T>* odd_head=odd_list.get_head();
            even_tail->next=odd_head;
            return even_list.get_head();    
        }

        void display(void){
            if(head==NULL){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=head;
            while(curr!=NULL){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"nullptr"<<endl;
            return;
        }

        void display(Node<T>* head){
             if(head==NULL){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=head;
            while(curr!=NULL){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"nullptr"<<endl;
            return;
        }

};

int main(){

    linklist<int> list;
    list.add_node_at_tail(17);
    list.add_node_at_tail(15);
    list.add_node_at_tail(8);
    list.add_node_at_tail(12);
    list.add_node_at_tail(10);
    list.add_node_at_tail(5);
    list.add_node_at_tail(4);
    list.add_node_at_tail(1);
    list.add_node_at_tail(7);
    list.add_node_at_tail(6);

    list.display();
    Node<int>* ordered_list=list.order_even_odd();
    list.display(ordered_list);
    return 0;
}