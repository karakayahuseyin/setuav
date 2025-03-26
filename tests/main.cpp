#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"
#include <Airframe/Airframe.hpp>

/**
 * Doctest implementation tests.
 */

TEST_CASE("Airframe test")
{
    Airframe airframe;
    CHECK(true);
}

TEST_CASE("Airframe test 2")
{
    if(0 == 1)
    {
        CHECK(true);
    }
    else {
        CHECK(false);
    }
}