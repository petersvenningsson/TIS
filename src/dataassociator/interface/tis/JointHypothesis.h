#pragma once

#include "Hypothesis.h"

namespace tis {

/**
 * A class descring a joint hypothesis.
 *
 */
class JointHypothesis {
   public:
    JointHypothesis(const std::vector<Hypothesis>& hypotheses);

    bool operator<(const JointHypothesis& rhs) const;
    bool operator>(const JointHypothesis& rhs) const;
    bool operator==(const JointHypothesis& rhs) const;

    std::vector<Hypothesis> hypotheses(void) const;
    bool isValid(void) const;
    double weight(void) const;

   private:
    std::vector<Hypothesis> hypotheses_;
    double weight_;
};

}  // namespace tis
