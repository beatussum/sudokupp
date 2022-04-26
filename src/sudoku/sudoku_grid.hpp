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

#include <array>
#include <string>

namespace sudoku
{
    class sudoku_grid final
    {
    public:
        using case_type = std::uint8_t;
        using line_type = std::array<case_type, 9>;

        using grid_type = std::array<line_type, 9>;
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
        bool is_empty() const noexcept;
    public:
        void solve();
    private:
        grid_type m_grid;
    };
}

#endif // SUDOKUPP_SUDOKU_SUDOKU_GRID_HPP
