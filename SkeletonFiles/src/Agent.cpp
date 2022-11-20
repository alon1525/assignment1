#include "Agent.h"
using namespace std;

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),agentsParty(nullptr),start(true),isOriginal(true),neighboors()
{

}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

Party Agent::getParty() const
{
    return *agentsParty;
}
//RULE OF 5!!!
void Agent::step(Simulation &sim)
{
    if (start)
    {
        *agentsParty = sim.getParty(mPartyId);
        start = false;
        neighboors = sim.getGraph().getNeighboors(getParty());   
        sort(neighboors.begin,neighboors.end,mSelectionPolicy*.Choose())
    }
    
    
}
