/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef IFRUIT_MIXER_HPP
#define IFRUIT_MIXER_HPP

#include "IFruit.hpp"
#include "FruitBox.hpp"

class IFruitMixer {
public:
    class IBlade {
    public:
        virtual ~IBlade() = default;
        virtual unsigned int operator()(const IFruit& fruit) const = 0;
    };

    virtual ~IFruitMixer() = default;
    virtual unsigned int mixFruits(FruitBox& box) const = 0;
    virtual void setBlade(IBlade* blade) = 0;
};

#endif
