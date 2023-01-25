/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Lemon.hpp"
#include "AFruit.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"

int main() {

    Lemon lemon;

    std::cout << lemon << std::endl;
    std::cout << "name: " << lemon.getName() << std::endl;
    std::cout << "vitamins: " << lemon.getVitamins() << std::endl;
    std::cout << "is peeled: " << (lemon.isPeeled() ? "true" : "false") << std::endl;

    lemon.peel();

    std::cout << lemon << std::endl;
    std::cout << "name: " << lemon.getName() << std::endl;
    std::cout << "vitamins: " << lemon.getVitamins() << std::endl;
    std::cout << "is peeled: " << (lemon.isPeeled() ? "true" : "false") << std::endl;

    std::cout << "is AFruit ? " << (dynamic_cast<AFruit *>(new Lemon) ? "true" : "false") << std::endl;
    std::cout << "is ABerry ? " << (dynamic_cast<ABerry *>(new Lemon) ? "true" : "false") << std::endl;
    std::cout << "is ACitrus ? " << (dynamic_cast<ACitrus *>(new Lemon) ? "true" : "false") << std::endl;
    std::cout << "is ANut ? " << (dynamic_cast<ANut *>(new Lemon) ? "true" : "false") << std::endl;

    return 0;
}
