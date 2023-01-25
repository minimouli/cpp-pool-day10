/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef BLUEBERRY_HPP
#define BLUEBERRY_HPP

#include "IFruit.hpp"

class Peach : public IFruit {
public:
    Peach();
    virtual ~Peach();

    virtual unsigned int getVitamins() const;
    virtual std::string getName() const;
    virtual bool isPeeled() const;
    virtual void peel();

    IFruit *clone() const;
};

#endif
