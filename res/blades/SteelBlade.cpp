/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "SteelBlade.hpp"

SteelBlade::~SteelBlade() {}

unsigned int SteelBlade::operator()(const IFruit &fruit) const {
    return fruit.getVitamins();
}
