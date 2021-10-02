/* Copyright 2021 Rafal Przywarski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "gtest/gtest.h"
#include "gmock/gmock.h"

extern "C"
{
#include "../config.h"
#include "../modern_cadet.h"
}

using testing::ElementsAreArray;
using testing::WhenSorted;

struct LayoutTest : public ::testing::Test
{
    template <typename KM>
    static std::vector<std::uint16_t> flatten(const KM& keymap)
    {
        std::vector<std::uint16_t> vals;
        for (auto& row : keymap)
            vals.insert(end(vals), std::begin(row), std::end(row));
        return vals;
    }
};

TEST_F(LayoutTest, LAYOUT_consistency)
{
    const std::uint16_t keymap[MATRIX_ROWS][MATRIX_COLS] =
        LAYOUT(
            11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
            21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
            31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
            51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
            61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
            71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
            81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
            91, 92, 93, 94, 95, 96, 97);

    ASSERT_LT(XXXXXXX, 11);
    ASSERT_THAT(flatten(keymap),
                WhenSorted(ElementsAreArray({int(XXXXXXX), int(XXXXXXX), int(XXXXXXX),
                                             11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                             21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                                             31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                                             41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                                             51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                                             61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
                                             71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                                             81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                                             91, 92, 93, 94, 95, 96, 97})));
}
