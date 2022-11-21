#pragma once
#include <string>
#include "Party.h"
#include "Agent.h"

using std::string;
class Agent;

class JoinPolicy 
{
    public:
        JoinPolicy();
        virtual Agent Choose(Agent &aAgent,Agent &bAgent)=0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        Agent Choose(Agent &aAgent,Agent &bAgent) override;
    
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        Agent Choose(Agent &aAgent,Agent &bAgent) override;
};