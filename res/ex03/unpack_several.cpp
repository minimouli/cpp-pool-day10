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
#include "Almond.hpp"
#include "BloodOrange.hpp"
#include "Coconut.hpp"
#include "Grapefruit.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Raspberry.hpp"
#include "../fruits/Peach.hpp"

int main() {

    FruitBox *fruitBox1 = new FruitBox(5);
    FruitBox *fruitBox2 = new FruitBox(5);
    FruitBox *fruitBox3 = new FruitBox(5);

    fruitBox1->pushFruit(new Orange());
    fruitBox1->pushFruit(new Lemon());
    fruitBox1->pushFruit(new Grapefruit());
    fruitBox1->pushFruit(new Lemon());
    fruitBox1->pushFruit(new Peach());

    fruitBox2->pushFruit(new Almond());
    fruitBox2->pushFruit(new Raspberry());
    fruitBox2->pushFruit(new BloodOrange());
    fruitBox2->pushFruit(new Coconut());
    fruitBox2->pushFruit(new Grapefruit());

    fruitBox3->pushFruit(new Peach());
    fruitBox3->pushFruit(new Almond());

    FruitBox *fruitBoxes[4] = {
        fruitBox1,
        fruitBox2,
        fruitBox3,
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
