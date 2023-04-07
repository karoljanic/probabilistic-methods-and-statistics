#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <queue>
#include <ostream>

#include "RandomNumberGenerator.hpp"

class Graph {
protected:
    unsigned int verticesNumber;
    std::vector<std::vector<unsigned int>> adjacencyList;

public:
    Graph(unsigned int n);
    unsigned int runRandomWalkWithCoverage(unsigned int startVertex, RandomNumberGenerator& gen);

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

private:
    unsigned int getRandomNeighbour(unsigned int vertex, RandomNumberGenerator& gen);
};


class Clique : public Graph {
public:
    Clique(unsigned int n);
};


class PathGraph : public Graph {
public:
    PathGraph(unsigned int n);
};


class LollipopGraph : public Graph {
public:
    LollipopGraph(unsigned int n);
};


class CompleteBinaryTree : public Graph {
public:
    CompleteBinaryTree(unsigned int n);
};


#endif // GRAPH_HPP