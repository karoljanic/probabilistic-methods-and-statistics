#include "Graph.hpp"

Graph::Graph(unsigned int n) : 
    verticesNumber(n), adjacencyList(n, std::vector<unsigned int>()) { }

unsigned int Graph::runRandomWalkWithCoverage(unsigned int startVertex, RandomNumberGenerator& gen) {
    std::vector<unsigned int> visited(verticesNumber, 0);
    visited[startVertex] = 1;
    unsigned int toVisit = verticesNumber - 1;
    unsigned int moves = 0;
    unsigned int lastVertex = startVertex;

    while(toVisit > 0) {
        lastVertex = getRandomNeighbour(lastVertex, gen);
        if(visited.at(lastVertex) == 0) {
            visited.at(lastVertex) = 1;
            toVisit--;
        } 
        
        moves++;
    }

    return moves;
}

unsigned int Graph::getRandomNeighbour(unsigned int vertex, RandomNumberGenerator& gen) {
    const std::vector<unsigned int> neighbours = adjacencyList.at(vertex);

    return neighbours.at(gen.get(0, neighbours.size() - 1));
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for(unsigned int v1 = 0; v1 < graph.verticesNumber; v1++) {
        os << v1 << ": ";
        for(const unsigned int& neighbour : graph.adjacencyList.at(v1)) {
            os << neighbour << " ";
        }
        os << "\n";
    }
   
    return os;
}

Clique::Clique(unsigned int n) : Graph(n) {
    for(unsigned int v1 = 0; v1 < n; v1++) {
        for(unsigned int v2 = v1+1; v2 < n; v2++) {
            adjacencyList.at(v1).push_back(v2);
            adjacencyList.at(v2).push_back(v1);
        }
    }
}

PathGraph::PathGraph(unsigned int n) : Graph(n) {
    for(unsigned int v = 0; v < (n - 1); v++) {
        adjacencyList.at(v).push_back(v + 1);
        adjacencyList.at(v + 1).push_back(v);
    }
}

LollipopGraph::LollipopGraph(unsigned int n) : Graph(n) {
    unsigned int cliqueSize = 2 * n / 3;
    unsigned int pathSize = n - cliqueSize;

    for(unsigned int v1 = 0; v1 < cliqueSize; v1++) {
        for(unsigned int v2 = v1+1; v2 < cliqueSize; v2++) {
            adjacencyList.at(v1).push_back(v2);
            adjacencyList.at(v2).push_back(v1);
        }
    }

    for(unsigned int v = cliqueSize - 1; v < (n - 1); v++) {
        adjacencyList.at(v).push_back(v + 1);
        adjacencyList.at(v + 1).push_back(v);
    }
}

CompleteBinaryTree::CompleteBinaryTree(unsigned int n) : Graph(n) {
    std::queue<int> vertices;
    vertices.push(0);

    while (!vertices.empty()) {
        int v = vertices.front();
        vertices.pop();
        unsigned int v1 = 2 * v + 1;
        unsigned int v2 = 2 * v + 2;

        if (v1 < n) {
            adjacencyList.at(v).push_back(v1);
            adjacencyList.at(v1).push_back(v);
            vertices.push(v1);
        }
        if (v2 < n) {
            adjacencyList.at(v).push_back(v2);
            adjacencyList.at(v2).push_back(v);
            vertices.push(v2);
        }
    }
}