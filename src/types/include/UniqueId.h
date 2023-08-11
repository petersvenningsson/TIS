#pragma once

#include <cstddef>

/**
 * A class describing a class which contains an id which is unique for all
 * instantiation of the class. Comparison operators are defined for the
 * unique id.
 *
 */
class UniqueId {
   public:
    UniqueId(void);
    bool operator<(const UniqueId& rhs) const;
    bool operator>(const UniqueId& rhs) const;
    bool operator==(const UniqueId& rhs) const;

    size_t id(void) const;
#ifndef UNIT_TEST
   protected:
#endif

    static size_t id_count;
    size_t id_;
};
