/*
 * Copyright (C) 2022 Mattéo Rossillol‑‑Laruelle <beatussum@protonmail.com>
 *
 * This program is free software:  you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published  by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be  useful,
 * but WITHOUT ANY WARRANTY;   without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include <algorithm>

namespace sudoku
{
    template <class _T>
    bool sudoku_grid::is_in_column(
        const cell_type __c,
        const _T __i
    ) const
    {
        if (__c > 9) {
            return false;
        } else {
            return std::find(
                get_column_cbegin(__i),
                get_column_cend(__i),
                __c
            ) != get_column_cend(__i);
        }
    }

    template <class _T>
    bool sudoku_grid::is_in_row(
        const cell_type __c,
        const _T __i
    ) const
    {
        if (__c > 9) {
            return false;
        } else {
            return std::find(
                get_row_cbegin(__i),
                get_row_cend(__i),
                __c
            ) != get_row_cend(__i);
        }
    }

    template <class _T>
    bool sudoku_grid::is_in_square(
        const cell_type __c,
        const _T __i
    ) const
    {
        if (__c > 9) {
            return false;
        } else {
            return std::find(
                get_square_cbegin(__i),
                get_square_cend(__i),
                __c
            ) != get_square_cend(__i);
        }
    }
}
