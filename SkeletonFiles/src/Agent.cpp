#include "Agent.h"
#include <bits/stdc++.h>
using namespace std;


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),agentsParty(nullptr),start(true),isOriginal(true),pickingOrder()
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

Agent::~Agent()
{
    if(mSelectionPolicy) delete mSelectionPolicy;
    if(agentsParty) delete agentsParty;
}
Agent::Agent(const Agent &other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    start = other.start;
    isOriginal = other.isOriginal;
    pickingOrder = other.pickingOrder;
    agentsParty = new Party(*(other.agentsParty));//fix this
    mSelectionPolicy = new SelectionPolicy(*(other.mSelectionPolicy));//need to fix this
}

Agent& Agent::operator=(const Agent &other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;   
    start = other.start;
    isOriginal = other.isOriginal;
    pickingOrder = other.pickingOrder;
    *agentsParty = *(other.agentsParty);
    *mSelectionPolicy = *(other.mSelectionPolicy);
    return *this;
}

Agent::Agent(Agent&& other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    start = other.start;
    isOriginal = other.isOriginal;
    pickingOrder = other.pickingOrder;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    agentsParty = other.agentsParty;
    other.agentsParty = nullptr;   
}

Agent& Agent::operator=(Agent &&other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    start = other.start;
    isOriginal = other.isOriginal;
    pickingOrder = other.pickingOrder;
    if(mSelectionPolicy)
    {
        delete mSelectionPolicy;
    }
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    if(agentsParty)
    {
        delete agentsParty;
    }
    agentsParty = other.agentsParty;
    other.agentsParty = nullptr;   
    return *this;
}

void Agent::step(Simulation &sim)
{
    if (start)
    {
        *agentsParty = sim.getParty(mPartyId);
        start = false;
        if(isOriginal)
        {
            sim.addCoalition(Coalition(*this));
        }
        std::vector<std::pair<int,Party>> neighboors = sim.getGraph().getNeighboors(getParty());   
        for (int i = 1; i < neighboors.size(); i++)
        {
            std::pair<int,Party> value = neighboors[i];
            while (i>0 && (*mSelectionPolicy).Choose(value.second,neighboors[i-1].second,value.first,neighboors[i-1].first).getmId() != value.second.getmId())
            {
                neighboors[i] = neighboors[i-1];
                i=i-1;
            }
            neighboors[i] = value;
            
        }
        for(int i=0;i<neighboors.size();i++)
        {
            pickingOrder.push(neighboors[i].second);
        }

        
    }
    
    
}
