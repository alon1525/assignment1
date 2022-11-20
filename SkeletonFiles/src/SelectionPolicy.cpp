#include "SelectionPolicy.h"

#include <string>

using std::string;

Party MandatesSelectionPolicy::Choose(Party &aParty, Party &bParty,int edgeWeight1,int edgeWeight2)
{
    if (aParty.getMandates() > bParty.getMandates())
    {
        return aParty;
    }
    else if (aParty.getMandates() < bParty.getMandates())
    {
        return bParty;
    }
    else
    {
        if (bParty.getmId() < aParty.getmId())
        {
            return bParty;
        }
        else
        {
            return aParty;
        }
    }
}
Party EdgeWeightSelectionPolicy::Choose(Party &aParty, Party &bParty,int edgeWeight1,int edgeWeight2)
{
    if (edgeWeight1>edgeWeight2)
    {
        return aParty;
    }
    else if(edgeWeight2>edgeWeight1)
    {
        return bParty;
    }
    else
    {
        if (bParty.getmId() < aParty.getmId())
        {
            return bParty;
        }
        else
        {
            return aParty;
        }
    }      
}