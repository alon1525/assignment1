#pragma once

#include <vector>
#include "Graph.h"
#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"

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

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Party *agentsParty; 
    bool start;
    bool isOriginal;
    std::vector<Party> neighboors;
};
