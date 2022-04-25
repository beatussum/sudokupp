# Copyright (C) 2022 Mattéo Rossillol‑‑Laruelle <beatussum@protonmail.com>
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <https://www.gnu.org/licenses/>.


set(SUDOKUPP_HPP)

set(SUDOKUPP_IPP)

set(
    SUDOKUPP_CPP
    main.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
add_executable(sudokupp "${SUDOKUPP_HPP}" "${SUDOKUPP_IPP}" "${SUDOKUPP_CPP}")
target_include_directories(sudokupp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(sudokupp Qt5::Core Qt5::Gui Qt5::Widgets)

add_to_doc("${SUDOKUPP_HPP}")
