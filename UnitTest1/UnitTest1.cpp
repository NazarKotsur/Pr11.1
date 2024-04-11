#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr11.1/Pr11.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestProcessFunction)
        {
            char fname[] = "test_input.bin";
            char gname[] = "test_output.bin";

            ofstream testInput(fname, ios::binary);
            double testValues[] = { -1.0, 0.0, 1.0, 2.0, 3.0 };
            for (double val : testValues) {
                testInput.write(reinterpret_cast<const char*>(&val), sizeof(val));
            }
            testInput.close();

            Process(fname, gname);

            ifstream expectedOutput(gname, ios::binary);

            double expectedFilteredValues[] = { 2.0, 3.0 };
            double actualValue;
            size_t index = 0;
            while (expectedOutput.read(reinterpret_cast<char*>(&actualValue), sizeof(actualValue))) {
                Assert::AreEqual(expectedFilteredValues[index], actualValue);
                index++;
            }
            Assert::AreEqual(sizeof(expectedFilteredValues) / sizeof(expectedFilteredValues[0]), index);

            expectedOutput.close();
            remove(fname);
            remove(gname);
        }
    };
}