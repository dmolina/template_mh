#pragma once

#include <problem.h>
#include <utility>

struct ResultMH {
  tSolution solution;
  tFitness fitness;
  unsigned int evaluations;

  ResultMH(tSolution &sol, tFitness fit, unsigned evals)
      : solution(sol), fitness(fit), evaluations(evals) {}
};

/**
 * Metaheuristic algorithm interface.
 *
 * @author  author
 * @version 1.0
 * @since   2021-05-01
 */
class MH {
public:
  virtual ~MH() {}
  /**
   * Run the metaheuristic algorithm to find the optimal solution.
   *
   * @param problem  The problem to solve.
   * @param maxevals The maximum number of evaluations.
   * @param theoric_min Early stops when the theoretical minimum fitness is found.
   * @return A pair containing the optimal solution and its fitness.
   * @throws Exception if the algorithm fails to converge.
   *
   * @since   2021-05-01
   * @author  author
   * @version 1.0
   */
  virtual ResultMH optimize(Problem *problem, int maxevals, tFitness theoric_min) = 0;
};
