/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, beforeEach, expect, suite, test } from '@minimouli/framework'

suite('Exercise 01', () => {

    let sources: Path[]

    beforeEach(() => {
        sources = [
            Path.fromProject('./IFruit.cpp'),
            Path.fromProject('./AFruit.cpp'),
            Path.fromProject('./ACitrus.cpp'),
            Path.fromProject('./ABerry.cpp'),
            Path.fromProject('./ANut.cpp'),
            Path.fromProject('./FruitBox.cpp')
        ]
    })

    test('#1', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/ex01/main1.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'size: 3',
            'fruits: 0',
            'push lemon: true',
            'push orange: true',
            'push peach: true',
            '[[name: "lemon", vitamins: 0, peeled: false], [name: "orange", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true]]',
            'size: 3',
            'fruits: 3',
            ''
        ])
    })

    test('#2', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromProject('./Strawberry.cpp'),
            Path.fromProject('./Almond.cpp'),
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/ex01/main2.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'size: 3',
            'fruits: 0',
            'push lemon: true',
            'push orange: true',
            'push peach: true',
            'push strawberry: false',
            'push almond: false',
            '[[name: "lemon", vitamins: 0, peeled: false], [name: "orange", vitamins: 0, peeled: false], [name: "peach", vitamins: 42, peeled: true]]',
            'size: 3',
            'fruits: 3',
            ''
        ])
    })

    test('#3', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromProject('./Strawberry.cpp'),
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/ex01/main3.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'size: 2',
            'fruits: 0',
            'push lemon: true',
            'push orange: true',
            'push peach: false',
            'pop: lemon',
            'push strawberry: true',
            '[[name: "orange", vitamins: 0, peeled: false], [name: "strawberry", vitamins: 6, peeled: true]]',
            'size: 2',
            'fruits: 2',
            ''
        ])
    })

    test('#4', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromProject('./Orange.cpp'),
            Path.fromMoulinette('./res/ex01/main4.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'size: 2',
            'fruits: 0',
            'pop: nullptr',
            'push lemon: true',
            'push orange: true',
            '[[name: "lemon", vitamins: 0, peeled: false], [name: "orange", vitamins: 0, peeled: false]]',
            'pop: lemon',
            'pop: orange',
            'pop: nullptr',
            'size: 2',
            'fruits: 0',
            ''
        ])
    })

})
