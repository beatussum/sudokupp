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
    typename __column_iterator<_InnerIterator>::reference
    __column_iterator<_InnerIterator>::operator[](
        const difference_type __n
    ) const
    {
        return *(*this + __n);
    }

    /*************************************
     * INCREMENT AND DECREMENT OPERATORS *
     *************************************/

    template <class _InnerIterator>
    __column_iterator<_InnerIterator>&
    __column_iterator<_InnerIterator>::operator--()
    {
        m_i -= 9;

        return *this;
    }

    template <class _InnerIterator>
    __column_iterator<_InnerIterator>
    __column_iterator<_InnerIterator>::operator--(int)
    {
        auto tmp = *this;
        --(*this);

        return tmp;
    }

    template <class _InnerIterator>
    __column_iterator<_InnerIterator>&
    __column_iterator<_InnerIterator>::operator++()
    {
        m_i += 9;

        return *this;
    }

    template <class _InnerIterator>
    __column_iterator<_InnerIterator>
    __column_iterator<_InnerIterator>::operator++(int)
    {
        auto tmp = *this;
        ++(*this);

        return tmp;
    }

    /************************
     * ASSIGNMENT OPERATORS *
     ************************/

    template <class _InnerIterator>
    __column_iterator<_InnerIterator>&
    __column_iterator<_InnerIterator>::operator+=(
        const difference_type __n
    )
    {
        m_i += 9 * __n;

        return *this;
    }

    template <class _InnerIterator>
    __column_iterator<_InnerIterator>&
    __column_iterator<_InnerIterator>::operator-=(
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
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i == __r.m_i;
    }

    template <class _InnerIterator>
    bool operator!=(
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i != __r.m_i;
    }

    template <class _InnerIterator>
    bool operator<(
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i < __r.m_i;
    }

    template <class _InnerIterator>
    bool operator>(
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i > __r.m_i;
    }

    template <class _InnerIterator>
    bool operator<=(
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i <= __r.m_i;
    }

    template <class _InnerIterator>
    bool operator>=(
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return __l.m_i >= __r.m_i;
    }

    /*******************************************
     * INCREMENT AND DECREMENT OPERATORS (bis) *
     *******************************************/

    template <class _InnerIterator>
    __column_iterator<_InnerIterator> operator-(
        __column_iterator<_InnerIterator> __l,
        const typename __column_iterator<_InnerIterator>::difference_type __n
    )
    {
        return __l -= __n;
    }

    template <class _InnerIterator>
    __column_iterator<_InnerIterator> operator+(
        __column_iterator<_InnerIterator> __l,
        const typename __column_iterator<_InnerIterator>::difference_type __n
    )
    {
        return __l += __n;
    }

    /*********
     * OTHER *
     *********/

    template <class _InnerIterator>
    typename __column_iterator<_InnerIterator>::difference_type operator-(
        const __column_iterator<_InnerIterator> __l,
        const __column_iterator<_InnerIterator> __r
    )
    {
        return (__l.m_i - __r.m_i) / 9;
    }

    template <class _InnerIterator>
    void swap(
        __column_iterator<_InnerIterator>& __l,
        __column_iterator<_InnerIterator>& __r
    )
    {
        using std::swap;

        swap(__l.m_i, __r.m_i);
    }
}
