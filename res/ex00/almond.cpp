/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Almond.hpp"
#include "AFruit.hpp"
#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "ANut.hpp"

int main() {

    Almond almond;

    std::cout << almond << std::endl;
    std::cout << "name: " << almond.getName() << std::endl;
    std::cout << "vitamins: " << almond.getVitamins() << std::endl;
    std::cout << "is peeled: " << (almond.isPeeled() ? "true" : "false") << std::endl;

    almond.peel();

    std::cout << almond << std::endl;
    std::cout << "name: " << almond.getName() << std::endl;
    std::cout << "vitamins: " << almond.getVitamins() << std::endl;
    std::cout << "is peeled: " << (almond.isPeeled() ? "true" : "false") << std::endl;

    std::cout << "is AFruit ? " << (dynamic_cast<AFruit *>(new Almond) ? "true" : "false") << std::endl;
    std::cout << "is ABerry ? " << (dynamic_cast<ABerry *>(new Almond) ? "true" : "false") << std::endl;
    std::cout << "is ACitrus ? " << (dynamic_cast<ACitrus *>(new Almond) ? "true" : "false") << std::endl;
    std::cout << "is ANut ? " << (dynamic_cast<ANut *>(new Almond) ? "true" : "false") << std::endl;

    return 0;
}
