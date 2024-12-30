#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H

#include <iostream>
#include <ctime>
#include <limits>
#include <string>
#include "DoublyLinklist.h"
using namespace std;


class Ticket{
    private:
        int id, priority;
        string customerName,requestDescription;
        time_t creationTime, closeTime;
        bool status;
        
    public:
        Ticket();
        Ticket(int _id, int _priority, string _customerName,string _requestDescription, time_t _creationTime, time_t _closeTime, bool _status);
    	Ticket(const Ticket& obj);
   
        void set_id(int id);
        void set_priority(int priority);
        void set_customerName(string customerName);
        void set_requestDescription(string requestDescription);
        void set_creationTime(time_t creationTime);
        void set_closeTime(time_t closeTime);
        void set_status(bool status);

        int get_id(void);
        int get_priority(void);
        string get_customerName(void);
        string get_requestDescription(void);
        time_t get_creationTime(void);
        time_t get_closeTime(void);
        time_t get_status(void);

        void close_ticket(void);
        void ticket_details(void);



        Ticket operator= (const Ticket& obj);
};


class serviceTicket{
    private:
        D_Linklist<Ticket> ticket;
        int ticketCount;


        void swap(D_Node<Ticket>* D_NODE01, D_Node<Ticket>* D_NODE02);
        D_Node<Ticket>* partition(D_Node<Ticket>* low, D_Node<Ticket>* high, int choice);
        void quickSort(D_Node<Ticket>* low, D_Node<Ticket>* high,int choice);
    

    public:

        serviceTicket();

        Ticket add_ticket();
        void add_ticket(Ticket obj);
        
        int get_ticketPosition(int id);
        void remove_ticket(int id);
        Ticket search_ticket(int id);
        Ticket search_ticket(string name);

        void sort();
        void sort(int choice);

        
        bool isEmpty(void);
        
        int get_ticketCount(void);
        void display(void);
        void displayOpenTickets(void);

        Ticket get_firstTicket(void);
        void remove_firstTicket(void);
        D_Node<Ticket>*& get_head(void);
        D_Node<Ticket>*& get_tail(void);
};


#include "ServiceRequest.tpp"

#endif