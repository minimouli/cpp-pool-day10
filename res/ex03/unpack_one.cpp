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

    FruitBox *fruitBox1 = new FruitBox(3);
    fruitBox1->pushFruit(new Orange());

    FruitBox *fruitBoxes[2] = {
        fruitBox1,
        nullptr
    };

    std::cout << "before unpacking: " << std::endl;
    for (int i = 0; fruitBoxes[i] != nullptr; i++) {
        std::cout << " " << *fruitBoxes[i] << std::endl;
    }

    IFruit **fruits = FruitUtils::unpack(fruitBoxes);

    std::cout << "unpacked fruits: " << std::endl;
    for (int i = 0; fruits[i] != nullptr; i++) {
        std::cout << " " << fruits[i]->getName() << std::endl;
    }

    return 0;
}
