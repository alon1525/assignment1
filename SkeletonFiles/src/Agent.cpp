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
//RULE OF 5!!!
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
