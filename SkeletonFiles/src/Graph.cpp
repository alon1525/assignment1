#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

const std::vector<Party> Graph::getNeighboors(Party curr) const
{
    std::vector<Party> a = std::vector<Party>();
    for(Party ver : mVertices)
    {
        if (ver.getmId() != curr.getmId())
        {
            if (getEdgeWeight(curr.getmId(),ver.getmId())>0)
            {
                a.push_back(ver);
            }
            
        }
        
    }
    return a;
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}


int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}