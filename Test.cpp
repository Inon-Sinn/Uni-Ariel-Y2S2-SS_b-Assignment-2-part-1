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
    CHECK_THROWS(testBook.write(100,100,100000, Direction::Vertical,"test"));
    // read after the end of the line
    CHECK_THROWS(testBook.read(0,0,100, Direction::Vertical,1));
    CHECK_THROWS(testBook.read(100,100,100000, Direction::Vertical,1));
    CHECK_THROWS(testBook.read(0,0,100, Direction::Vertical,0));
    CHECK_THROWS(testBook.read(100,100,100000, Direction::Vertical,0));
    // erase after the end of the line
    CHECK_THROWS(testBook.erase(0,0,100, Direction::Vertical,1));
    CHECK_THROWS(testBook.erase(100,100,100000, Direction::Vertical,1));
    CHECK_THROWS(testBook.erase(0,0,100, Direction::Vertical,0));
    CHECK_THROWS(testBook.erase(100,100,100000, Direction::Vertical,0));
};

// it's impossible to test every thing alone, so we will combine the test for write,read and erase
TEST_CASE("Combined Test"){
    ariel::Notebook testBook;
    
    //read on an empty Notebook - vertical
    CHECK_EQ(testBook.read(0,0,0,Direction::Vertical,0),"");
    CHECK_EQ(testBook.read(0,0,0,Direction::Vertical,5),"_____");

    //read on an empty Notebook - horizontal
    CHECK_EQ(testBook.read(0,0,0,Direction::Horizontal,0),"");
    CHECK_EQ(testBook.read(0,0,0,Direction::Horizontal,5),"_____");

    // Basic writing tests - vertical
    testBook.write(0,0,0,Direction::Vertical,"test");
    CHECK_EQ(testBook.read(0,0,0,Direction::Vertical,5),"test_");

    // Basic writing tests - horizontal
    testBook.write(1,0,0,Direction::Horizontal,"test");
    CHECK_EQ(testBook.read(1,0,0,Direction::Horizontal,5),"test_");

    // writing Errors tests - overwriting writen text
    testBook.write(2,0,0,Direction::Horizontal,"test");
    CHECK_THROWS(testBook.write(2,0,0,Direction::Vertical,"test"));
    CHECK_THROWS(testBook.write(2,0,0,Direction::Horizontal,"test"));
    CHECK_NOTHROW(testBook.write(2,0,0,Direction::Vertical,""));
    CHECK_NOTHROW(testBook.write(2,0,0,Direction::Horizontal,""));

    // writing Errors tests - overwriting ereased text
    testBook.erase(3,0,0,Direction::Horizontal,5);
    CHECK_THROWS(testBook.write(3,0,0,Direction::Vertical,"test"));
    CHECK_THROWS(testBook.write(3,0,0,Direction::Horizontal,"test"));
    CHECK_NOTHROW(testBook.write(3,0,0,Direction::Vertical,""));
    CHECK_NOTHROW(testBook.write(3,0,0,Direction::Horizontal,""));

    // simple erase tests

    
};