/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 06', () => {

    test('Hack the reality', async () => {

        const gpp = new GPP([
            Path.fromProject('./IFruit.cpp'),
            Path.fromProject('./AFruit.cpp'),
            Path.fromProject('./ACitrus.cpp'),
            Path.fromProject('./ABerry.cpp'),
            Path.fromProject('./ANut.cpp'),
            Path.fromProject('./Almond.cpp'),
            Path.fromProject('./BloodOrange.cpp'),
            Path.fromProject('./Coconut.cpp'),
            Path.fromProject('./Grapefruit.cpp'),
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromProject('./Raspberry.cpp'),
            Path.fromProject('./Strawberry.cpp'),
            Path.fromMoulinette('./res/ex06/main.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            `-I${Path.fromMoulinette('./res/interfaces').toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[name: "lemon", vitamins: 4, peeled: true]',
            '[name: "lemon", vitamins: 125, peeled: true]',
            '[name: "orange", vitamins: 7, peeled: true]',
            '[name: "orange", vitamins: 865, peeled: true]',
            '[name: "strawberry", vitamins: 6, peeled: true]',
            '[name: "strawberry", vitamins: 103, peeled: true]',
            '[name: "almond", vitamins: 2, peeled: true]',
            '[name: "almond", vitamins: 792, peeled: true]',
            '[name: "grapefruit", vitamins: 5, peeled: true]',
            '[name: "grapefruit", vitamins: 303, peeled: true]',
            '[name: "blood orange", vitamins: 6, peeled: true]',
            '[name: "blood orange", vitamins: 742, peeled: true]',
            '[name: "raspberry", vitamins: 5, peeled: true]',
            '[name: "raspberry", vitamins: 903, peeled: true]',
            '[name: "coconut", vitamins: 4, peeled: true]',
            '[name: "coconut", vitamins: 834, peeled: true]',
            ''
        ])
    })

})
