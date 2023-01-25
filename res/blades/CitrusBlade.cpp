/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "CitrusBlade.hpp"
#include "ACitrus.hpp"

CitrusBlade::~CitrusBlade() {}

unsigned int CitrusBlade::operator()(const IFruit &fruit) const {

    if (dynamic_cast<const ACitrus *>(&fruit) == nullptr) {
        return 0;
    }

    return fruit.getVitamins();
}
