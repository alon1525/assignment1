#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),timer(0),bestOfferedAgent(nullptr) 
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

void Party::recieveOffer(Agent *agent)
{
    if (mState==Waiting)
    {
        mState = CollectingOffers;
        bestOfferedAgent = agent;
    }
    else if (mState==CollectingOffers)
    {
        bestOfferedAgent = mJoinPolicy*->choose(bestOfferedAgent,agent);//to ask how to write
    }
    
}
//we need to to RULE OF 5 here!!!
void Party::step(Simulation &s)
{
    // TODO: implement this method
}
