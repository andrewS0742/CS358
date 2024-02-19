#include "pch.h"
#include "CppUnitTest.h"

#include "../Ranked Ballot Counter/voter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Voter v{ "a", "b", "c", "d" };
		}
	};
}
