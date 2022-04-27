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
    /***************************
     * MEMBER ACCESS OPERATORS *
     ***************************/

    template <class _InnerIterator>
    typename __square_iterator<_InnerIterator>::reference
    __square_iterator<_InnerIterator>::operator[](
        const difference_type __n
    ) const
    {
        return *(*this + __n);
    }

    /*************************************
     * INCREMENT AND DECREMENT OPERATORS *
     *************************************/

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

    /************************
     * ASSIGNMENT OPERATORS *
     ************************/

    /**
     * Here is a square:
     *
     * +~~~+~~~+~~~+
     * I 0 | 1 | 2 I
     * +~~~+~~~+~~~+
     * I 3 | 4 | 5 I
     * +~~~+~~~+~~~+
     * I 6 | 7 | 8 I
     * +~~~+~~~+~~~+
     *
     * We notice that, between the cell containing 2 and the one containing 3,
     * there are 6 cells (resp. between the cell containing 5 and the one
     * containing 6).
     *
     * Let `__n` the number of increments to be made, and `c` the column index
     * corresponding to the cell before the increment.
     *
     * Note that there are `(c + __n) / 3` rows separating the cell before
     * and after increment.
     */
    template <class _InnerIterator>
    __square_iterator<_InnerIterator>&
    __square_iterator<_InnerIterator>::operator+=(
        const difference_type __n
    )
    {
        auto column_index = m_counter % 3;

        // If `__n` is negative, index are counted from left to right.
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

    /************************
     * COMPARISON OPERATORS *
     ************************/

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

    /*******************************************
     * INCREMENT AND DECREMENT OPERATORS (bis) *
     *******************************************/

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

    /*********
     * OTHER *
     *********/

    template <class _InnerIterator>
    typename __square_iterator<_InnerIterator>::difference_type operator-(
        const __square_iterator<_InnerIterator> __l,
        const __square_iterator<_InnerIterator> __r
    )
    {
        return __l.m_counter - __r.m_counter;
    }

    template <class _InnerIterator>
    void swap(
        __square_iterator<_InnerIterator>& __l,
        __square_iterator<_InnerIterator>& __r
    )
    {
        using std::swap;

        swap(__l.m_i, __r.m_i);
        swap(__l.m_counter, __r.m_counter);
    }
}
