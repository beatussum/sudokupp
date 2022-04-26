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


#ifndef SUDOKUPP_SUDOKU_SQUARE_ITERATOR_HPP
#define SUDOKUPP_SUDOKU_SQUARE_ITERATOR_HPP

#include <iterator>

namespace sudoku
{
    template <class _InnerIterator>
    class __square_iterator;

    template <class _InnerIterator>
    bool operator==(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator!=(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator<(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator>(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator<=(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    bool operator>=(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    typename __square_iterator<_InnerIterator>::difference_type operator-(
        const __square_iterator<_InnerIterator>,
        const __square_iterator<_InnerIterator>
    );

    template <class _InnerIterator>
    class __square_iterator final
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
        friend class sudoku_grid;

        friend bool operator== <>(
            const __square_iterator,
            const __square_iterator
        );

        friend bool operator!= <>(
            const __square_iterator,
            const __square_iterator
        );

        friend bool operator< <>(
            const __square_iterator,
            const __square_iterator
        );

        friend bool operator> <>(
            const __square_iterator,
            const __square_iterator
        );

        friend bool operator<= <>(
            const __square_iterator,
            const __square_iterator
        );

        friend bool operator>= <>(
            const __square_iterator,
            const __square_iterator
        );

        friend difference_type operator- <>(
            const __square_iterator,
            const __square_iterator
        );
    public:
        __square_iterator()
            : m_i()
            , m_counter(0)
        {}

        __square_iterator(_InnerIterator __i)
            : m_i(std::move(__i))
            , m_counter(0)
        {}
    public:
        reference operator*() const { return *m_i; }
        reference operator[](const difference_type) const;

        __square_iterator& operator--();
        __square_iterator operator--(int);
        __square_iterator& operator++();
        __square_iterator operator++(int);

        __square_iterator& operator+=(const difference_type);
        __square_iterator& operator-=(const difference_type);

        pointer operator->() const { return m_i.operator->(); }
    private:
        iterator_type m_i;
        difference_type m_counter;
    };

    template <class _InnerIterator>
    __square_iterator<_InnerIterator> operator-(
        __square_iterator<_InnerIterator>,
        const typename __square_iterator<_InnerIterator>::difference_type
    );

    template <class _InnerIterator>
    __square_iterator<_InnerIterator> operator+(
        __square_iterator<_InnerIterator>,
        const typename __square_iterator<_InnerIterator>::difference_type
    );
}

#include "sudoku/square_iterator.ipp"

#endif // SUDOKUPP_SUDOKU_SQUARE_ITERATOR_HPP
