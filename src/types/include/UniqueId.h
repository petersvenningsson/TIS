#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

/**
 * A class describing a class which contains an id which is unique for all
 * instantiation of the class. Comparison operators are defined for the
 * unique id.
 *
 */
class UniqueId {
   public:
    UniqueId(void);

    /**
     * Checks if the elements in the std::vector<UniqueId> are unique.
     *
     * @param vector.
     * @returns true if elements in vector are unique.
     */
    template <typename T>
    bool static CheckUniqueness(std::vector<T>& vector) {
        std::sort(vector.begin(), vector.end());

        auto it = std::adjacent_find(vector.begin(), vector.end());
        if (it != vector.end()) {
            return false;
        } else {
            return true;
        }
    }

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
