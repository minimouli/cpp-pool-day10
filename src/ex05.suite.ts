/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, beforeEach, expect, suite, test } from '@minimouli/framework'

suite('Exercise 05', () => {

    let sources: Path[]

    beforeEach(() => {
        sources = [
            Path.fromProject('./IFruit.cpp'),
            Path.fromProject('./AFruit.cpp'),
            Path.fromProject('./ACitrus.cpp'),
            Path.fromProject('./ABerry.cpp'),
            Path.fromProject('./ANut.cpp'),
            Path.fromProject('./FruitBox.cpp'),
            Path.fromProject('./FruitMixer.cpp'),
            Path.fromProject('./BloodOrange.cpp'),
            Path.fromProject('./Coconut.cpp'),
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromProject('./Strawberry.cpp')
        ]
    })

    test('Steel Blade', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromMoulinette('./res/blades/SteelBlade.cpp'),
            Path.fromMoulinette('./res/ex05/steel.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            `-I${Path.fromMoulinette('./res/interfaces').toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'mixer has no blade',
            'vitamins: 0',
            'box: [[name: "lemon", vitamins: 4, peeled: true], [name: "blood orange", vitamins: 6, peeled: true], [name: "strawberry", vitamins: 6, peeled: true], [name: "orange", vitamins: 7, peeled: true], [name: "coconut", vitamins: 4, peeled: true]]',
            'vitamins: 27',
            'box: []',
            ''
        ])
    })

    test('Citrus Blade', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromMoulinette('./res/blades/CitrusBlade.cpp'),
            Path.fromMoulinette('./res/ex05/citrus.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            `-I${Path.fromMoulinette('./res/interfaces').toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'mixer has no blade',
            'vitamins: 0',
            'box: [[name: "lemon", vitamins: 4, peeled: true], [name: "blood orange", vitamins: 6, peeled: true], [name: "strawberry", vitamins: 6, peeled: true], [name: "orange", vitamins: 7, peeled: true], [name: "coconut", vitamins: 4, peeled: true]]',
            'vitamins: 17',
            'box: []',
            ''
        ])
    })

    test('Malfunctioning Blade', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromMoulinette('./res/blades/MalfunctioningBlade.cpp'),
            Path.fromMoulinette('./res/ex05/malfunctioning.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            `-I${Path.fromMoulinette('./res/interfaces').toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'mixer has no blade',
            'vitamins: 0',
            'box: [[name: "lemon", vitamins: 4, peeled: true], [name: "blood orange", vitamins: 6, peeled: true], [name: "strawberry", vitamins: 6, peeled: true], [name: "orange", vitamins: 7, peeled: true], [name: "coconut", vitamins: 4, peeled: true]]',
            'vitamins: 0',
            'box: []',
            ''
        ])
    })

})
