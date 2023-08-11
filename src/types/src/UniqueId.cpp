#include "UniqueId.h"

size_t UniqueId::id_count = 0;

UniqueId::UniqueId(void) : id_(UniqueId::id_count++) {
}

size_t UniqueId::id(void) const {
    return id_;
}

bool UniqueId::operator<(const UniqueId& rhs) const {
    return id_ < rhs.id();
}

bool UniqueId::operator>(const UniqueId& rhs) const {
    return id_ > rhs.id();
}

bool UniqueId::operator==(const UniqueId& rhs) const {
    return id_ == rhs.id();
}
