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


#ifndef SUDOKUPP_SUDOKU_SUDOKU_GRID_HPP
#define SUDOKUPP_SUDOKU_SUDOKU_GRID_HPP

#include "sudoku/column_iterator.hpp"
#include "sudoku/square_iterator.hpp"

#include <array>
#include <string>

namespace sudoku
{
    class sudoku_grid final
    {
    public:
        using cell_type = std::uint8_t;
        using row_type  = std::array<cell_type, 9>;
        using size_type = row_type::size_type;

        using grid_type       = std::array<row_type, 9>;
        using column_iterator = __column_iterator<row_type::iterator>;

        using const_column_iterator =
            __column_iterator<row_type::const_iterator>;

        using row_iterator       = row_type::iterator;
        using const_row_iterator = row_type::const_iterator;
        using square_iterator    = __square_iterator<row_type::iterator>;

        using const_square_iterator =
            __square_iterator<row_type::const_iterator>;
    public:
        inline static std::string m_kstrgrid =
            "+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+---+---+---+---+---+---+---+---+---+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+---+---+---+---+---+---+---+---+---+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+---+---+---+---+---+---+---+---+---+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+---+---+---+---+---+---+---+---+---+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+---+---+---+---+---+---+---+---+---+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+---+---+---+---+---+---+---+---+---+\n"
            "I 0 | 0 | 0 I 0 | 0 | 0 I 0 | 0 | 0 I\n"
            "+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+";
    public:
        explicit sudoku_grid(grid_type);

        explicit operator std::string() const;
    public:
        bool is_empty() const;

        const_column_iterator get_column_cbegin(const size_type) const;
        const_column_iterator get_column_cend(const size_type) const;
        column_iterator get_column_begin(const size_type);
        column_iterator get_column_end(const size_type);
        const_column_iterator get_column_begin(const size_type) const;
        const_column_iterator get_column_end(const size_type) const;

        const_row_iterator get_row_cbegin(const size_type) const;
        const_row_iterator get_row_cend(const size_type) const;
        row_iterator get_row_begin(const size_type);
        row_iterator get_row_end(const size_type);
        const_row_iterator get_row_begin(const size_type) const;
        const_row_iterator get_row_end(const size_type) const;

        const_square_iterator get_square_cbegin(const size_type) const;
        const_square_iterator get_square_cend(const size_type) const;
        square_iterator get_square_begin(const size_type);
        square_iterator get_square_end(const size_type);
        const_square_iterator get_square_begin(const size_type) const;
        const_square_iterator get_square_end(const size_type) const;
    public:
        void solve();
    public:
        grid_type m_grid;
    };
}

#endif // SUDOKUPP_SUDOKU_SUDOKU_GRID_HPP
