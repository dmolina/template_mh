#include <iostream>
#include <problem.h>
#include <random.hpp>
#include <string>
#include <util.h>
// Real problem class
#include "pincrem.h"

// All all algorithms
#include "brutesearch.h"
#include "randomsearch.h"

using namespace std;
int main(int argc, char *argv[]) {
  long int seed;

  // Seed the random number generator
  if (argc == 1) {
    // Use a fixed seed for reproducibility
    seed = 42;
  } else {
    seed = atoi(argv[1]);
  }

  RandomSearch ralg = RandomSearch();
  BruteSearch rbrute = BruteSearch();
  ProblemIncrem rproblem = ProblemIncrem(100);
  // Solve using evaluations
  vector<pair<string, MH *>> algoritmos = {make_pair("RandomSearch", &ralg),
                                           make_pair("BruteSearch", &rbrute)};
  Problem *problem = dynamic_cast<Problem *>(&rproblem);

  for (int i = 0; i < algoritmos.size(); i++) {
    Random::seed(seed);
    cout << algoritmos[i].first << endl;
    MH *mh = algoritmos[i].second;
    pair<tSolution, tFitness> result = mh->optimize(problem, 100);
    cout << "Best solution: " << result.first << endl
         << "Best fitness: " << result.second << endl;
  }

  return 0;
}
