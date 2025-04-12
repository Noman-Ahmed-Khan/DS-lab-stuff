#include <iostream>

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next=nullptr;
        Node<T>* prev=nullptr;
        Node(int value=0):data(value){};
};
 

template <typename T>
class linklist{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        linklist() : head(nullptr), tail(head){}
        linklist(int value) : head(new Node<T>(value)), tail(head){}

        void add_node_at_pos(T value,int pos){
            Node<T>* new_node=new Node<T>(value);
            if(head==nullptr){
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
            new_node->prev=prev_node->next;

            new_node->next=next_node;
            next_node->prev=new_node;
            
        }

        void add_node_at_head(T value){
            Node<T>* new_node=new Node<T>(value);
            
            new_node->next=head;
            head->prev=new_node;
            
            head=new_node;
            
            tail->next=head;
            head->prev=nullptr;
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
        
        void display(void){
            if(head==nullptr){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=head;
            while(curr){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"nullptr"<<endl;
            return;
        }
        void display_reverse(void){
            if(tail==nullptr){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=tail;
            while(curr){
                cout<<curr->data<<"->";
                curr=curr->prev;
            }
            cout<<"nullptr"<<endl;
            return;
        }

        void display_reverse(Node<T>* tail){
            if(tail==nullptr){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=tail;
            while(curr){
                cout<<curr->data<<"->";
                curr=curr->prev;
            }
            cout<<"nullptr"<<endl;
            return;
        }

        void display(Node<T>* head){
            if(head==nullptr){
                cout<<"Linklist is empty"<<endl;
                return;
            }
            Node<T>* curr=head;
            while(curr){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"nullptr"<<endl;
            return;
        }
    
        
        linklist<T> operator =(linklist<T> list){
            this->head=list.head;
            this->tail=list.tail;
            return *this;
        }

        void reverse(void){
            Node<T>* prevptr=nullptr;
            Node<T>* curr=head;
            while(curr->next){
                Node<T>* nextptr=curr->next;
                curr->prev=nextptr;                
                curr->next=prevptr;
                prevptr=curr;
                curr=nextptr;
            }
            
            tail=head;
            
            head=prevptr->prev;
            head->next=prevptr;

            head->prev=nullptr;
            tail->next=nullptr;
        }

        
        void add_node_at_tail(T value){
            Node<T>* new_node=new Node<T>(value);
            if(head==nullptr){
                head=new_node;
                tail=head;
                return;
            }
            tail->next=new_node;
            new_node->prev=tail;
            tail=new_node;
            tail->next=nullptr;
        }
        
        
        void delete_node_at_head(void){
            if(head==nullptr){
                cout<<"Linklist Does Not Rush"<<endl<<endl;
                return;
            }

            Node<T>* tmp_node=head;
            head=head->next;
            tail->next=head;
            head->prev=nullptr;
            
            delete tmp_node;
        }

        void delete_node_at_tail(void){
            if(head==nullptr){
                cout<<"Linklist Does Not Rush"<<endl;
                return;
            }

            Node<T>* tmp_node=tail;
            tail=tail->prev;
            tail->next=nullptr;
    
            delete tmp_node;
        }
        
        void delete_node(Node<T>* &node){
            if(head==nullptr){
                cout<<"Linklist Does Not Rush"<<endl;
                return;
            }
            if(node==head){
                delete_node_at_head();
                return;
            }
            if(node==tail){
                delete_node_at_tail();
                return;
            }

            Node<T>* tmp=node;
            Node<T>* prev=node->prev;
            Node<T>* next=node->next;
            
            prev->next=next;
            next->prev=prev;

            node=node->next;
            delete tmp;

        }
        
        void aternate_list(void){
            if(head==nullptr){
                cout<<"Linklist Does Not Rush"<<endl;
                return;
            }

            Node<T>* curr=head;
            int index=0;
            while(curr!=tail){
                Node<T>* next=curr->next;
                if(index++%2==1){
                    add_node_at_tail(curr->data);
                    delete_node(curr);
                }
                curr=next; 
            }
        }
        
        void get_user_input(void){
            bool stop=false; T value; char choice;
            system("cls");

            while(!stop){
                cout<<"Enter Node Value: ";
                cin>>value;
                add_node_at_tail(value);
                cout<<"Continue List: Y/N: ";
                cin>>choice;
                if(choice=='n' || choice=='N'){
                    stop=true;
                }
                system("cls");
            }
        }

};

int main(){
    linklist<int> list;

    list.get_user_input();

    list.aternate_list();
    list.display();
    
    return 0;
}