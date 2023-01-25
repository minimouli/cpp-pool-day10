/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "MalfunctioningBlade.hpp"

MalfunctioningBlade::~MalfunctioningBlade() {}

unsigned int MalfunctioningBlade::operator()(const IFruit &fruit) const {
    return 0;
}
