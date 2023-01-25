/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "FruitFactory.hpp"
#include "Grapefruit.hpp"
#include "Lemon.hpp"
#include "Raspberry.hpp"
#include "../fruits/Banana.hpp"
#include "../fruits/Peach.hpp"
#include "../fruits/UltraBanana.hpp"

int main() {

    FruitFactory factory;

    Lemon *lemon = new Lemon();
    Peach *peach = new Peach();
    Grapefruit *grapefruit = new Grapefruit();
    Raspberry *raspberry = new Raspberry();

    std::cout << "register: " << *lemon << std::endl;
    factory.registerFruit(lemon);

    std::cout << "create: " << *factory.createFruit("lemon") << std::endl;

    std::cout << "register: " << *peach << std::endl;
    factory.registerFruit(peach);
    std::cout << "register: " << *grapefruit << std::endl;
    factory.registerFruit(grapefruit);
    std::cout << "register: " << *raspberry << std::endl;
    factory.registerFruit(raspberry);

    Banana *banana = new Banana();
    std::cout << "register: " << *banana << std::endl;
    factory.registerFruit(banana);

    std::cout << "create: " << *factory.createFruit("grapefruit") << std::endl;
    std::cout << "create: " << *factory.createFruit("peach") << std::endl;
    std::cout << "create: " << *factory.createFruit("peach") << std::endl;
    std::cout << "create: " << (factory.createFruit("coconut") == nullptr ? "nullptr" : "wtf?") << std::endl;

    std::cout << "unregister: " << *grapefruit << std::endl;
    factory.unregisterFruit("grapefruit");

    std::cout << "create: " << *factory.createFruit("lemon") << std::endl;
    std::cout << "create: " << (factory.createFruit("grapefruit") == nullptr ? "nullptr" : "wtf?") << std::endl;

    std::cout << "create: " << *factory.createFruit("banana") << std::endl;

    UltraBanana *ultraBanana = new UltraBanana();
    std::cout << "register: " << *ultraBanana << std::endl;
    factory.registerFruit(ultraBanana);

    std::cout << "create: " << *factory.createFruit("banana") << std::endl;

    return 0;
}
