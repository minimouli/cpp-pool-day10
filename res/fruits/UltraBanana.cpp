/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "UltraBanana.hpp"

UltraBanana::UltraBanana() {
    std::cout << "ultra banana created" << std::endl;
}

UltraBanana::~UltraBanana() {
    std::cout << "ultra banana destroyed" << std::endl;
}

unsigned int UltraBanana::getVitamins() const {
    return 99;
}

std::string UltraBanana::getName() const {
    return "banana";
}

bool UltraBanana::isPeeled() const {
    return true;
}

void UltraBanana::peel() {}

IFruit *UltraBanana::clone() const {
    return new UltraBanana();
}
