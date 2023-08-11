#pragma once

#include "Hypothesis.h"

/**
 * A class descring a joint hypothesis.
 *
 */
class JointHypothesis {
   public:
    JointHypothesis(const std::vector<Hypothesis>& hypotheses);

    bool operator<(const Hypothesis& rhs) const;
    bool operator>(const Hypothesis& rhs) const;

#ifndef UNIT_TEST
   private:
#endif
    std::vector<Hypothesis> hypotheses_;
    double weight_;
};
