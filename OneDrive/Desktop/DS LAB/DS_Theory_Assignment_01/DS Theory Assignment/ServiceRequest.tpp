
#include "ServiceRequest.h"




    Ticket::Ticket() : id(0), priority(0), customerName(""), requestDescription(""), creationTime(0), closeTime(0), status(false){}
    Ticket::Ticket(int _id, int _priority, string _customerName,string _requestDescription, time_t _creationTime, time_t _closeTime, bool _status) : id(_id), priority(_priority), customerName(_customerName), requestDescription(_requestDescription), creationTime(_creationTime), closeTime(_closeTime), status(_status){}
    Ticket::Ticket(const Ticket& obj)  : id(obj.id), priority(obj.priority), customerName(obj.customerName), requestDescription(obj.requestDescription), creationTime(obj.creationTime), closeTime(obj.closeTime), status(obj.status){}

    void Ticket::set_id(int id){
        this->id=id;
    }
    void Ticket::set_priority(int priority){
        this->priority=priority;
    }
    void Ticket::set_customerName(string customerName){
        this->customerName=customerName;
    }
    void Ticket::set_requestDescription(string requestDescription){
        this->requestDescription=requestDescription;
    }
    void Ticket::set_creationTime(time_t creationTime){
        this->creationTime=creationTime;
    }
    void Ticket::set_closeTime(time_t closeTime){
        this->closeTime=closeTime;
    }
    void Ticket::set_status(bool status){
        this->status=status;
    }

    int Ticket::get_id(void){
        return this->id;
    }
    int Ticket::get_priority(void){
        return this->priority;
    }

    string Ticket::get_customerName(void){
        return this->customerName;
    }
    string Ticket::get_requestDescription(void){
        return this->requestDescription;
    }
    time_t Ticket::get_creationTime(void){
        return this->creationTime;
    }
    time_t Ticket::get_closeTime(void){
        return this->closeTime;
    }
    time_t Ticket::get_status(void){
        return this->status;
    }

        void Ticket::close_ticket(void){
            status=false;
            closeTime=time(nullptr);
        }


    void Ticket::ticket_details(void){
        cout<<"TICKET ID: "<<id<<endl;
        cout<<"PRIORITY: "<<priority<<endl;
        cout<<"CUSTOMERE NAME: "<<customerName<<endl;
        cout<<"REQUEST DESCRIPTION: "<<requestDescription<<endl;
        cout<<"CREATION TIME: "<<ctime(&creationTime);
        cout<<"CLOSE TIME: "<< ((closeTime == 0) ? "Mon Jan 00 00:00:00 0000\n" : ctime(&closeTime));
        if(status) cout<<"STATUS: "<<"Processing"<<endl;
        else cout<<"STATUS: "<<"Processed"<<endl;
    }



    Ticket Ticket::operator= (const Ticket& obj){
        this->id=obj.id;
        this->priority=obj.priority;
        this->customerName=obj.customerName;
        this->requestDescription=obj.requestDescription;
        this->creationTime=obj.creationTime;
        this->closeTime=obj.closeTime;
        this->status=obj.status;

        return *this;
    }

    serviceTicket::serviceTicket(): ticketCount(0) {};

    void serviceTicket::swap(D_Node<Ticket>* D_NODE01, D_Node<Ticket>* D_NODE02){
        Ticket tmp=D_NODE01->data;
        D_NODE01->data=D_NODE02->data;
        D_NODE02->data=tmp;
    }

    D_Node<Ticket>* serviceTicket::partition(D_Node<Ticket>* low, D_Node<Ticket>* high, int choice){
        D_Node<Ticket>* pivot=high;
        D_Node<Ticket>* i=low;

        for (D_Node<Ticket>* j=low; j!=high; j=j->next) {
            bool condition=false;
            if (choice==1) condition=(j->data.get_priority()>pivot->data.get_priority());
            else if(choice==2) condition=(j->data.get_creationTime()<=pivot->data.get_creationTime());
            else condition=(j->data.get_customerName()<=pivot->data.get_customerName());
            
            if(condition){
                swap(i, j);
                i=i->next;
            }
        }
        swap(i, high);
        return i;
    }

    void serviceTicket::quickSort(D_Node<Ticket>* low, D_Node<Ticket>* high,int choice){

        if (low==nullptr || low==high || low==high->next) return;
        D_Node<Ticket>* pi=partition(low,high,choice);
        
        quickSort(low,pi->prev,choice);
        quickSort(pi->next,high,choice);
    }



    Ticket serviceTicket::add_ticket(){
        ticketCount++;
        Ticket tmp;
        string textData;
        int priority;
        cout<<"INPUT YOUR NAME: ";
        cin.ignore();   
        getline(cin,textData);
        tmp.set_customerName(textData);
        
        cout<<"INPUT PROBLEM DESCRIPTION: ";
        cin.ignore();   
        getline(cin,textData);
        tmp.set_requestDescription(textData);
        
        cout<<"INPUT PROBLEM PRIORITY: ";
        cin>>priority;
        tmp.set_priority(priority);

        tmp.set_creationTime(time(nullptr));
        tmp.set_id(ticketCount);
        tmp.set_status(true);

        ticket.add_node_at_tail(tmp);
        return tmp;
    }
    int serviceTicket::get_ticketPosition(int id){
        D_Node<Ticket>* curr=ticket.get_head();
        int count=0;
        while(curr && curr->data.get_id()!=id){
            curr=curr->next;
            count++;
        } 
        if(!curr) return -1;
        return count; 
    }
    void serviceTicket::add_ticket(Ticket obj){
        ticketCount++;
        ticket.add_node_at_tail(obj);
    }

    void serviceTicket::remove_ticket(int id){
        if(ticketCount<1){
            cout<<"NO TICKETS AVAILABLE TO BE REMOVED"<<endl;
            return;
        }
        int ticketPosition=get_ticketPosition(id);
        if(ticketPosition==-1){
            cout<<"INVALID TICKET ID"<<endl;
            return;
        }      
        ticket.remove_node_at_pos(ticketPosition);
        ticketCount--;
    }

    Ticket serviceTicket::search_ticket(int id){
        D_Node<Ticket>* curr=ticket.get_head();
        while(curr && curr->data.get_id()!=id){
            curr=curr->next;
        } 
        if(!curr){
            cout<<"INVALID TICKET ID"<<endl;
            return Ticket();
        }
        return curr->data;    
    }

    Ticket serviceTicket::search_ticket(string name){
        D_Node<Ticket>* curr=ticket.get_head();
        while(curr && curr->data.get_customerName()!=name){
            curr=curr->next;
        } 
        if(!curr){
            cout<<"INVALID TICKET CUSTOMER NAME"<<endl;
            return Ticket();
        }
        return curr->data;    
    }

    void serviceTicket::sort(){
        int choice;
        cout<<endl<<"PLEASE CHOOSE SORTING CONDITION:"<<endl<<"1) SORT ON PRIORITY"
        <<endl<<"2) SORT ON CREATION TIME"<<endl<<"3) SORT ON CUSTOMER NAME"<<endl
        <<"CHOICE (1,2,3): ";
        cin>>choice;
        if(choice<1 || choice>3){
            cout<<"WRONG CHOICE";
            return;
        }
        quickSort(ticket.get_head(),ticket.get_tail(),choice);
    }

        void serviceTicket::sort(int choice){
        if(choice<1 || choice>3){
            cout<<"WRONG CHOICE";
            return;
        }
        quickSort(ticket.get_head(),ticket.get_tail(),choice);
    }

    int serviceTicket::get_ticketCount(void){
        return ticketCount;
    }

    bool serviceTicket::isEmpty(void){
        return ticketCount<1;
    }

    void serviceTicket::display(void){
        D_Node<Ticket>* curr=ticket.get_head();
        while(curr){
            curr->data.ticket_details();
            cout<<endl;
            curr=curr->next;
        }
    }

    void serviceTicket::displayOpenTickets(){
        D_Node<Ticket>* curr=ticket.get_head();
        while(curr && curr->data.get_status()){
            curr->data.ticket_details();
            cout<<endl;
            curr=curr->next;
        }
    }


    Ticket serviceTicket::get_firstTicket(void){
        return ticket.get_head()->data;
    }
    
    D_Node<Ticket>*& serviceTicket::get_head(void){
        return ticket.get_head();
    }
    
    D_Node<Ticket>*& serviceTicket::get_tail(void){
        return ticket.get_tail();
    }
    
    void serviceTicket::remove_firstTicket(void){
        if(ticketCount<1) return;
        ticket.remove_node_at_head();
        ticketCount--;
    }
    
