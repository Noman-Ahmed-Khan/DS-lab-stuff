#include <iostream>

using namespace std;

template <typename T>
class Doubly_Node{
    public:
        T data;
        Doubly_Node<T>* next=NULL;
        Doubly_Node<T>* prev=NULL;
        Doubly_Node(int value=0):data(value){};
};

template <typename T>
class Singly_Node{
    public:
        T data;
        Singly_Node<T>* next=NULL;
        Singly_Node(int value=0):data(value){};
};
 

template <typename T>
class Doubly_linklist{
    private:
        Doubly_Node<T>* head;
        Doubly_Node<T>* tail;
    public:
        Doubly_linklist() : head(NULL), tail(head){}
        Doubly_linklist(int value) : head(new Doubly_Node<T>(value)), tail(head){}

        void add_Doubly_node_at_tail(T value){
            Doubly_Node<T>* new_Doubly_node=new Doubly_Node<T>(value);
            if(head==NULL){
                head=new_Doubly_node;
                tail=head;
                return;
            }
            tail->next=new_Doubly_node;
            new_Doubly_node->prev=tail;
            tail=new_Doubly_node;
            tail->next=head;
            head->prev=tail;
        }

        void add_Doubly_node_at_pos(T value,int pos){
            Doubly_Node<T>* new_Doubly_node=new Doubly_Node<T>(value);
            if(head==NULL){
                head=new_Doubly_node;
                tail=head;
                return;
            }
            if(pos==0){
                add_Doubly_node_at_head(value);
                return;
            }
            int count=0; Doubly_Node<T>* curr=head;
            while(count<pos-1 && curr!=tail){
                if(curr==tail){
                    cout<<"Error Wrong Position";
                    return;
                }
                curr=curr->next;
                count++;
            }
            if(curr==tail){
                add_Doubly_node_at_tail(value);
                return;
            }

            Doubly_Node<T>* prev_Doubly_node=curr;
            Doubly_Node<T>* next_Doubly_node=curr->next;
            
            prev_Doubly_node->next=new_Doubly_node;
            new_Doubly_node->prev=prev_Doubly_node->next;

            new_Doubly_node->next=next_Doubly_node;
            next_Doubly_node->prev=new_Doubly_node;
            
        }

        void add_Doubly_node_at_head(T value){
            Doubly_Node<T>* new_Doubly_node=new Doubly_Node<T>(value);
            
            new_Doubly_node->next=head;
            head->prev=new_Doubly_node;
            
            head=new_Doubly_node;
            
            tail->next=head;
            head->prev=tail;
            return;
        }

void delete_Doubly_node_at_pos(int pos){
            if(head==NULL){
                cout<<"Doubly_Linklist Does Not Rush"<<endl;
                return;
            }
            if(pos==0){
                delete_Doubly_node_at_head();
                return;
            }
            int count=0; Doubly_Node<T>* curr=head;
            while(count<pos-1){
                if(curr->next==tail){
                    cout<<"Error Wrong Position";
                    return;
                }
                curr=curr->next;
                count++;
            }
            if(curr->next==tail){
                delete_Doubly_node_at_tail();
                return;
            }
            Doubly_Node<T>* prev_Doubly_node=curr;
            Doubly_Node<T>* tmp_Doubly_node=curr->next;
            Doubly_Node<T>* next_Doubly_node=curr->next->next;
            
            prev_Doubly_node->next=next_Doubly_node;
            next_Doubly_node->prev=prev_Doubly_node;

            delete tmp_Doubly_node;
        }
        
        void delete_Doubly_node_at_head(void){
            if(head==NULL){
                cout<<"Doubly_Linklist Does Not Rush"<<endl<<endl;
                return;
            }

            Doubly_Node<T>* tmp_Doubly_node=head;
            head=head->next;
            tail->next=head;
            head->prev=tail;
            
            delete tmp_Doubly_node;
        }

        void delete_Doubly_node_at_tail(void){
            if(head==NULL){
                cout<<"Doubly_Linklist Does Not Rush"<<endl;
                return;
            }

            Doubly_Node<T>* tmp_Doubly_node=tail;
            Doubly_Node<T>* curr=head;
            while(curr->next!=tail){
                curr=curr->next;
            }
            tail=curr;
            tail->next=head;
            head->prev=tail->next;

            delete tmp_Doubly_node;
        }
       
        Doubly_Node<T>* get_head(void){
            return head;
        }
        
        Doubly_Node<T>* get_tail(void){
            return tail;
        }

        
        void set_tail(Doubly_Node<T>* tail){
            this->tail=tail;
            return;
        }        
        void set_head(Doubly_Node<T>* head){
            this->head=head;
            return;
        }
        
