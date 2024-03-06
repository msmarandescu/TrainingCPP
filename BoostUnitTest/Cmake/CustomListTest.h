#define BOOST_TEST_MODULE CustomListTest
#include <boost/test/included/unit_test.hpp>

// Include CustomList class header:
#include "/home/projectx/Desktop/Git_Repo/TrainingCPP/BoostUnitTest/Cmake/CustomList.h"


// Define a test suite for the CustomList class
BOOST_AUTO_TEST_SUITE(CustomListTestSuite)

// Test the insertData method
BOOST_AUTO_TEST_CASE(TestInsertData) {
    CustomList<int>& listInt = CustomList<int>::getInstance();
    listInt.insertData(42);
    BOOST_CHECK_EQUAL(listInt.getSize(), 1);
    BOOST_CHECK_EQUAL(listInt.getData(), 42);
}

// Test the getData method
BOOST_AUTO_TEST_CASE(TestGetData) {
    CustomList<int>& listInt = CustomList<int>::getInstance();
    listInt.insertData(35);
    int val = listInt.getData();
    BOOST_CHECK_EQUAL(val, 35);
    BOOST_CHECK_EQUAL(listInt.getSize(), 0);
}

// Test the getSize method
BOOST_AUTO_TEST_CASE(TestGetSize) {
    CustomList<int>& listInt = CustomList<int>::getInstance();
    listInt.insertData(1);
    listInt.insertData(87);
    listInt.insertData(33);

    BOOST_CHECK_EQUAL(listInt.getSize(), 3);
}

// Test the display method
BOOST_AUTO_TEST_CASE(TestDisplay) {
    // Testul presupune că metoda display() funcționează corect și afișează lista introdusa la testul anterior
    // Aici puteți verifica manual dacă lista este afișată corect pe stdout

    CustomList<int>& listInt = CustomList<int>::getInstance();
    listInt.display();

    BOOST_CHECK_EQUAL(listInt.getSize(), 3);
}

// Test if class CustomList is singleton
BOOST_AUTO_TEST_CASE(TestSingleton) {
    CustomList<int>& listInt1 = CustomList<int>::getInstance();
    CustomList<int>& listInt2 = CustomList<int>::getInstance();

    BOOST_CHECK_EQUAL(&listInt1, &listInt2);
}

BOOST_AUTO_TEST_SUITE_END()


