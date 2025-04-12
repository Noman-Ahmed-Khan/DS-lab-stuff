#ifndef AGENT_SERVICE_H
#define AGENT_SERVICE_H

#include<climits>
#include "ServiceRequest.h"
#include "Logs.h"
#include "DynamicArray.h"
#define maxTicketCount 5

class Agent{
    private:
        int id;
        string agentName;
        serviceTicket assignedTickets;
        bool availability;
    public:
        Agent(); 
        Agent(int _id, string _agentName, bool _availability); 
        Agent(Agent& obj);
        bool isAvailable(void);
        void set_id(int id);
        void set_agentName(string agentName);
        void set_availability(bool availability);
        
        int get_id(void);
        string get_agentName(void);
        bool get_availability(void);

        void assignTickets(serviceTicket& tickets);
        void assignTickets(Queue<Ticket>& tickets);
        
        int get_assignedTicketsCount(void);
        Agent& operator=(Agent& obj);
        void display_assignedTickets();
        void display();
};


class serviceAgent{
    private:
        DynamicArray<Agent> Agents;
        int agentCount;
        void countingSort(DynamicArray<Agent>& arr,bool ascending);
    public:
        serviceAgent();
        void add_agent();
        void add_agent(Agent obj);
        void assign_tickets(serviceTicket& tickets);
        void display_assignedTickets(int index);

        void display_assignedTickets(void);
        void sort(bool ascending);
        void assign_tickets(Queue<Ticket>& tickets);
        DynamicArray<Agent>& get_array(void);
        void display(bool withAssignTickets);
};


#include "AgentService.tpp"

#endif
