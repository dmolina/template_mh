#pragma once
#include <mh.h>

/**
 * Trayectory-based metaheuristic algorithm interface.
 */
class MHTrayectory : public MH {
public:
  virtual ~MHTrayectory() {}
  /**
   * Run the Trayectory-based metaheuristic algorithm to find the optimal
   * solution.
   *
   * @param problem  The problem to solve.
   * @param maxevals The maximum number of evaluations.
   * @see MHTrayectory::optimize()
   */
  ResultMH optimize(Problem *problem, int maxevals) override {
    tSolution initial = problem->createSolution();
    tFitness fitness = problem->fitness(initial);
    return optimize(problem, initial, fitness, maxevals);
  }

public:
  /**
   * Run the Trayectory-based metaheuristic algorithm to find the optimal
   * solution starting from a given solution.
   *
   * @param problem  The problem to solve.
   * @param current The initial solution.
   * @param fitness The fitness of the initial solution.
   * @param maxevals The maximum number of evaluations.
   */
  virtual ResultMH optimize(Problem *problem, const tSolution &current,
                            tFitness fitness, int maxevals) = 0;
};
