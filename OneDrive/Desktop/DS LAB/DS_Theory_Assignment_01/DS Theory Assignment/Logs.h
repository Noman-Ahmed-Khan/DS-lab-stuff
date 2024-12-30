#ifndef LOGS_H
#define LOGS_H

#include<iostream>
#include "ServiceRequest.h"
#include "PriorityQueue.h"
#include "Stack.h"


class Logs{
    private:
        Stack<Ticket> resolutionStack;
        Queue<Ticket> pendingTicketQueue;
    public:
        Logs();
        Logs(Stack<Ticket> _reslutionStack,Queue<Ticket> _pendingTicketQueue);
        Logs(const Logs& obj);
        
        void set_resolutionStack(Stack<Ticket> resolutionStack);
        void set_pendingTicketQueue(Queue<Ticket> pendingTicketQueue);


        Stack<Ticket>& get_resolutionStack(void);
        Queue<Ticket>& get_pendingTicketQueue(void);

        Logs& operator=(const Logs& other);
        void log_CloseTicket(void);
        void add_pendingTicket(Ticket ticket);

        void display_pendingTickets(void);
        void display_resolutionLogs(void);
        ~Logs();

};

#include "Logs.tpp"
#endif