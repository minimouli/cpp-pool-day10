/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, beforeEach, expect, suite, test } from '@minimouli/framework'

suite('Exercise 00', () => {

    let sources: Path[]

    beforeEach(() => {
        sources = [
            Path.fromProject('./IFruit.cpp'),
            Path.fromProject('./AFruit.cpp'),
            Path.fromProject('./ACitrus.cpp'),
            Path.fromProject('./ABerry.cpp'),
            Path.fromProject('./ANut.cpp')
        ]
    })

    test('Lemon', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Lemon.cpp'),
            Path.fromMoulinette('./res/ex00/lemon.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[name: "lemon", vitamins: 0, peeled: false]',
            'name: lemon',
            'vitamins: 0',
            'is peeled: false',
            '[name: "lemon", vitamins: 4, peeled: true]',
            'name: lemon',
            'vitamins: 4',
            'is peeled: true',
            'is AFruit ? true',
            'is ABerry ? false',
            'is ACitrus ? true',
            'is ANut ? false',
            ''
        ])
    })

    test('Orange', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Orange.cpp'),
            Path.fromMoulinette('./res/ex00/orange.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[name: "orange", vitamins: 0, peeled: false]',
            'name: orange',
            'vitamins: 0',
            'is peeled: false',
            '[name: "orange", vitamins: 7, peeled: true]',
            'name: orange',
            'vitamins: 7',
            'is peeled: true',
            'is AFruit ? true',
            'is ABerry ? false',
            'is ACitrus ? true',
            'is ANut ? false',
            ''
        ])
    })

    test('Strawberry', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Strawberry.cpp'),
            Path.fromMoulinette('./res/ex00/strawberry.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[name: "strawberry", vitamins: 6, peeled: true]',
            'name: strawberry',
            'vitamins: 6',
            'is peeled: true',
            '[name: "strawberry", vitamins: 6, peeled: true]',
            'name: strawberry',
            'vitamins: 6',
            'is peeled: true',
            'is AFruit ? true',
            'is ABerry ? true',
            'is ACitrus ? false',
            'is ANut ? false',
            ''
        ])
    })

    test('Almond', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromProject('./Almond.cpp'),
            Path.fromMoulinette('./res/ex00/almond.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[name: "almond", vitamins: 0, peeled: false]',
            'name: almond',
            'vitamins: 0',
            'is peeled: false',
            '[name: "almond", vitamins: 2, peeled: true]',
            'name: almond',
            'vitamins: 2',
            'is peeled: true',
            'is AFruit ? true',
            'is ABerry ? false',
            'is ACitrus ? false',
            'is ANut ? true',
            ''
        ])
    })

    test('Peach', async () => {

        const gpp = new GPP([
            ...sources,
            Path.fromMoulinette('./res/fruits/Peach.cpp'),
            Path.fromMoulinette('./res/ex00/peach.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[name: "peach", vitamins: 42, peeled: true]',
            'name: peach',
            'vitamins: 42',
            'is peeled: true',
            '[name: "peach", vitamins: 42, peeled: true]',
            'name: peach',
            'vitamins: 42',
            'is peeled: true',
            'is AFruit ? false',
            'is ABerry ? false',
            'is ACitrus ? false',
            'is ANut ? false',
            ''
        ])
    })

})
