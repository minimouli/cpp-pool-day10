/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "AFruit.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"
#include "../fruits/Peach.hpp"

int main() {

    Peach blueberry;

    std::cout << blueberry << std::endl;
    std::cout << "name: " << blueberry.getName() << std::endl;
    std::cout << "vitamins: " << blueberry.getVitamins() << std::endl;
    std::cout << "is peeled: " << (blueberry.isPeeled() ? "true" : "false") << std::endl;

    blueberry.peel();

    std::cout << blueberry << std::endl;
    std::cout << "name: " << blueberry.getName() << std::endl;
    std::cout << "vitamins: " << blueberry.getVitamins() << std::endl;
    std::cout << "is peeled: " << (blueberry.isPeeled() ? "true" : "false") << std::endl;

    std::cout << "is AFruit ? " << (dynamic_cast<AFruit *>(new Peach) ? "true" : "false") << std::endl;
    std::cout << "is ABerry ? " << (dynamic_cast<ABerry *>(new Peach) ? "true" : "false") << std::endl;
    std::cout << "is ACitrus ? " << (dynamic_cast<ACitrus *>(new Peach) ? "true" : "false") << std::endl;
    std::cout << "is ANut ? " << (dynamic_cast<ANut *>(new Peach) ? "true" : "false") << std::endl;

    return 0;
}
