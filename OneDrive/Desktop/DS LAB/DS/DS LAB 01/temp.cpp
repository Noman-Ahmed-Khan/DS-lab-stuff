#include <iostream>

using namespace std;

namespace{
    struct Node{
        int data;
        Node* next=nullptr;

        Node(int value) : data(value){}
    };
}

void insert_at_tail(Node* &tail, int value){
    Node* new_node = new Node(value);
    tail->next = new_node;
    tail = new_node;
}

void insert_at_head(Node* &head, int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

void insert_at_pos(Node* &head, int pos,int value){
    
    Node* curr=head;
    int curr_cnt=0;

    if(pos<0){
        throw out_of_range("Invalid position");    
    } else if(pos==0){
        insert_at_head(head,value);
        return;
    } 


    while(curr_cnt<pos-1){
        if(curr->next==nullptr){
            throw out_of_range("Invalid position");
        }
        curr=curr->next;
        curr_cnt++;
    }
    Node* new_node=new Node(value);
    new_node->next=curr->next;
    curr->next=new_node;
}

void display_nodes(Node* head){
    Node* curr=head;

    while(curr->next!=nullptr){
        cout<<curr->data<<" -> ";
        curr=curr->next;
    }
    cout<<curr->data<<" -> ";    
    cout<<"nullptr"<<endl;
}


int main(){

    Node* head=new Node(5);
    Node* tail=head;

    insert_at_tail(tail, 9);
    insert_at_tail(tail, 10);
    
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    insert_at_head(head, 0);

    insert_at_pos(head,6,6);    
    insert_at_pos(head,7,7);    
    insert_at_pos(head,8,8);    

    insert_at_pos(head,0,-1);    
    
    display_nodes(head);

}