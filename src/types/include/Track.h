#pragma once
#include <Eigen/Dense>

#include "Density.h"
#include "Detection.h"

/**
 */
class Track {
   public:
    Track(const Density& density);
    Track(const Detection& detection);

   private:
    Density density_;
};
