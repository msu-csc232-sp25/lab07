/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    task1_test.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Task 1 test fixture.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

#include "csc232_test_utils.h"
#include "magic_box.h"
#include <gtest/gtest.h>

namespace csc232
{
    class Task1TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task1TestFixture( ) = default;

        ~Task1TestFixture( ) override = default;

    protected:
        // Reusable objects for each unit test in this test fixture
    };

#if !TEST_TASK1
    TEST_F( Task1TestFixture, Bootstrap )
    {
        std::cerr << "Task 1 is not ready for evaluation; please toggle the TEST_TASK1 macro to TRUE\n";
        SUCCEED( ); // Just to keep spirits up out of the box ;-)
    }

#else
    static const int FIRST_ITEM{ 420 };
    static const int SECOND_ITEM{ 24 };
    // TODO: Add unit tests as needed for task 1
    TEST_F( Task1TestFixture, ItHasMagicByDefault )
    {
        auto mbox_ptr = std::make_unique<csc232::MagicBox<int>>( );
        mbox_ptr->set_item( FIRST_ITEM );
        auto expected{ FIRST_ITEM };
        auto actual{ mbox_ptr->get_item( ) };
        EXPECT_EQ( expected, actual );
        mbox_ptr->set_item( SECOND_ITEM );
        actual = mbox_ptr->get_item( );
        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task1TestFixture, ItHasMagicUponInitialization )
    {
        auto mbox_ptr = std::make_unique<csc232::MagicBox<int>>( FIRST_ITEM );
        auto expected{ FIRST_ITEM };
        auto actual{ mbox_ptr->get_item( ) };
        EXPECT_EQ( expected, actual );
        mbox_ptr->set_item( SECOND_ITEM );
        actual = mbox_ptr->get_item( );
        EXPECT_EQ( expected, actual );
    }
#endif

} // end namespace csc232
