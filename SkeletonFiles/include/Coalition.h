#pragma once

#include <vector>
#include "Party.h"
#include "Agent.h"

using std::vector;

class Coalition
{
public:
    Coalition(Agent firstAgent);
    void addParty(Party partyId);
    void addOfferedParty(int partyId);
    bool hasBeenOffered(int party);
    int getTotalMandates();
    int getCoalitionId();
private:
    int totalMandates;
    vector<int> coalitionList;
    vector<int> offeredParties;
    int coalitionId;
};