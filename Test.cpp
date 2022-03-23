/**
 * AUTHORS: Inon Sinn
 * 
 * Date: 23/03/2022
 */

#include "Notebook.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

using namespace ariel;

// tests for cases where we pass the limit of 100 char in a row,
TEST_CASE("Bad input"){
    ariel::Notebook testBook;

    // write after the end of the line
    CHECK_THROWS(testBook.write(0,0,100, Direction::Vertical,"test"));
    CHECK_THROWS(testBook.write(0,0,100000, Direction::Vertical,"test"));
    // read after the end of the line
    CHECK_THROWS(testBook.read(0,0,100, Direction::Vertical,1));
    CHECK_THROWS(testBook.read(0,0,100000, Direction::Vertical,1));
    CHECK_THROWS(testBook.read(0,0,100, Direction::Vertical,0));
    CHECK_THROWS(testBook.read(0,0,100000, Direction::Vertical,0));
    // erase after the end of the line
    CHECK_THROWS(testBook.erase(0,0,100, Direction::Vertical,1));
    CHECK_THROWS(testBook.erase(0,0,100000, Direction::Vertical,1));
    CHECK_THROWS(testBook.erase(0,0,100, Direction::Vertical,0));
    CHECK_THROWS(testBook.erase(0,0,100000, Direction::Vertical,0));
};

TEST_CASE("Test for 'write' and 'read'"){
    ariel::Notebook testBook;
    
    // Good Input
    // CHECK_EQ(testBook.write)
};

TEST_CASE("Function: read"){
    ariel::Notebook testBook;

};

TEST_CASE("Function: erase"){
    ariel::Notebook testBook;

};