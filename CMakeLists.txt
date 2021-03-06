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


cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0048 NEW)

project(sudokupp
        VERSION 0.9.0
        DESCRIPTION "A sudoku solver written in C++"
        HOMEPAGE_URL "https://github.com/beatussum/sudokupp/"
        LANGUAGES CXX)

option(WITH_DOC "Build the documentation" OFF)

option(
    WITH_OPTIMISED_ALGORITHM
    "Use an optimised algorithm to solve the sudoku grid"
    ON
)

unset(CMAKE_CXX_FLAGS_RELEASE CACHE)
macro(add_gcc_cxx_flags _flags)
    if(CMAKE_COMPILER_IS_GNUCXX)
         set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_flags}")
    endif()
endmacro()

# Use ccache if installed
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

set(
    EXPORT_DIR
    "${CMAKE_BINARY_DIR}/exports"
    CACHE PATH
    "The path where the export header is generated"
)

if (WITH_DOC)
    set(
        DOC_DIR
        "${CMAKE_BINARY_DIR}/doc"
        CACHE PATH
        "The path where the documentation is built"
    )

    find_package(Doxygen REQUIRED)

    set(DOXYGEN_OUTPUT_DIRECTORY "${DOC_DIR}")
    set(DOXYGEN_INLINE_INHERITED_MEMB YES)
    set(DOXYGEN_ALIASES "pexample=@par Example")
    set(DOXYGEN_HIDE_UNDOC_CLASSES YES)
    set(DOXYGEN_HIDE_IN_BODY_DOCS YES)
    set(DOXYGEN_WARN_NO_PARAMDOC YES)
    set(DOXYGEN_WARN_LOGFILE "${DOC_DIR}/log")
endif()

macro(add_to_doc _headers)
    if (WITH_DOC)
        doxygen_add_docs(
            doc
            "${_headers}"
            COMMENT "Generating documentation…"
        )
    endif()
endmacro()

if (WITH_OPTIMISED_ALGORITHM)
    add_compile_definitions(SUDOKUPP_OPTIMISED_ALGORITHM)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

add_gcc_cxx_flags(
    -fmessage-length=75
    -fno-gnu-keywords
    -fno-operator-names
    -funsigned-char
    -pipe
    -Wall
    -Wconversion
    -Wdouble-promotion
    -Wduplicated-branches
    -Wduplicated-cond
    -Wfloat-equal
    -Wignored-qualifiers
    -Wimplicit-fallthrough=5
    -Wmissing-field-initializers
    -Wmissing-include-dirs
    -Wno-div-by-zero
    -Wnoexcept
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpedantic
    -Wsuggest-attribute=const
    -Wsuggest-attribute=noreturn
    -Wsuggest-attribute=pure
    -Wsuggest-final-methods
    -Wsuggest-final-types
    -Wsuggest-final-types
    -Wsuggest-override
    -Wsuggest-override
    -Wundef
    -Wuninitialized
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_gcc_cxx_flags(-O0)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_gcc_cxx_flags(-O2)
    add_gcc_cxx_flags(-Werror -Wfatal-errors)
endif()

add_subdirectory("${CMAKE_SOURCE_DIR}/src")
