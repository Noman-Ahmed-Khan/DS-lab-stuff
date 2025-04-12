#include<iostream>
// #include<string>
#include<ctime>
#include"AgentService.h"
#include"ServiceRequest.h"
#include"SortingSearchingMethods.h"
#include"Logs.h"
#include"ReportingAnalytics.h"

using namespace std;


int main(){
    Config configuration;
    configuration.load("configuration_file.txt");
    DynamicArray<Pair<string,string>> pairs=configuration.get_keyValuePair();
    SortingSearchingAlgorithm algorithm(pairs);
    int choice=0;
    while(true){
        cout<<"LOG IN:"<<endl;
        cout<<"1) STUDENT"<<endl;
        cout<<"2) ADMINISTRATION"<<endl;
        cout<<"3) SERVICE LOGS"<<endl;
        cout<<"4) REPORTING AND ANALYTICS"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        serviceTicket tickets;
        serviceAgent agents;
        Logs log;
        Analysis analysis;

        if(choice==1){
            while(true){
                int studentChoice=0;
                system("cls");
                cout<<"1) REQUEST COMPLAIN TICKET"<<endl;
                cout<<"2) DISPLAY ALL TICKET"<<endl;
                cout<<"3) REQUEST TICKET POSITION"<<endl;
                cout<<"4) REQUEST A TICKET DATA"<<endl;
                cout<<"5) REMOVE TICKET"<<endl;
                cout<<"6) SORT TICKETS"<<endl;
                cout<<"7) REQUEST A TICKET DATA(URGENT)"<<endl;
                cout<<"8) Exit"<<endl;
                cout<<"CHOICE: ";
                cin>>studentChoice;
                if(studentChoice==1)log.add_pendingTicket(tickets.add_ticket());
                else if(studentChoice==2){
                    tickets.sort(2);
                    tickets.display();
                }else if(studentChoice==3){
                    int id;
                    cout<<"INPUT TICKET ID: ";
                    cin>>id;
                    cout<<"Ticket Position: "<<tickets.get_ticketPosition(id);
                }else if(studentChoice==4){
                    string name;
                    int id;
                    cout<<"DO YOU HAVE TICKET 1)ID OR 2)NAME:";
                    cin>>id;
                    if(id==1){
                        cout<<"INPUT TICKET ID: ";
                        cin>>id;
                        Ticket tk=tickets.search_ticket(id);
                        tk.ticket_details();
                    }else if(id==2){
                        cout<<"INPUT TICKET NAME: ";
                        cin>>name;
                        Ticket tk=tickets.search_ticket(name);
                        tk.ticket_details();
                    }
                }else if(studentChoice==5){
                    int id;
                    cout<<"INPUT TICKET ID: ";
                    cin>>id;
                    tickets.remove_ticket(id);
                }else if(studentChoice==6){
                    D_Node<Ticket>* left=tickets.get_head();
                    D_Node<Ticket>* right=tickets.get_tail();
                    algorithm.sort(left,right,tickets.get_ticketCount(),2);
                    cout<<"DATA SORTED USING "<<algorithm.get_sortingAlgorithm()<<endl;
                    getchar();
                }else if(studentChoice==7){
                    int id;
                    cout<<"INPUT TICKET ID: ";
                    cin>>id;
                    // algorithm.(searchingAlgorithm,id);
                }else if(studentChoice==8)break;
                int dummy;
                cout<<endl<<"Press any number to continue: ";
                cin>>dummy;
            }   
            system("cls");
        }else if(choice==2){
            system("cls");
            while(true){
                int agentChoice=0;
                system("cls");
                cout<<"1) ADD AGENT"<<endl;
                cout<<"2) ASSIGN TICKETS"<<endl;
                cout<<"3) DISPLAY AGENTS AND THEIR ASSIGNED TICKETS"<<endl;
                cout<<"4) DISPLAY TICKETS IN PROCESS WITH AGENTS"<<endl;
                cout<<"5) SORT Agents"<<endl;
                cout<<"6) EXIT"<<endl;
                cout<<"CHOICE: ";
                cin>>agentChoice;
                if(agentChoice==1)agents.add_agent();
                else if(agentChoice==2)agents.assign_tickets(log.get_pendingTicketQueue());
                else if(agentChoice==3)agents.display(true);
                else if(agentChoice==4)agents.display_assignedTickets();
                else if(agentChoice==5){
                    agents.sort(false);
                }
                else if(agentChoice==6)break;
                int dummy;
                cout<<endl<<"Press any number to continue: ";
                cin>>dummy;
            }
            system("cls");
        }else if(choice==3){
            while(true){
                int logChoice=0;
                system("cls");
                cout<<"1) ADD TICKET ON PRIORITY"<<endl;
                cout<<"2) DISPLAY PENDING TICKETS"<<endl;
                cout<<"3) DISPLAY RESOLVED TICKETS"<<endl;
                cout<<"4) CLOSE TICKETS"<<endl;
                cout<<"5) EXIT"<<endl;
                cout<<"CHOICE: ";
                cin>>logChoice;
                if(logChoice==1)log.add_pendingTicket(tickets.add_ticket());
                else if(logChoice==2)log.display_pendingTickets();
                else if(logChoice==3)log.display_resolutionLogs();
                else if(logChoice==4)log.log_CloseTicket();
                else if(logChoice==5)break;
                int dummy;
                cout<<endl<<"Press any number to continue: ";
                cin>>dummy;
            }
            system("cls");
        }else if(choice==4){
            while(true){
                system("cls");
                int analysisChoice=0;
                cout<<"1) ADD TICKET ON PRIORITY"<<endl;
                cout<<"2) DISPLAY PENDING TICKETS"<<endl;
                cout<<"3) DISPLAY RESOLVED TICKETS"<<endl;
                cout<<"4) EXIT"<<endl;
                cout<<"CHOICE: ";
                cin>>analysisChoice;
                if(analysisChoice==1)analysis.listAgents(agents);
                else if(analysisChoice==2)analysis.listOpenTickets(tickets);
                else if(analysisChoice==3)analysis.ticketResolutionHistory(log);
                else if(analysisChoice==4)break;
                int dummy;
                cout<<endl<<"Press any number to continue: ";
                cin>>dummy;
            }
            system("cls");
        }else if(choice==5)break;
    }
    return 0;
}