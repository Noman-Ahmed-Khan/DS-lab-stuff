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
        int size=0;
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
            size++;
        }

        void add_node_at_head(T value){
            Node<T>* new_node=new Node<T>(value);
            new_node->next=head;
            head=new_node;
            size++;
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

        bool check_palindrome(void){
            Node<T>* curr=head;
            int index, checking_size=size;
            
            while(curr!=NULL && checking_size!=size/2){
                Node<T>* last_node;
                last_node=curr;
                index=0;
                while(index<checking_size){
                    last_node=last_node->next;
                    index++;
                }
                if(curr->data!=last_node->data){
                    return false;
                }
                curr=curr->next;
                checking_size-=2;
            }
            
            return true;
        }

        int get_size(void){
            return size;
        }
        
        void set_size(int size){
            this->size=size;
            return;
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

    int type=0; bool flag;
    cout<<"What Type Of Data Type For Link List: 1) char, 2) int :";
    cin>>type;

    switch (type) {
        case 1: {
            linklist<char> list;  
            list.get_user_input();
            flag = list.check_palindrome();
            list.display();
            break;
        }
        case 2: {
            linklist<int> list;   
            list.get_user_input();
            flag = list.check_palindrome();
            list.display();
            break;
        }
        default:
            cout << "Wrong Choice" << endl;
            break;
    }
    
    if (flag){
        cout<<"Linklist Is A Palindrom";
    } else {
        cout<<"Linklist Is Not A Palindrom"   ;  
    }

    
    return 0;
}