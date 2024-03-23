#include "pch.h"
#include "CppUnitTest.h"
#include "../vse/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int rowCount = 8;
            const int colCount = 6;
            int** z = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
                z[i] = new int[colCount];

            Create(z, rowCount, colCount, -10, 10);

            for (int i = 0; i < rowCount; ++i)
                for (int j = 0; j < colCount; ++j)
                    Assert::IsTrue(z[i][j] >= -10 && z[i][j] <= 10);

            for (int i = 0; i < rowCount; ++i)
                delete[] z[i];
            delete[] z;
        }
    };
}
