#include "ReportingAnalytics.h"

    Analysis::Analysis(){}
    
    void Analysis::listOpenTickets(serviceTicket& tickets){
        tickets.sort(2);
        tickets.displayOpenTickets();
    }

    void Analysis::listAgents(serviceAgent& agents){
        agents.sort(false);
        agents.display(true);
    }

    void Analysis::ticketResolutionHistory(Logs& logs){
        logs.display_resolutionLogs();
    }
