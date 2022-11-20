#pragma once
#include <string>
#include "Party.h"

using std::string;

class JoinPolicy 
{
    public:
        JoinPolicy();
        virtual int Choose(Party &aParty,Party &bParty)=0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        int Choose(Party &aParty,Party &bParty) override;
    
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        int Choose(Party &aParty,Party &bParty) override;
};