/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "FruitBox.hpp"
#include "FruitMixer.hpp"
#include "BloodOrange.hpp"
#include "Coconut.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Strawberry.hpp"
#include "../blades/SteelBlade.hpp"

int main() {

    FruitBox box(5);
    FruitMixer mixer;
    SteelBlade blade;

    Lemon *lemon = new Lemon();
    BloodOrange *bloodOrange = new BloodOrange();
    Strawberry *strawberry = new Strawberry();
    Orange *orange = new Orange();
    Coconut *coconut = new Coconut();

    lemon->peel();
    bloodOrange->peel();
    orange->peel();
    coconut->peel();

    box.pushFruit(lemon);
    box.pushFruit(bloodOrange);
    box.pushFruit(strawberry);
    box.pushFruit(orange);
    box.pushFruit(coconut);

    unsigned int vitamins = mixer.mixFruits(box);
    std::cout << "vitamins: " << vitamins << std::endl;
    std::cout << "box: " << box << std::endl;

    mixer.setBlade(&blade);

    vitamins = mixer.mixFruits(box);
    std::cout << "vitamins: " << vitamins << std::endl;
    std::cout << "box: " << box << std::endl;

    return 0;
}
