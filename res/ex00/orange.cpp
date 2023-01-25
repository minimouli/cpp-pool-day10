/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Orange.hpp"
#include "AFruit.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"

int main() {

    Orange orange;

    std::cout << orange << std::endl;
    std::cout << "name: " << orange.getName() << std::endl;
    std::cout << "vitamins: " << orange.getVitamins() << std::endl;
    std::cout << "is peeled: " << (orange.isPeeled() ? "true" : "false") << std::endl;

    orange.peel();

    std::cout << orange << std::endl;
    std::cout << "name: " << orange.getName() << std::endl;
    std::cout << "vitamins: " << orange.getVitamins() << std::endl;
    std::cout << "is peeled: " << (orange.isPeeled() ? "true" : "false") << std::endl;

    std::cout << "is AFruit ? " << (dynamic_cast<AFruit *>(new Orange) ? "true" : "false") << std::endl;
    std::cout << "is ABerry ? " << (dynamic_cast<ABerry *>(new Orange) ? "true" : "false") << std::endl;
    std::cout << "is ACitrus ? " << (dynamic_cast<ACitrus *>(new Orange) ? "true" : "false") << std::endl;
    std::cout << "is ANut ? " << (dynamic_cast<ANut *>(new Orange) ? "true" : "false") << std::endl;

    return 0;
}
