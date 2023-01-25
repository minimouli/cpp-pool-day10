/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "IFruit.hpp"
#include "Hack.hpp"
#include "Almond.hpp"
#include "BloodOrange.hpp"
#include "Coconut.hpp"
#include "Grapefruit.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Raspberry.hpp"
#include "Strawberry.hpp"

int main() {

    IFruit *lemon = new Lemon();
    IFruit *orange = new Orange();
    IFruit *strawberry = new Strawberry();
    IFruit *almond = new Almond();
    IFruit *grapefruit = new Grapefruit();
    IFruit *bloodOrange = new BloodOrange();
    IFruit *raspberry = new Raspberry();
    IFruit *coconut = new Coconut();

    Hack *hackedLemon = reinterpret_cast<Hack *>(lemon);
    Hack *hackedOrange = reinterpret_cast<Hack *>(orange);
    Hack *hackedStrawberry = reinterpret_cast<Hack *>(strawberry);
    Hack *hackedAlmond = reinterpret_cast<Hack *>(almond);
    Hack *hackedGrapefruit = reinterpret_cast<Hack *>(grapefruit);
    Hack *hackedBloodOrange = reinterpret_cast<Hack *>(bloodOrange);
    Hack *hackedRaspberry = reinterpret_cast<Hack *>(raspberry);
    Hack *hackedCoconut = reinterpret_cast<Hack *>(coconut);

    lemon->peel();
    orange->peel();
    almond->peel();
    grapefruit->peel();
    bloodOrange->peel();
    coconut->peel();

    std::cout << *lemon << std::endl;
    hackedLemon->hack(125);
    std::cout << *lemon << std::endl;

    std::cout << *orange << std::endl;
    hackedOrange->hack(865);
    std::cout << *orange << std::endl;

    std::cout << *strawberry << std::endl;
    hackedStrawberry->hack(103);
    std::cout << *strawberry << std::endl;

    std::cout << *almond << std::endl;
    hackedAlmond->hack(792);
    std::cout << *almond << std::endl;

    std::cout << *grapefruit << std::endl;
    hackedGrapefruit->hack(303);
    std::cout << *grapefruit << std::endl;

    std::cout << *bloodOrange << std::endl;
    hackedBloodOrange->hack(742);
    std::cout << *bloodOrange << std::endl;

    std::cout << *raspberry << std::endl;
    hackedRaspberry->hack(903);
    std::cout << *raspberry << std::endl;

    std::cout << *coconut << std::endl;
    hackedCoconut->hack(834);
    std::cout << *coconut << std::endl;

    return 0;
}
