#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),timer(0),bestOffer(0) 
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

int Party::getmId() const
{
    return mId;
}

const string & Party::getName() const
{
    return mName;
}

void Party::recieveOffer(int agentId)
{
    if (mState==Waiting)
    {
        mState = CollectingOffers;
        bestOffer = agentId;
    }
    else if (mState==CollectingOffers)
    {
        //add when written join policy
    }
    
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
}
