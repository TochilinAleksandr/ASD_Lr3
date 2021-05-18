#include "pch.h"
#include "CppUnitTest.h"
#include "../Tochilin_lr3/Lr3.h"
#include "../Tochilin_lr3/Lr3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		DijkstraAlgorithm* test1 = new DijkstraAlgorithm("../UnitTest1/tests/test1.txt");
		DijkstraAlgorithm* test2 = new DijkstraAlgorithm("../UnitTest1/tests/test2.txt");
		DijkstraAlgorithm* test3 = new DijkstraAlgorithm("../UnitTest1/tests/test3.txt");
		DijkstraAlgorithm* test4 = new DijkstraAlgorithm("../UnitTest1/tests/test4.txt");
		TEST_METHOD(TestAlgorithm)
		{
			Assert::AreEqual(9, test1->getMinPrice("Perm", "St. Petersburg"));
			Assert::AreEqual(8, test1->getMinPrice("Perm", "Novosibirsck"));
			Assert::AreEqual(-1, test1->getMinPrice("Novosibirsck", "Perm"));
			Assert::AreEqual(9, test2->getMinPrice("Perm", "Novosibirsck"));
			Assert::AreEqual(2, test2->getMinPrice("Moscow", "St. Petersburg"));
			Assert::AreEqual(-1, test2->getMinPrice("Novosibirsck", "St. Petersburg"));
			Assert::AreEqual(13, test3->getMinPrice("Perm", "St. Petersburg"));
			Assert::AreEqual(10, test3->getMinPrice("Perm", "Irkutsck"));
			Assert::AreEqual(14, test3->getMinPrice("Perm", "Novosibirsck"));
			Assert::AreEqual(5, test3->getMinPrice("Novosibirsck", "Moscow"));
			Assert::AreEqual(4, test3->getMinPrice("Moscow", "Irkutsck"));
			Assert::AreEqual(7, test3->getMinPrice("St. Petersburg", "Irkutsck"));
			Assert::AreEqual(5, test4->getMinPrice("Perm", "Novosibirsck"));
			Assert::AreEqual(10, test4->getMinPrice("Moscow", "Novosibirsck"));
			Assert::AreEqual(8, test4->getMinPrice("Irkutsck", "Novosibirsck"));
			Assert::AreEqual(9, test4->getMinPrice("St. Petersburg", "Novosibirsck"));
			Assert::AreEqual(14, test4->getMinPrice("Rostov", "Novosibirsck"));
			Assert::AreEqual(10, test4->getMinPrice("Rostov", "Irkutsck"));
			Assert::AreEqual(12, test4->getMinPrice("Rostov", "Moscow"));
			Assert::AreEqual(13, test4->getMinPrice("Rostov", "St. Petersburg"));
			Assert::AreEqual(9, test4->getMinPrice("Rostov", "Perm"));
			Assert::AreEqual(8, test4->getMinPrice("Irkutsck", "Novosibirsck"));
			Assert::AreEqual(15, test4->getMinPrice("Irkutsck", "Rostov"));
			Assert::AreEqual(15, test4->getMinPrice("Irkutsck", "Perm"));
		}
	};
}
