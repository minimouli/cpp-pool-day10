/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef CITRUS_BLADE_HPP
#define CITRUS_BLADE_HPP

#include "IFruit.hpp"
#include "IFruitMixer.hpp"

class CitrusBlade : public IFruitMixer::IBlade {
public:
    virtual ~CitrusBlade();
    virtual unsigned int operator()(const IFruit &fruit) const;
};

#endif
