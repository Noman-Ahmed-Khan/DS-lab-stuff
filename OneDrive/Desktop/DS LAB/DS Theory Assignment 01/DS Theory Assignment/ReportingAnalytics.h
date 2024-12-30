#ifndef REPORTING_ANALYTICS_H
#define REPORTING_ANALYTICS_H

#include "ServiceRequest.h"
#include "AgentService.h"
#include "Logs.h"

class Analysis{
        private:
        public:
            Analysis();
            
            void listOpenTickets(serviceTicket& tickets);
            void listAgents(serviceAgent& agents);
            void ticketResolutionHistory(Logs& logs);

};
    #include "ReportingAnalytics.tpp"
#endif