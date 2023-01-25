/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "FruitBox.hpp"
#include "FruitUtils.hpp"
#include "Almond.hpp"
#include "BloodOrange.hpp"
#include "Coconut.hpp"
#include "Grapefruit.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Raspberry.hpp"
#include "../fruits/Peach.hpp"

int main() {

    FruitBox unsorted(10);
    FruitBox lemons(10);
    FruitBox citruses(10);
    FruitBox berries(10);

    unsorted.pushFruit(new Lemon());
    unsorted.pushFruit(new Peach());
    unsorted.pushFruit(new Grapefruit());
    unsorted.pushFruit(new Raspberry());
    unsorted.pushFruit(new BloodOrange());
    unsorted.pushFruit(new Coconut());
    unsorted.pushFruit(new Lemon());
    unsorted.pushFruit(new Almond());
    unsorted.pushFruit(new Peach());
    unsorted.pushFruit(new Orange());

    std::cout << "before sort:" << std::endl;
    std::cout << " unsorted: " << unsorted << std::endl;
    std::cout << " lemons  : " << lemons << std::endl;
    std::cout << " citruses: " << citruses << std::endl;
    std::cout << " berries : " << berries << std::endl;

    FruitUtils::sort(unsorted, lemons, citruses, berries);

    std::cout << "after sort:" << std::endl;
    std::cout << " unsorted: " << unsorted << std::endl;
    std::cout << " lemons  : " << lemons << std::endl;
    std::cout << " citruses: " << citruses << std::endl;
    std::cout << " berries : " << berries << std::endl;

    return 0;
}
