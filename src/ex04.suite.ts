/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 04', () => {

    test('The fruit factory', async () => {

        const gpp = new GPP([
            Path.fromProject('./IFruit.cpp'),
            Path.fromProject('./AFruit.cpp'),
            Path.fromProject('./ACitrus.cpp'),
            Path.fromProject('./ABerry.cpp'),
            Path.fromProject('./ANut.cpp'),
            Path.fromProject('./FruitBox.cpp'),
            Path.fromProject('./FruitFactory.cpp'),
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Grapefruit.cpp'),
            Path.fromProject('./Raspberry.cpp'),
            Path.fromMoulinette('./res/fruits/Banana.cpp'),
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/fruits/UltraBanana.cpp'),
            Path.fromMoulinette('./res/ex04/main.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'register: [name: "lemon", vitamins: 0, peeled: false]',
            'create: [name: "lemon", vitamins: 0, peeled: false]',
            'register: [name: "peach", vitamins: 42, peeled: true]',
            'register: [name: "grapefruit", vitamins: 0, peeled: false]',
            'register: [name: "raspberry", vitamins: 5, peeled: true]',
            'banana created',
            'register: [name: "banana", vitamins: 3, peeled: true]',
            'create: [name: "grapefruit", vitamins: 0, peeled: false]',
            'create: [name: "peach", vitamins: 42, peeled: true]',
            'create: [name: "peach", vitamins: 42, peeled: true]',
            'create: nullptr',
            'unregister: [name: "grapefruit", vitamins: 0, peeled: false]',
            'create: [name: "lemon", vitamins: 0, peeled: false]',
            'create: nullptr',
            'create: banana created',
            '[name: "banana", vitamins: 3, peeled: true]',
            'ultra banana created',
            'register: [name: "banana", vitamins: 99, peeled: true]',
            'banana destroyed',
            'create: ultra banana created',
            '[name: "banana", vitamins: 99, peeled: true]',
            'ultra banana destroyed',
            ''
        ])
    })

})
