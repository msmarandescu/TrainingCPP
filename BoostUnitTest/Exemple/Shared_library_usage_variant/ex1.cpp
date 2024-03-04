#define BOOST_TEST_MODULE Suites
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
namespace utf = boost::unit_test;
#include <iostream>
#include <fstream>



struct fileManager
{
    static fileManager& instance()
    {
        static fileManager f;
        return f;
    }
    void writeFile(const std::string& fileName, const std::string& message)
    {
        std::ofstream writeStream(fileName,std::ofstream::trunc); //open in overwrite mode
        if(!writeStream.is_open())
        {
            std::cout << "Eroare la deschiderea fișierului: " << fileName << std::endl;
            return;
        }
        writeStream << message;
        writeStream.close();
    }

    const std::string readFile(const std::string& fileName)
    {
        std::ifstream fisier(fileName);
        std::string continut;

        if (fisier.is_open()) 
        {
            std::string linie;
            while (getline(fisier, linie)) {
                continut += linie; 
                continut.push_back('\n'); 
            }
            fisier.close();
        } else {
            std::cout << "Nu am putut deschide fisierul.";
        }
        return continut;
    }
};

BOOST_AUTO_TEST_SUITE(Maths)
BOOST_AUTO_TEST_CASE(SimpleText_Test)
{
    std::string testStr = "hello";
    fileManager::instance().writeFile("test.txt", testStr);
    BOOST_CHECK(fileManager::instance().readFile("test.txt").compare(testStr));
}

BOOST_AUTO_TEST_CASE(MultipleLines_Test)
{
    std::string testStr = "hello! \n How \n are \n you?";
    fileManager::instance().writeFile("test.txt", testStr);
    BOOST_CHECK(fileManager::instance().readFile("test.txt").compare(testStr));
}


BOOST_AUTO_TEST_SUITE_END()