﻿/*
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


#ifndef SUDOKUPP_SUDOKU_COLUMN_ITERATOR_HPP
#define SUDOKUPP_SUDOKU_COLUMN_ITERATOR_HPP

#include <iterator>

namespace sudoku
{
    template <class _InnerIterator>
    class __column_iterator;

    template <class _InnerIterator>
    bool operator==(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator!=(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator<(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator>(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator<=(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator>=(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    typename __column_iterator<_InnerIterator>::difference_type operator-(
        const __column_iterator<_InnerIterator>,
        const __column_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    class __column_iterator final
    {
    public:
        using iterator_type = _InnerIterator;

        using difference_type =
            typename std::iterator_traits<iterator_type>::difference_type;

        struct iterator_category
            : std::random_access_iterator_tag
            , std::output_iterator_tag
        {};

        using pointer =
            typename std::iterator_traits<iterator_type>::pointer;

        using reference =
            typename std::iterator_traits<iterator_type>::reference;

        using value_type =
            typename std::iterator_traits<iterator_type>::value_type;
    public:
        friend bool operator== <>(
            const __column_iterator,
            const __column_iterator
        );

        friend bool operator!= <>(
            const __column_iterator,
            const __column_iterator
        );

        friend bool operator< <>(
            const __column_iterator,
            const __column_iterator
        );

        friend bool operator> <>(
            const __column_iterator,
            const __column_iterator
        );

        friend bool operator<= <>(
            const __column_iterator,
            const __column_iterator
        );

        friend bool operator>= <>(
            const __column_iterator,
            const __column_iterator
        );

        friend difference_type operator- <>(
            const __column_iterator,
            const __column_iterator
        );
    public:
        __column_iterator() = default;

        __column_iterator(_InnerIterator __i)
            : m_i(std::move(__i))
        {}
    public:
        reference operator*() const { return *m_i; }
        reference operator[](const difference_type __n) const;

        __column_iterator& operator--();
        __column_iterator operator--(int);
        __column_iterator& operator++();
        __column_iterator operator++(int);

        __column_iterator& operator+=(const difference_type);
        __column_iterator& operator-=(const difference_type);

        pointer operator->() const { return m_i.operator->(); }
    private:
        iterator_type m_i;
    };

    template <class _InnerIterator>
    __column_iterator<_InnerIterator> operator+(
        __column_iterator<_InnerIterator>,
        const typename __column_iterator<_InnerIterator>::difference_type
    );
}

#include "sudoku/column_iterator.ipp"

#endif // SUDOKUPP_SUDOKU_COLUMN_ITERATOR_HPP

