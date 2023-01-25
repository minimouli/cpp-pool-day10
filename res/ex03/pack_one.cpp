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
#include "Orange.hpp"

int main() {

    IFruit *fruits[2] = {
        new Orange(),
        nullptr
    };

    std::cout << "before packing: " << std::endl;
    for (int i = 0; fruits[i] != nullptr; i++) {
        std::cout << " " << fruits[i]->getName() << std::endl;
    }

    FruitBox **fruitBoxes = FruitUtils::pack(fruits, 3);

    std::cout << "packed fruits: " << std::endl;
    for (int i = 0; fruitBoxes[i] != nullptr; i++) {
        std::cout << " " << *fruitBoxes[i] << std::endl;
    }

    return 0;
}
