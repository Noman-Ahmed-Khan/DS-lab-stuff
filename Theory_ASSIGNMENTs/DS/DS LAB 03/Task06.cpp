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
            head->prev=tail;
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
    
 
    void swap_nodes(int pos01,int pos02){
        if(head==tail){
            cout<<"List Too Short"<<endl;
            return;
        }


        int cnt01=0;
        int cnt02=0;
        Node<T>* node01=head;
        Node<T>* node02=head;

        while(cnt01<pos01 || cnt02<pos02){
            if(cnt01<pos01){
                node01=node01->next;
                cnt01++;
            }
            if(cnt02<pos02){
                node02=node02->next;
                cnt02++;    
            }
        }

        if (node01==head || node01==tail || node02==head || node02==tail) {
            if (node01==head && node02!=tail) {
                swap_head(pos02);
            } else if (node02==head && node01!=tail) {
                swap_head(pos01);
            } else if (node01==tail && node02!=head) {
                swap_tail(pos02);
            } else if (node02==tail && node01!=head) {
                swap_tail(pos01);
            } else if ((node01==head && node02==tail) || (node01==tail && node02==head)) {
                swap_head_tail();
            }
            return;
        }

        if(node01->next==node02 && node02->prev==node01){
            swap_adjacent(node01,node02);
        }

        if(node02->next==node01 && node01->prev==node02){
            swap_adjacent(node02,node01);
        }

        Node<T>* prev01=node01->prev;
        Node<T>* next01=node01->next;
        Node<T>* prev02=node02->prev;
        Node<T>* next02=node02->next;
        
        prev01->next=node02;
        next01->prev=node02;
        node02->next=next01;
        node02->prev=prev01;

        prev02->next=node01;
        next02->prev=node01;
        node01->next=next02;
        node01->prev=prev02;

    }

    void swap_head(int pos) {
        if (head==NULL) {
            cout<<"List is empty"<<endl;
            return;
        }

        if (pos==0) {
            cout<<"Position is the head, no swap needed."<<endl;
            return;
        }

        Node<T>* node01=head;
        Node<T>* node02=head;
        int cnt=0;
        
        while (cnt<pos) {
            node02=node02->next;
            cnt++;
        }

        if (node02==tail) {
            swap_head_tail();
            return;
        }

        Node<T>* prev01=node01->prev;
        Node<T>* prev02=node02->prev;
        Node<T>* next01=node01->next;
        Node<T>* next02=node02->next;

        
        prev01->next=node02;
        next01->prev=node02;
        node02->next=next01;
        node02->prev=prev01;

        prev02->next=node01;
        next02->prev=node01;
        node01->next=next02;
        node01->prev=prev02;

        head=node02;
        tail->next=head;
        head->prev=tail;
    }

    void swap_tail(int pos) {
        if (head==NULL) {
            cout<<"List is empty"<<endl;
            return;
        }

        if (pos==0) {
            swap_head_tail();
            return;
        }

        Node<T>* node01=head;
        Node<T>* node02=tail;
        int cnt=0;
        
        while (cnt<pos) {
            node01=node01->next;
            cnt++;
        }

        
        if (node01==head) {
            swap_head_tail();
            return;
        }

        if (node01==tail) {
            cout<<"Node is already the head."<<endl;
            return;
        }

        Node<T>* prev01=node01->prev;
        Node<T>* next01=node01->next;
        Node<T>* prev02=tail->prev;
        Node<T>* next02=tail->next;
        
        
        tail->next=next01;
        tail->prev=prev01;
        prev01->next=tail;
        next01->prev=tail;
        tail=node01;


        prev02->next=node01;
        next02->prev=node01;
        node01->next=next02;
        node01->prev=prev02;

    }

    void swap_head_tail() {
        if (head==NULL || head==tail) { 
            cout<<"List is too short to swap head and tail."<<endl;
            return;
        }

        Node<T>* temp_head=head;
        Node<T>* temp_tail=tail;

        Node<T>* prev_head=head->prev;
        Node<T>* next_head=head->next;
        Node<T>* prev_tail=tail->prev;
        Node<T>* next_tail=tail->next;

        head=temp_tail;
        tail=temp_head;


        head->next=next_head;
        head->prev=prev_head;
        next_head->prev=head;
        head->prev=tail;

        tail->next=next_tail;
        tail->prev=prev_tail;
        prev_tail->next=tail;
        tail->next=head;
    }

    void swap_adjacent(Node<T>* node1, Node<T>* node2) {
        if(node1==NULL || node2==NULL) {
            cout<<"Invalid nodes."<<endl;
            return;
        }

        if((node1==tail && node2==head) || (node2==tail && node1==head)) {
            swap_head_tail();
            return;
        }


        Node<T>* prev1=node1->prev;
        Node<T>* next2=node2->next;

        prev1->next=node2;
        next2->prev=node1;

        node2->prev=prev1;
        node2->next=node1;

        node1->prev=node2;
        node1->next=next2;

        if (node1==head) {
            head=node2;
        } else if (node2==tail) {
            tail=node1;
        }
    }

};

int main(){

    linklist<int> list;
    list.add_node_at_tail(1);
    list.add_node_at_tail(7);
    list.add_node_at_tail(4);
    list.add_node_at_tail(2);
    list.add_node_at_tail(6);
    list.add_node_at_tail(4);
    list.add_node_at_tail(5);
    list.add_node_at_tail(3);
    list.add_node_at_tail(9);
    list.add_node_at_tail(8);

    int pos01=0,pos02=0;
    cout<<"Input position 01: ";
    cin>>pos01;
    cout<<"Input position 02: ";
    cin>>pos02;

    cout<<endl<<"Before Swaping: "<<endl;
    list.display();
    list.display_reverse();
    cout<<endl;
    list.swap_nodes(pos01,pos02);
    cout<<endl<<"After Swaping: "<<endl;
    list.display();
    list.display_reverse();
    cout<<endl<<endl;

    return 0;
}
  
