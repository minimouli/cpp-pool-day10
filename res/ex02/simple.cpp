/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "FruitBox.hpp"
#include "FruitUtils.hpp"
#include "Lemon.hpp"
#include "../fruits/Peach.hpp"

int main() {

    FruitBox unsorted(2);
    FruitBox lemons(2);
    FruitBox citruses(2);
    FruitBox berries(2);

    unsorted.pushFruit(new Lemon());
    unsorted.pushFruit(new Peach());

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
