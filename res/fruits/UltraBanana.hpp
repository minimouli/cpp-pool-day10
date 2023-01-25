/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ULTRA_BANANA_HPP
#define ULTRA_BANANA_HPP

#include "IFruit.hpp"

class UltraBanana : public IFruit {
public:
    UltraBanana();
    virtual ~UltraBanana();

    virtual unsigned int getVitamins() const;
    virtual std::string getName() const;
    virtual bool isPeeled() const;
    virtual void peel();

    IFruit *clone() const;
};

#endif
