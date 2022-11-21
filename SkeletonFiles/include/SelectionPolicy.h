#pragma once
#include "Party.h"

class SelectionPolicy
{
    public:
        SelectionPolicy();
        virtual ~SelectionPolicy();
        virtual Party Choose(Party &aParty,Party &bParty,int edgeWeight1,int edgeWeight2)=0;    
};

class MandatesSelectionPolicy : public SelectionPolicy 
{
    public:
        MandatesSelectionPolicy();
        Party Choose(Party &aParty,Party &bParty,int edgeWeight1,int edgeWeight2) override;
    
};

class EdgeWeightSelectionPolicy : public SelectionPolicy 
{
    public:
        EdgeWeightSelectionPolicy();
        Party Choose(Party &aParty,Party &bParty,int edgeWeight1,int edgeWeight2) override;
};