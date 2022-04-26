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


#include "sudoku/sudoku_grid.hpp"

#include <stdexcept>

namespace sudoku
{
    sudoku_grid::sudoku_grid(grid_type __s)
        : m_grid(std::move(__s))
    {
        for (const auto& i : m_grid) {
            for (const auto j : i) {
                if (j > 9) {
                    throw std::invalid_argument(
                        "A sudoku grid must contain only numbers between 1 and 9, "
                        "or 0 (if the corresponding case is empty)."
                    );
                }
            }
        }
    }

    sudoku_grid::operator std::string() const
    {
        std::string ret = m_kstrgrid;

        for (std::uint8_t i = 0; i != 9; ++i) {
            for (std::uint8_t j = 0; j != 9; ++j) {
                ret[( 76 * i + 40 ) + 4 * j] =
                    '0' + static_cast<char>(m_grid[i][j]);
            }
        }

        return ret;
    }

    bool sudoku_grid::is_empty() const noexcept
    {
        for (const auto& i : m_grid) {
            for (const auto j : i) {
                if (j != 0) {
                    return false;
                }
            }
        }

        return true;
    }
}
