/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "FruitBox.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "../fruits/Peach.hpp"

int main() {

    FruitBox fruitBox(3);

    std::cout << "size: " << fruitBox.getSize() << std::endl;
    std::cout << "fruits: " << fruitBox.nbFruits() << std::endl;

    std::cout << "push lemon: " << (fruitBox.pushFruit(new Lemon()) ? "true" : "false") << std::endl;
    std::cout << "push orange: " << (fruitBox.pushFruit(new Orange()) ? "true" : "false") << std::endl;
    std::cout << "push peach: " << (fruitBox.pushFruit(new Peach()) ? "true" : "false") << std::endl;

    std::cout << fruitBox << std::endl;
    std::cout << "size: " << fruitBox.getSize() << std::endl;
    std::cout << "fruits: " << fruitBox.nbFruits() << std::endl;

    return 0;
}
