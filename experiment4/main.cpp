#include <iostream>
#include <fstream>

#include "RandomNumberGenerator.hpp"
#include "Graph.hpp"

using namespace std;

#define K       50
#define N_MIN   1850
#define N_MAX   2000
#define N_STEP  50
 
int main() {
    ofstream output;
    output.open("lollipop5.txt");

    RandomNumberGenerator randomNumberGenerator = RandomNumberGenerator();

    for(unsigned int n = N_MIN; n <= N_MAX; n += N_STEP) {
        std::cout << n << std::endl;
        Graph graph = LollipopGraph(n);
        output << n;
        for(unsigned int k = 0; k < K; k++) {
            output << ", " << graph.runRandomWalkWithCoverage(n / 2, randomNumberGenerator);
        }
        output << "\n";
    }

    output.close();
 
    return 0;
}