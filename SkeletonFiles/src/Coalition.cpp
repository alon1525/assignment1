#include "Coalition.h"
#include <algorithm>

Coalition::Coalition(Agent firstAgent) : totalMandates(firstAgent.getParty().getMandates()),coalitionList(1,firstAgent.getPartyId()),offeredParties(),coalitionId(firstAgent.getPartyId())
{
    // You can change the implementation of the constructor, but not the signature!
}

int Coalition::getTotalMandates()
{
    return totalMandates;
}

int Coalition::getCoalitionId()
{
    return coalitionId;
}

void Coalition::addParty(Party party)
{
    coalitionList.push_back(party.getmId());
    totalMandates = totalMandates + party.getMandates();
}

void Coalition::addOfferedParty(int partyId)
{
    offeredParties.push_back(partyId);//if we have time we can make it more efficient by doing a binary search and sorting the vector
}

bool Coalition::hasBeenOffered(int partyId)
{
    if(std::find(offeredParties.begin(),offeredParties.end(),partyId) != offeredParties.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}