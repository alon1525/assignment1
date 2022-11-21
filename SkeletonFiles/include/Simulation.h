#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;
class Coalition;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addCoalition(Coalition coalition);
    vector<Coalition> mCoalitions;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    std::pair<int,int> max;//first is mandates number second id
};
