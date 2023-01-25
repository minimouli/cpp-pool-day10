/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "FruitUtils.hpp"
#include "FruitBox.hpp"
#include "IFruit.hpp"
#include "Almond.hpp"
#include "BloodOrange.hpp"
#include "Coconut.hpp"
#include "Grapefruit.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Raspberry.hpp"
#include "../fruits/Peach.hpp"

int main() {

    IFruit *fruits[13] = {
        new Orange(),
        new Lemon(),
        new Grapefruit(),
        new Lemon(),
        new Peach(),
        new Almond(),
        new Raspberry(),
        new BloodOrange(),
        new Coconut(),
        new Grapefruit(),
        new Peach(),
        new Almond(),
        nullptr
    };

    std::cout << "before packing: " << std::endl;
    for (int i = 0; fruits[i] != nullptr; i++) {
        std::cout << " " << fruits[i]->getName() << std::endl;
    }

    FruitBox **fruitBoxes = FruitUtils::pack(fruits, 5);

    std::cout << "packed fruits: " << std::endl;
    for (int i = 0; fruitBoxes[i] != nullptr; i++) {
        std::cout << " " << *fruitBoxes[i] << std::endl;
    }

    return 0;
}
