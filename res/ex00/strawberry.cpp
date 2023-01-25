/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Strawberry.hpp"
#include "AFruit.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"

int main() {

    Strawberry strawberry;

    std::cout << strawberry << std::endl;
    std::cout << "name: " << strawberry.getName() << std::endl;
    std::cout << "vitamins: " << strawberry.getVitamins() << std::endl;
    std::cout << "is peeled: " << (strawberry.isPeeled() ? "true" : "false") << std::endl;

    strawberry.peel();

    std::cout << strawberry << std::endl;
    std::cout << "name: " << strawberry.getName() << std::endl;
    std::cout << "vitamins: " << strawberry.getVitamins() << std::endl;
    std::cout << "is peeled: " << (strawberry.isPeeled() ? "true" : "false") << std::endl;

    std::cout << "is AFruit ? " << (dynamic_cast<AFruit *>(new Strawberry) ? "true" : "false") << std::endl;
    std::cout << "is ABerry ? " << (dynamic_cast<ABerry *>(new Strawberry) ? "true" : "false") << std::endl;
    std::cout << "is ACitrus ? " << (dynamic_cast<ACitrus *>(new Strawberry) ? "true" : "false") << std::endl;
    std::cout << "is ANut ? " << (dynamic_cast<ANut *>(new Strawberry) ? "true" : "false") << std::endl;

    return 0;
}
