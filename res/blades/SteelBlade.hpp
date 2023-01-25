/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef STEEL_BLADE_HPP
#define STEEL_BLADE_HPP

#include "IFruit.hpp"
#include "IFruitMixer.hpp"

class SteelBlade : public IFruitMixer::IBlade {
public:
    virtual ~SteelBlade();
    virtual unsigned int operator()(const IFruit &fruit) const;
};

#endif
