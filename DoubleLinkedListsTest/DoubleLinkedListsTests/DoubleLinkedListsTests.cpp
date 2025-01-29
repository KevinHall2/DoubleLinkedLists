#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedListsTest/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListsTests
{
	TEST_CLASS(DoubleLinkedListsTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			List<int> list;
			Assert::AreEqual(list.first(), 0);
			Assert::AreEqual(list.last(), 0);
			Assert::AreEqual(list.getLength(), 0);
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9, 8, 7, 6, 5 };
			Iterator<int> iter = list.begin();
			Assert::AreEqual(*iter, 9);
			iter++;
			Assert::AreEqual(*iter, 8);
			iter++;
			Assert::AreEqual(*iter, 7);
			iter++;
			Assert::AreEqual(*iter, 6);
			iter++;
			Assert::AreEqual(*iter, 5);
			Assert::AreEqual(list.getLength(), 5);

		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 1);

			list.pushFront(2);
			Assert::AreEqual(list.first(), 2);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 2);

			list.pushFront(3);
			Assert::AreEqual(list.first(), 3);
			Assert::AreEqual(*(list.begin()++), 2);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 3);
		}
	};
}
