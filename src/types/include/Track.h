#pragma once
#include <Eigen/Dense>

#include "Density.h"
#include "Detection.h"

/**
 */
class Track : public UniqueId {
   public:
    Track(const Density& density);
    Track(const Detection& detection);

    Eigen::Matrix<double, 6, 1> x() const;
    Eigen::Matrix<double, 6, 6> P() const;

   private:
    Density density_;
};
