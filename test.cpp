// daniisakov@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <sstream>

using namespace ariel;

TEST_CASE("Basic container operations") {
    MyContainer<int> container;
    
    // Test empty container
    CHECK(container.size() == 0);
    
    // Test adding elements
    container.addElement(5);
    CHECK(container.size() == 1);
    
    container.addElement(3);
    container.addElement(8);
    CHECK(container.size() == 3);
}

TEST_CASE("Remove operations") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    
    // Remove existing element
    container.remove(2);
    CHECK(container.size() == 2);
    
    // Try to remove non-existing element
    CHECK_THROWS(container.remove(99));
}

TEST_CASE("Print container") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    
    std::ostringstream oss;
    oss << container;
    CHECK(oss.str() == "[1, 2, 3]");
}

TEST_CASE("Ascending order") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);
    
    std::vector<int> result;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        result.push_back(*it);
    }
    
    CHECK(result.size() == 3);
    CHECK(result[0] == 1);
    CHECK(result[1] == 2);
    CHECK(result[2] == 3);
}

TEST_CASE("Descending order") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(2);
    
    std::vector<int> result;
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        result.push_back(*it);
    }
    
    CHECK(result.size() == 3);
    CHECK(result[0] == 3);
    CHECK(result[1] == 2);
    CHECK(result[2] == 1);
}

TEST_CASE("Original order") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(9);
    
    std::vector<int> result;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        result.push_back(*it);
    }
    
    CHECK(result.size() == 3);
    CHECK(result[0] == 5);
    CHECK(result[1] == 1);
    CHECK(result[2] == 9);
}

TEST_CASE("String container") {
    MyContainer<std::string> container;
    container.addElement("hello");
    container.addElement("world");
    
    CHECK(container.size() == 2);
    
    std::ostringstream oss;
    oss << container;
    CHECK(oss.str() == "[hello, world]");
} 