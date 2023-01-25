/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Banana.hpp"

Banana::Banana() {
    std::cout << "banana created" << std::endl;
}

Banana::~Banana() {
    std::cout << "banana destroyed" << std::endl;
}

unsigned int Banana::getVitamins() const {
    return 3;
}

std::string Banana::getName() const {
    return "banana";
}

bool Banana::isPeeled() const {
    return true;
}

void Banana::peel() {}

IFruit *Banana::clone() const {
    return new Banana();
}
