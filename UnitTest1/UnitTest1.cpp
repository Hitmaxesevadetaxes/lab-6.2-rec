#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 6.2 rec\lab 6.2 rec\Source.cpp" // Замініть на відносний шлях, якщо можливо

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestfindMinOddIndexRecursive)
        {
            const int size = 5;
            int arr[size] = { 2, 3, 5, 7, 4 };
            int minOddIndex = findMinOddIndexRecursive(arr, size);


            Assert::AreEqual(1, minOddIndex);


            Assert::AreEqual(3, arr[minOddIndex]);
        };
    };
}