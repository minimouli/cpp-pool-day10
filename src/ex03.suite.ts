/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, beforeEach, expect, suite, test } from '@minimouli/framework'

suite('Exercise 03', () => {

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

    suite('Pack', () => {

        test('One', async () => {

            const gpp = new GPP([
                ...sources,
                Path.fromProject('./Lemon.cpp'),
                Path.fromProject('./Orange.cpp'),
                Path.fromMoulinette('./res/ex03/pack_one.cpp')
            ])
            const exec = await gpp.execute([
                `-I${Path.fromProject().toString()}`,
                '-std=c++20'
            ])
            await exec.execute()

            expect(exec).toExitWith(0)
            await expect(exec).toOutput([
                'before packing: ',
                ' orange',
                'packed fruits: ',
                ' [[name: "orange", vitamins: 0, peeled: false]]',
                ''
            ])
        })

        test('Several', async () => {

            const gpp = new GPP([
                ...sources,
                Path.fromProject('./Lemon.cpp'),
                Path.fromProject('./Orange.cpp'),
                Path.fromProject('./Almond.cpp'),
                Path.fromProject('./Grapefruit.cpp'),
                Path.fromProject('./BloodOrange.cpp'),
                Path.fromProject('./Raspberry.cpp'),
                Path.fromProject('./Coconut.cpp'),
                Path.fromMoulinette('./res/fruits/Peach.cpp'),
                Path.fromMoulinette('./res/ex03/pack_several.cpp')
            ])
            const exec = await gpp.execute([
                `-I${Path.fromProject().toString()}`,
                '-std=c++20'
            ])
            await exec.execute()

            expect(exec).toExitWith(0)
            await expect(exec).toOutput([
                'before packing: ',
                ' orange',
                ' lemon',
                ' grapefruit',
                ' lemon',
                ' peach',
                ' almond',
                ' raspberry',
                ' blood orange',
                ' coconut',
                ' grapefruit',
                ' peach',
                ' almond',
                'packed fruits: ',
                ' [[name: "orange", vitamins: 0, peeled: false], [name: "lemon", vitamins: 0, peeled: false], [name: "grapefruit", vitamins: 0, peeled: false], [name: "lemon", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true]]',
                ' [[name: "almond", vitamins: 0, peeled: false], [name: "raspberry", vitamins: 5, peeled: true], [name: "blood orange", vitamins: 0, peeled: false], [name: "coconut", vitamins: 0, peeled: false], [name: "grapefruit", vitamins: 0, peeled: false]]',
                ' [[name: "peach", vitamins: 42, peeled: true], [name: "almond", vitamins: 0, peeled: false]]',
                ''
            ])
        })

    })

    suite('Unpack', () => {

        test('One', async () => {

            const gpp = new GPP([
                ...sources,
                Path.fromProject('./Lemon.cpp'),
                Path.fromProject('./Orange.cpp'),
                Path.fromMoulinette('./res/ex03/unpack_one.cpp')
            ])
            const exec = await gpp.execute([
                `-I${Path.fromProject().toString()}`,
                '-std=c++20'
            ])
            await exec.execute()

            expect(exec).toExitWith(0)
            await expect(exec).toOutput([
                'before unpacking: ',
                ' [[name: "orange", vitamins: 0, peeled: false]]',
                'unpacked fruits: ',
                ' orange',
                ''
            ])
        })

        test('Several', async () => {

            const gpp = new GPP([
                ...sources,
                Path.fromProject('./Lemon.cpp'),
                Path.fromProject('./Orange.cpp'),
                Path.fromProject('./Almond.cpp'),
                Path.fromProject('./Grapefruit.cpp'),
                Path.fromProject('./BloodOrange.cpp'),
                Path.fromProject('./Raspberry.cpp'),
                Path.fromProject('./Coconut.cpp'),
                Path.fromMoulinette('./res/fruits/Peach.cpp'),
                Path.fromMoulinette('./res/ex03/unpack_several.cpp')
            ])
            const exec = await gpp.execute([
                `-I${Path.fromProject().toString()}`,
                '-std=c++20'
            ])
            await exec.execute()

            expect(exec).toExitWith(0)
            await expect(exec).toOutput([
                'before unpacking: ',
                ' [[name: "orange", vitamins: 0, peeled: false], [name: "lemon", vitamins: 0, peeled: false], [name: "grapefruit", vitamins: 0, peeled: false], [name: "lemon", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true]]',
                ' [[name: "almond", vitamins: 0, peeled: false], [name: "raspberry", vitamins: 5, peeled: true], [name: "blood orange", vitamins: 0, peeled: false], [name: "coconut", vitamins: 0, peeled: false], [name: "grapefruit", vitamins: 0, peeled: false]]',
                ' [[name: "peach", vitamins: 42, peeled: true], [name: "almond", vitamins: 0, peeled: false]]',
                'unpacked fruits: ',
                ' orange',
                ' lemon',
                ' grapefruit',
                ' lemon',
                ' peach',
                ' almond',
                ' raspberry',
                ' blood orange',
                ' coconut',
                ' grapefruit',
                ' peach',
                ' almond',
                ''
            ])
        })

    })

})
