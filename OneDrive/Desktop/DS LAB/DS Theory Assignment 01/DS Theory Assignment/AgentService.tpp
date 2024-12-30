#include "AgentService.h"

        Agent::Agent() : id(0), agentName(""), assignedTickets(), availability(true){}; 
        Agent::Agent(int _id, string _agentName, bool _availability) : id(_id), agentName(_agentName), assignedTickets(), availability(_availability){}; 
        Agent::Agent(Agent& obj) : id(obj.id), agentName(obj.agentName), assignedTickets(), availability(obj.availability){
                D_Node<Ticket>* curr=obj.assignedTickets.get_head(); 
                while(curr){
                    assignedTickets.add_ticket(curr->data);
                    curr=curr->next;
                }
            
            }
        bool Agent::isAvailable(void){
            return availability;
        }
        void Agent::set_id(int id){
            this->id=id;
        }
        void Agent::set_agentName(string agentName){
            this->agentName=agentName;
        }
        void Agent::set_availability(bool availability){
            this->availability=availability;
        }
        
        
        int Agent::get_id(void){
            return this->id;
        }
        string Agent::get_agentName(void){
            return this->agentName;
        }
        bool Agent::get_availability(void){
            return this->availability;
        }

        void Agent::assignTickets(serviceTicket& tickets){
            if(tickets.isEmpty()) return;

            if(!availability) return;

            assignedTickets.add_ticket(tickets.get_firstTicket());
            
            tickets.remove_firstTicket();

            if(assignedTickets.get_ticketCount()>=maxTicketCount) availability=false;
            else availability=true;
        }
        
        void Agent::assignTickets(Queue<Ticket>& tickets){
            if(tickets.isEmpty()) return;
            if(!availability) return;

            assignedTickets.add_ticket(tickets.front());
            
            tickets.deQueue();

            if(assignedTickets.get_ticketCount()>=maxTicketCount) availability=false;
            else availability=true;
        }
        

        int Agent::get_assignedTicketsCount(void){
            return assignedTickets.get_ticketCount();
        }

        Agent& Agent::operator=(Agent& obj) {
            if (this!=&obj) {
                this->id = obj.id;
                this->availability = obj.availability;
                this->agentName = obj.agentName;

                assignedTickets = serviceTicket();

                D_Node<Ticket>* curr = obj.assignedTickets.get_head();
                while (curr) {
                    assignedTickets.add_ticket(curr->data);
                    curr=curr->next;
                }
            }
            return *this;
        }

                
        void Agent::display_assignedTickets(){
            assignedTickets.display();
        }

        void Agent::display(){
            cout<<"AGENT NAME: "<<agentName<<endl;
            cout<<"AGENT ID: "<<id<<endl;
            cout<<"AVAILABILTY: "<< ((availability)? "YES" : "NO")<<endl;
            cout<<"ASSIGNED CASES: "<<assignedTickets.get_ticketCount()<<endl;
        }
    serviceAgent::serviceAgent(){}
    void serviceAgent::countingSort(DynamicArray<Agent>& arr, bool ascending) {

        int freq[6]={0};

        for(int i=0; i<arr.size(); i++) freq[arr[i].get_assignedTicketsCount()]++;

        if (ascending) for(int i=1; i<6; i++) freq[i]+=freq[i-1];
        else for(int i=4; i>=0; i--) freq[i]+=freq[i + 1];
            
        

        DynamicArray<Agent> newArr(arr.size());

        for (int i=arr.size()-1; i>=0; i--){
            newArr[--freq[arr[i].get_assignedTicketsCount()]]=arr[i];

        } 
        for (int i=0; i<arr.size() ; i++){

            arr[i]=newArr[i];
        } 


    }



    void serviceAgent::add_agent(){   
        agentCount++;
        string agentName;

        cout<<"INPUT AGENT NAME: ";
        cin.ignore();
        getline(cin,agentName);

        Agent tmp;
        tmp.set_id(agentCount);
        tmp.set_agentName(agentName);
        tmp.set_availability(true);
        Agents.push_back(tmp);            
    }

    void serviceAgent::sort(bool ascending){
        countingSort(Agents,ascending);
    }
    void serviceAgent::add_agent(Agent obj){    
        string agentName;
        Agents.push_back(obj);            
    }


    void serviceAgent::assign_tickets(serviceTicket& tickets){
        
        tickets.sort(1);
        tickets.display();
        while (!tickets.isEmpty()) {
            int minIndex=-1;
            int minCount=INT_MAX;

            for (int j=0; j<Agents.size(); j++) {
                if(!Agents[j].isAvailable()) continue;
                int assignedCount=Agents[j].get_assignedTicketsCount();
                if (assignedCount<minCount) {
                    minCount=assignedCount;
                    minIndex=j; 
                }
            }

            if (minIndex!=-1) {
                Agents[minIndex].assignTickets(tickets);
            }
        }
    }
    
        void serviceAgent::assign_tickets(Queue<Ticket>& tickets){
        
        while (!tickets.isEmpty()) {
            int minIndex=-1;
            int minCount=INT_MAX;

            for (int j=0; j<Agents.size(); j++) {
                if(!Agents[j].isAvailable()) continue;
                int assignedCount=Agents[j].get_assignedTicketsCount();
                if (assignedCount<minCount) {
                    minCount=assignedCount;
                    minIndex=j; 
                }
            }

            if (minIndex!=-1) {
                Agents[minIndex].assignTickets(tickets);
            }
        }
    }

    void serviceAgent::display_assignedTickets(int index){
        Agents[index].display_assignedTickets();
    }

    void serviceAgent::display_assignedTickets(void){
        int id;
        cout<<"INPUT AGENT ID: ";
        cin>>id;
        int index=-1;
        for(int i=0 ; i<Agents.size() ; i++){
            if(Agents[i].get_id()==id){
                index=i;
                break;
            }
        }  
        if(index==-1){
            cout<<"WRONG NUMBER: "<<endl;
            return;
        }
        Agents[index].display_assignedTickets();
    }

    void serviceAgent::display(bool withAssignTickets){
        for(int i=0 ; i<Agents.size() ; i++){
            Agents[i].display();
            cout<<endl;
            if(withAssignTickets && Agents[i].get_assignedTicketsCount()>0){
                cout<<"Assigned Tickets: "<<endl;
                Agents[i].display_assignedTickets();
            }
        }
    }


    DynamicArray<Agent>& serviceAgent::get_array(void){
        return Agents;
    }
