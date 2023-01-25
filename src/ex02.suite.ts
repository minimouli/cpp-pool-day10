/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, beforeEach, expect, suite, test } from '@minimouli/framework'

suite('Exercise 02', () => {

    let sources: Path[]

    beforeEach(() => {
        sources = [
            Path.fromProject('./IFruit.cpp'),
            Path.fromProject('./AFruit.cpp'),
            Path.fromProject('./ACitrus.cpp'),
            Path.fromProject('./ABerry.cpp'),
            Path.fromProject('./ANut.cpp'),
            Path.fromProject('./FruitBox.cpp'),
            Path.fromProject('./FruitUtils.cpp')
        ]
    })

    test('Simple', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/ex02/simple.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'before sort:',
            ' unsorted: [[name: "lemon", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true]]',
            ' lemons  : []',
            ' citruses: []',
            ' berries : []',
            'after sort:',
            ' unsorted: [[name: "peach", vitamins: 42, peeled: true]]',
            ' lemons  : [[name: "lemon", vitamins: 0, peeled: false]]',
            ' citruses: []',
            ' berries : []',
            ''
        ])
    })

    test('All', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromProject('./Strawberry.cpp'),
            Path.fromProject('./Almond.cpp'),
            Path.fromProject('./Grapefruit.cpp'),
            Path.fromProject('./BloodOrange.cpp'),
            Path.fromProject('./Raspberry.cpp'),
            Path.fromProject('./Coconut.cpp'),
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/ex02/all.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'before sort:',
            ' unsorted: [[name: "lemon", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true], [name: "grapefruit", vitamins: 0, peeled: false], [name: "raspberry", vitamins: 5, peeled: true], [name: "blood orange", vitamins: 0, peeled: false], [name: "coconut", vitamins: 0, peeled: false], [name: "lemon", vitamins: 0, peeled: false], [name: "almond", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true], [name: "orange", vitamins: 0, peeled: false]]',
            ' lemons  : []',
            ' citruses: []',
            ' berries : []',
            'after sort:',
            ' unsorted: [[name: "peach", vitamins: 42, peeled: true], [name: "coconut", vitamins: 0, peeled: false], [name: "almond", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true]]',
            ' lemons  : [[name: "lemon", vitamins: 0, peeled: false], [name: "lemon", vitamins: 0, peeled: false]]',
            ' citruses: [[name: "grapefruit", vitamins: 0, peeled: false], [name: "blood orange", vitamins: 0, peeled: false], [name: "orange", vitamins: 0, peeled: false]]',
            ' berries : [[name: "raspberry", vitamins: 5, peeled: true]]',
            ''
        ])
    })

})
