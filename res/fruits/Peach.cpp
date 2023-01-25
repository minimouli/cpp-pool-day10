/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "Peach.hpp"

Peach::Peach() {}

Peach::~Peach() {}

unsigned int Peach::getVitamins() const {
    return 42;
}

std::string Peach::getName() const {
    return "peach";
}

bool Peach::isPeeled() const {
    return true;
}

void Peach::peel() {}

IFruit *Peach::clone() const {
    return new Peach();
}
