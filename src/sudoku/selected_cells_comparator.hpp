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


#ifndef SUDOKUPP_SUDOKU_SELECTED_CELLS_COMPARATOR
#define SUDOKUPP_SUDOKU_SELECTED_CELLS_COMPARATOR

namespace sudoku
{
    /**
     * @brief A class used as \p Compare type in the optimised algorithm.
     *
     * This class allows to optimise the algorithm used to solve the sudoku
     * grid. Indeed, it sorts the container containing the <em>selected
     * cells</em> by increasing order of possibilities.
     *
     * This class respects the <em>named requierement</em> <tt>Compare</tt>.
     *
     * @warning This class was not designed to be used elsewhere.
     *
     */
    class selected_cells_comparator final
    {
    public:
        template <class _T>
        bool operator()(const _T, const _T) const;
    };
}

#include "sudoku/selected_cells_comparator.ipp"

#endif // SUDOKUPP_SUDOKU_SELECTED_CELLS_COMPARATOR