        void display(void){
            if(head==NULL){
                cout<<"Doubly_Linklist is empty"<<endl;
                return;
            }
            Doubly_Node<T>* curr=head;
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
                cout<<"Doubly_Linklist is empty"<<endl;
                return;
            }
            Doubly_Node<T>* curr=tail;
            while(curr!=head){
                cout<<curr->data<<"->";
                curr=curr->prev;
            }
            cout<<curr->data<<"->";
            cout<<"repeat"<<endl;
            return;
        }

        void display_reverse(Doubly_Node<T>* tail){
            if(tail==NULL){
                cout<<"Doubly_Linklist is empty"<<endl;
                return;
            }
            Doubly_Node<T>* curr=tail;
            while(curr!=head){
                cout<<curr->data<<"->";
                curr=curr->prev;
            }
            cout<<curr->data<<"->";
            cout<<"repeat"<<endl;
            return;
        }

        void display(Doubly_Node<T>* head){
            if(head==NULL){
                cout<<"Doubly_Linklist is empty"<<endl;
                return;
            }
            Doubly_Node<T>* curr=head;
            while(curr!=tail){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<curr->data<<"->";
            cout<<"repeat"<<endl;
            return;
        }

};



template <typename T>
class Singly_linklist{
    private:
        Singly_Node<T>* head;
        Singly_Node<T>* tail;
    public:
        Singly_linklist() : head(NULL), tail(head){}
        Singly_linklist(int value) : head(new Singly_Node<T>(value)), tail(head){}

        void add_Singly_node_at_tail(T value){
            Singly_Node<T>* new_Singly_node=new Singly_Node<T>(value);
            if(head==NULL){
                head=new_Singly_node;
                tail=head;
                return;
            }
            tail->next=new_Singly_node;
            tail=new_Singly_node;
        }

        void add_Singly_node_at_head(T value){
            Singly_Node<T>* new_Singly_node=new Singly_Node<T>(value);
            new_Singly_node->next=head;
            head=new_Singly_node;
            return;
        }

        Singly_Node<T>* get_head(void){
            return head;
        }
        
        Singly_Node<T>* get_tail(void){
            return tail;
        }

        
        void set_tail(Singly_Node<T>* tail){
            this->tail=tail;
            return;
        }        
        void set_head(Singly_Node<T>* head){
            this->head=head;
            return;
        }
        
        Singly_Node<T>* order_even_odd(void){
            Singly_linklist<T> even_list;
            Singly_linklist<T> odd_list;
            Singly_Node<T>* curr=head;

            while(curr!=NULL){
                if(curr->data%2==0){
                    even_list.add_Singly_node_at_tail(curr->data);
                } else {
                    odd_list.add_Singly_node_at_tail(curr->data);
                }
                curr=curr->next;
            }
            Singly_Node<T>* even_tail=even_list.get_tail();
            Singly_Node<T>* odd_head=odd_list.get_head();
            even_tail->next=odd_head;
            return even_list.get_head();    
        }

        void display(void){
            if(head==NULL){
                cout<<"Singly_Linklist is empty"<<endl;
                return;
            }
            Singly_Node<T>* curr=head;
            while(curr!=NULL){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"nullptr"<<endl;
            return;
        }

        void display(Singly_Node<T>* head){
             if(head==NULL){
                cout<<"Singly_Linklist is empty"<<endl;
                return;
            }
            Singly_Node<T>* curr=head;
            while(curr!=NULL){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"nullptr"<<endl;
            return;
        }

        
        Singly_linklist<T> convert_to_singly_list(Doubly_linklist<T> list){
            Doubly_Node<T>* doubly_curr=list.get_head();
            Doubly_Node<T>* doubly_tail=list.get_tail();
            
            Singly_linklist<T> new_list;

            if(doubly_curr==NULL){
                cout<<"Doubly list is empty"<<endl;
                return new_list;
            }

            while(doubly_curr!=doubly_tail){
                new_list.add_Singly_node_at_tail(doubly_curr->data);
                doubly_curr=doubly_curr->next;
            }
            new_list.add_Singly_node_at_tail(doubly_curr->data);
            
            
            return new_list;
        }
        
        Singly_linklist<T> operator =(Singly_linklist<T> list){
            this->head=list.head;
            return *this;
        }


};




int main(){

    Doubly_linklist<int> doubly_list;
    doubly_list.add_Doubly_node_at_tail(0);
    doubly_list.add_Doubly_node_at_tail(1);
    doubly_list.add_Doubly_node_at_tail(2);
    doubly_list.add_Doubly_node_at_tail(3);
    doubly_list.add_Doubly_node_at_tail(4);
    doubly_list.add_Doubly_node_at_tail(5);

    // display circular list
    doubly_list.display();
    doubly_list.display_reverse();
    cout<<endl<<endl;


    Singly_linklist<int> singly_list;
    singly_list=singly_list.convert_to_singly_list(doubly_list);
    singly_list.display();


    return 0;
}