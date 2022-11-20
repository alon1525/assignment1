#include "JoinPolicy.h"
#include <string>

using std::string;

int MandatesJoinPolicy::Choose(Party &aParty, Party &bParty)
{
    if (aParty.getMandates() > bParty.getMandates())
    {
        return aParty.getmId();
    }
    else if (aParty.getMandates() < bParty.getMandates())
    {
        return bParty.getmId();
    }
    else
    {
        if (bParty.getmId() < aParty.getmId())
        {
            return bParty.getmId();
        }
        else
        {
            return aParty.getmId();
        }
    }
}
int LastOfferJoinPolicy::Choose(Party &aParty, Party &bParty)
{
    return bParty.getmId();      
}