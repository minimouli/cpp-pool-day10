/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef MALFUNCTIONING_BLADE_HPP
#define MALFUNCTIONING_BLADE_HPP

#include "IFruit.hpp"
#include "IFruitMixer.hpp"

class MalfunctioningBlade : public IFruitMixer::IBlade {
public:
    virtual ~MalfunctioningBlade();
    virtual unsigned int operator()(const IFruit &fruit) const;
};

#endif
