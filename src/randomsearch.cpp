#include <cassert>
#include <randomsearch.h>

using namespace std;

/**
 * Create random solutions until maxevals has been achieved, and returns the
 * best one.
 *
 * @param problem The problem to be optimized
 * @param maxevals Maximum number of evaluations allowed
 * @param theoric_min Early stops when the theoretical minimum fitness is found.
 * @return A pair containing the best solution found and its fitness
 */
ResultMH RandomSearch::optimize(Problem *problem, int maxevals, tFitness theoric_min) {
  assert(maxevals > 0);
  tSolution best;
  tFitness best_fitness = -1;

  for (int i = 0; i < maxevals; i++) {
    tSolution solution = problem->createSolution();
    tFitness fitness = problem->fitness(solution);

    if (fitness < best_fitness || best_fitness < 0) {
      best = solution;
      best_fitness = fitness;
    }

    if (best_fitness == theoric_min) break;
    
  }

  return ResultMH(best, best_fitness, maxevals);
}
