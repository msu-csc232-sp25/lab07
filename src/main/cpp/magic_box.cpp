/**
 * @file magic_box.cpp
 */

#include "magic_box.h"

namespace csc232
{
    // Task 1b - Define MagicBox
    template<typename T>
    MagicBox<T>::MagicBox() : PlainBox<T>() {}

    template<typename T>
    MagicBox<T>::MagicBox(const T& item) : PlainBox<T>(item) {}
}
