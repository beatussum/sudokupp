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


namespace sudoku
{
    /******************************
     * CONSTRUCTORS AND OPERATORS *
     ******************************/

    template <class _InnerIterator>
    typename __square_iterator<_InnerIterator>::reference
    __square_iterator<_InnerIterator>::operator[](
        const difference_type __n
    ) const
    {
        return *(*this + __n);
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator>&
    __square_iterator<_InnerIterator>::operator--()
    {
        if ((m_counter-- % 3) == 0) {
            m_i -= 7;
        } else {
            --m_i;
        }

        return *this;
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator>
    __square_iterator<_InnerIterator>::operator--(int)
    {
        auto tmp = *this;
        --(*this);

        return tmp;
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator>&
    __square_iterator<_InnerIterator>::operator++()
    {
        if ((++m_counter % 3) == 0) {
            m_i += 7;
        } else {
            ++m_i;
        }

        return *this;
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator>
    __square_iterator<_InnerIterator>::operator++(int)
    {
        auto tmp = *this;
        ++(*this);

        return tmp;
    }

    // TODO: add comments
    template <class _InnerIterator>
    __square_iterator<_InnerIterator>&
    __square_iterator<_InnerIterator>::operator+=(
        const difference_type __n
    )
    {
        auto column_index = m_counter % 3;

        if (__n < 0) {
            column_index -= 2;
        }

        m_counter += __n;
        m_i       += __n + ((column_index + __n) / 3) * 6;

        return *this;
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator>&
    __square_iterator<_InnerIterator>::operator-=(
        const difference_type __n
    )
    {
        return *this += -__n;
    }

    /***********
     * FRIENDS *
     **********/

    template <class _InnerIterator>
    bool operator==(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i == __r.m_i;
    }

    template <class _InnerIterator>
    bool operator!=(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i != __r.m_i;
    }

    template <class _InnerIterator>
    bool operator<(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i < __r.m_i;
    }

    template <class _InnerIterator>
    bool operator>(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i > __r.m_i;
    }

    template <class _InnerIterator>
    bool operator<=(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i <= __r.m_i;
    }

    template <class _InnerIterator>
    bool operator>=(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i >= __r.m_i;
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator> operator-(
        __square_iterator<_InnerIterator> __l,
        const typename __square_iterator<_InnerIterator>::difference_type __n
    )

    {
        return __l -= __n;
    }

    template <class _InnerIterator>
    __square_iterator<_InnerIterator> operator+(
        __square_iterator<_InnerIterator> __l,
        const typename __square_iterator<_InnerIterator>::difference_type __n
    )

    {
        return __l += __n;
    }

    template <class _InnerIterator>
    typename __square_iterator<_InnerIterator>::difference_type operator-(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        const auto n = __l.m_i - __r.m_i;

        return n - 6 * (n / 9);
    }
}
