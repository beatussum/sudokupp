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
    /************************
     * FORWARD DECLARATIONS *
     ************************/

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
    __square_iterator<_InnerIterator> operator-(
        __square_iterator<_InnerIterator>,
        const typename __square_iterator<_InnerIterator>::difference_type
    );

    template <class _InnerIterator>
    __square_iterator<_InnerIterator> operator+(
        __square_iterator<_InnerIterator>,
        const typename __square_iterator<_InnerIterator>::difference_type
    );

    template <class _InnerIterator>
    void swap(
        __square_iterator<_InnerIterator>&,
        __square_iterator<_InnerIterator>&
    );

    /*********************
     * CLASS DECLARATION *
     *********************/

    /**
     * @brief A class allowing iteration over a square composing the grid of a
     * sudoku.
     *
     * This class implements an \em iterator allowing to iterate over a square
     * composing the grid of a sudoku. It respects the following <em>named
     * requierements</em>, \p LegacyOutputIterator and
     * <tt>LegacyRandomAccessIterator</tt>.
     *
     * This iterator works by using an iterator of the two-dimensionnal array
     * used to store the grid of the sudoku (\p m_i), and a counter variable
     * (\p m_counter). This counter allows to know if the next iterator is the
     * one in the next column, in the grid, or in the next row.
     *
     * @note This class was designed as a <em>template class</em> in order to
     * simplify implementation of \p const and \p non-const iterator, and, in
     * this way, avoid code repetition. Indeed, both are implemented using
     * <tt>typedef</tt>s.
     *
     * @warning As mentioned in the note above, this class should not be
     * used directly.
     *
     * @warning Usage of the following implemented methods on two iterators
     * referring to two different columns results in undefined behavior.
     *
     * @warning This class was not designed to be inheritable.
     *
     * @tparam _InnerIterator Type of the iterator of the two-dimensionnal
     * array used to store the grid of the sudoku.
     */
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
        // Necessary in order to set the suitable `m_counter` for method
        // returning a "past-the-end iterators".
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

        friend void swap<>(__square_iterator&, __square_iterator&);
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
}

#include "sudoku/square_iterator.ipp"

#endif // SUDOKUPP_SUDOKU_SQUARE_ITERATOR_HPP
