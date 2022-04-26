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
#include "sudoku/column_iterator.hpp"

#include <algorithm>
#include <stdexcept>

namespace sudoku
{
    /******************************
     * CONSTRUCTORS AND OPERATORS *
     ******************************/

    sudoku_grid::sudoku_grid(grid_type __s)
        : m_grid(std::move(__s))
    {
        for (const auto& i : m_grid) {
            for (const auto j : i) {
                if (j > 9) {
                    throw std::invalid_argument(
                        "A sudoku grid must contain only numbers between 1 and 9, "
                        "or 0 (if the corresponding cell is empty)."
                    );
                }
            }
        }
    }

    sudoku_grid::operator std::string() const
    {
        std::string ret = m_strgrid;

        for (std::uint8_t i = 0; i != 9; ++i) {
            for (std::uint8_t j = 0; j != 9; ++j) {
                ret[( 76 * i + 40 ) + 4 * j] =
                    '0' + static_cast<char>(m_grid[i][j]);
            }
        }

        return ret;
    }

    /********************
     * MEMBER ACCESSORS *
     ********************/

    sudoku_grid::const_column_iterator sudoku_grid::get_column_cbegin(
        const size_type __n
    ) const
    {
        return m_grid.front().cbegin() + (__n % 9);
    }

    sudoku_grid::const_column_iterator sudoku_grid::get_column_cend(
        const size_type __n
    ) const
    {
        return m_grid.cend()[-1].cbegin() + (__n % 9) + 9;
    }

    sudoku_grid::column_iterator sudoku_grid::get_column_begin(
        const size_type __n
    )
    {
        return m_grid.front().begin() + (__n % 9);
    }

    sudoku_grid::column_iterator sudoku_grid::get_column_end(
        const size_type __n
    )
    {
        return m_grid.end()[-1].begin() + (__n % 9) + 9;
    }

    sudoku_grid::const_column_iterator sudoku_grid::get_column_begin(
        const size_type __n
    ) const
    {
        return get_column_cbegin(__n);
    }

