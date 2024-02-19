#include "pch.h"
#include "CppUnitTest.h"
#include "../Ranked Ballot Counter/main.hpp"
//#include "../Ranked Ballot Counter/voter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//
			//Voter v("a", "b", "c", "c");
			Candidate c = Candidate("something");
			Assert::AreEqual(true, true);
		}
	};
}
