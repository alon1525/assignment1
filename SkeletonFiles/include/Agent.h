#pragma once
#include <vector>
#include "Graph.h"
#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"
#include "SelectionPolicy.h"
#include <queue>

using namespace std;
class Party;

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Party getParty() const;
    Coalition agentCoalition = Coalition(*this);
    bool isOriginal;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Party *agentsParty; 
    bool start;
    queue<Party> pickingOrder;
    
};
