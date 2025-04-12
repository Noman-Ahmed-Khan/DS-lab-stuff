#include "Logs.h"


    Logs::Logs(){}
    // Time complexity: O(1) - Default constructor
    Logs::Logs(Stack<Ticket> _resolutionStack,Queue<Ticket> _pendingTicketQueue):resolutionStack(_resolutionStack),pendingTicketQueue(_pendingTicketQueue){};
    // Time complexity: O(1) - Constructor that initializes resolutionStack and pendingTicketQueue
    Logs::Logs(const Logs& obj) :resolutionStack(obj.resolutionStack),pendingTicketQueue(obj.pendingTicketQueue){};
    // Time complexity: O(1) - Copy constructor

    void Logs::set_resolutionStack(Stack<Ticket> resolutionStack){
        // Time complexity: O(1) - Setter for resolutionStack
        this->resolutionStack=resolutionStack;
    }
    void Logs::set_pendingTicketQueue(Queue<Ticket> pendingTicketQueue){
        // Time complexity: O(1) - Setter for pendingTicketQueue
        this->pendingTicketQueue=pendingTicketQueue;
    }


    Stack<Ticket>& Logs::get_resolutionStack(void){
        // Time complexity: O(1) - Getter for resolutionStack
        return resolutionStack;
    }
    Queue<Ticket>& Logs::get_pendingTicketQueue(void){
        // Time complexity: O(1) - Getter for pendingTicketQueue
        return pendingTicketQueue;
    }

    Logs& Logs::operator=(const Logs& other) {
        // Time complexity: O(1) - Assignment operator
        if (this == &other) {
            return *this;
        }
        
        resolutionStack = other.resolutionStack;
        pendingTicketQueue = other.pendingTicketQueue;

        return *this;
    }

    void Logs::log_CloseTicket(void){
        // Time complexity: O(1) - Dequeues from pendingTicketQueue, closes the ticket, and pushes it to resolutionStack
        Ticket resolved=pendingTicketQueue.deQueue();
        resolved.close_ticket();
        resolutionStack.push(resolved);
    }

    void Logs::add_pendingTicket(Ticket ticket){
        // Time complexity: O(log n) - Enqueues the ticket to pendingTicketQueue based on its priority
        pendingTicketQueue.enQueue(ticket,ticket.get_priority());
    }

    void Logs::display_pendingTickets(void) {
        // Time complexity: O(n) - Dequeues all pending tickets from the queue and displays their details
        Queue<Ticket> tmp = pendingTicketQueue;

        while (!tmp.isEmpty()) {
            Ticket ticket=tmp.deQueue(); 
            ticket.ticket_details();
            cout<<endl;
        }
    }


    void Logs::display_resolutionLogs(void){
        // Time complexity: O(n) - Pops all resolved tickets from the stack and displays their details
        Stack<Ticket> tmp=resolutionStack;
        while(!tmp.isEmpty()){
            tmp.top().ticket_details();
            tmp.pop();
            cout<<endl;
        }
    }
    Logs::~Logs() {}
    // Time complexity: O(1) - Destructor