    sudoku_grid::const_column_iterator sudoku_grid::get_column_end(
        const size_type __n
    ) const
    {
        return get_column_cend(__n);
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_cbegin(
        const size_type __n
    ) const
    {
        return m_grid[__n % 9].cbegin();
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_cend(
        const size_type __n
    ) const
    {
        return m_grid[__n % 9].cend();
    }

    sudoku_grid::row_iterator sudoku_grid::get_row_begin(
        const size_type __n
    )
    {
        return m_grid[__n % 9].begin();
    }

    sudoku_grid::row_iterator sudoku_grid::get_row_end(
        const size_type __n
    )
    {
        return m_grid[__n % 9].end();
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_begin(
        const size_type __n
    ) const
    {
        return get_row_cbegin(__n);
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_end(
        const size_type __n
    ) const
    {
        return get_row_cend(__n);
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_cbegin(
        const size_type __n
    ) const
    {
        return m_grid[(__n / 27) * 3].cbegin() + ((__n % 9) / 3) * 3;
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_cend(
        const size_type __n
    ) const
    {
        const_square_iterator ret =
            m_grid[(__n / 27) * 3 + 2].cbegin() + (((__n % 9) / 3) * 3) + 9;

        ret.m_counter = 9;

        return ret;
    }

    sudoku_grid::square_iterator sudoku_grid::get_square_begin(
        const size_type __n
    )
    {
        return m_grid[(__n / 27) * 3].begin() + ((__n % 9) / 3) * 3;
    }

    sudoku_grid::square_iterator sudoku_grid::get_square_end(
        const size_type __n
    )
    {
        square_iterator ret =
            m_grid[(__n / 27) * 3 + 2].begin() + (((__n % 9) / 3) * 3) + 9;

        ret.m_counter = 9;

        return ret;
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_begin(
        const size_type __n
    ) const
    {
        return get_square_cbegin(__n);
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_end(
        const size_type __n
    ) const
    {
        return get_square_cend(__n);
    }


    sudoku_grid::const_column_iterator sudoku_grid::get_column_cbegin(
        const const_row_iterator __i
    ) const
    {
        return get_column_cbegin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_column_iterator sudoku_grid::get_column_cend(
        const const_row_iterator __i
    ) const
    {
        return get_column_cend(__i - m_grid.front().cbegin());
    }

    sudoku_grid::column_iterator sudoku_grid::get_column_begin(
        const const_row_iterator __i
    )
    {
        return get_column_begin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::column_iterator sudoku_grid::get_column_end(
        const const_row_iterator __i
    )
    {
        return get_column_end(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_column_iterator sudoku_grid::get_column_begin(
        const const_row_iterator __i
    ) const
    {
        return get_column_begin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_column_iterator sudoku_grid::get_column_end(
        const const_row_iterator __i
    ) const
    {
        return get_column_end(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_cbegin(
        const const_row_iterator __i
    ) const
    {
        return get_row_cbegin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_cend(
        const const_row_iterator __i
    ) const
    {
        return get_row_cend(__i - m_grid.front().cbegin());
    }

    sudoku_grid::row_iterator sudoku_grid::get_row_begin(
        const const_row_iterator __i
    )
    {
        return get_row_begin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::row_iterator sudoku_grid::get_row_end(
        const const_row_iterator __i)
    {
        return get_row_end(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_begin(
        const const_row_iterator __i
    ) const
    {
        return get_row_begin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_row_iterator sudoku_grid::get_row_end(
        const const_row_iterator __i
    ) const
    {
        return get_row_end(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_cbegin(
        const const_row_iterator __i
    ) const
    {
        return get_square_cbegin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_cend(
        const const_row_iterator __i
    ) const
    {
        return get_square_cend(__i - m_grid.front().cbegin());
    }

    sudoku_grid::square_iterator sudoku_grid::get_square_begin(
        const const_row_iterator __i
    )
    {
        return get_square_begin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::square_iterator sudoku_grid::get_square_end(
        const const_row_iterator __i
    )
    {
        return get_square_end(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_begin(
        const const_row_iterator __i
    ) const
    {
        return get_square_begin(__i - m_grid.front().cbegin());
    }

    sudoku_grid::const_square_iterator sudoku_grid::get_square_end(
        const const_row_iterator __i
    ) const
    {
        return get_square_end(__i - m_grid.front().cbegin());
    }

    bool sudoku_grid::is_in_column(
        const cell_type __c,
        const size_type __i
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

    bool sudoku_grid::is_in_row(
        const cell_type __c,
        const size_type __i
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

    bool sudoku_grid::is_in_square(
        const cell_type __c,
        const size_type __i
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

    bool sudoku_grid::is_empty() const
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

    bool sudoku_grid::is_valid() const
    {
        for (cell_type i = 1; i != 10; ++i) {
            for (size_type k = 0; k != 9; ++k) {
                if (!is_in_column(i, k)) {
                    return false;
                }

                if (!is_in_row(i, k)) {
                    return false;
                }

                if (!is_in_square(i, 27 * (k / 3) + 3 * (k % 3))) {
                    return false;
                }
            }
        }

        return true;
    }

    std::vector<sudoku_grid::row_iterator> sudoku_grid::get_empty_cells()
    {
        std::vector<row_iterator> ret;

        for (auto& i : m_grid) {
            for (auto j = i.begin(); j != i.end(); ++j) {
                if (*j == 0) {
                    ret.push_back(j);
                }
            }
        }

        return ret;
    }

    std::vector<sudoku_grid::const_row_iterator>
    sudoku_grid::get_empty_cells() const
    {
        std::vector<const_row_iterator> ret;

        for (auto& i : m_grid) {
            for (auto j = i.cbegin(); j != i.cend(); ++j) {
                if (*j == 0) {
                    ret.push_back(j);
                }
            }
        }

        return ret;
    }

    std::uint8_t sudoku_grid::get_number_of_empty_cells() const
    {
        std::uint8_t ret = 0;

        for (auto& i : m_grid) {
            for (auto j : i) {
                if (j == 0) {
                    ++ret;
                }
            }
        }

        return ret;
    }
}
