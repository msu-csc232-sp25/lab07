/**
 * @file expanded_templates.cpp
 */

#include "csc232.h"
// NOLINTBEGIN(bugprone-suspicious-include)
#include "plain_box.cpp"

template class csc232::PlainBox<int>;

#if TEST_TASK1
#include "magic_box.cpp"
template class csc232::MagicBox<int>;
#endif

#if TEST_TASK2
#include "safe.cpp"
template class csc232::Safe<int>;
#endif
// NOLINTEND(bugprone-suspicious-include)
