#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedList/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListsTests
{
	TEST_CLASS(DoubleLinkedListsTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			List<int> list;
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = List<int>({ 9, 8, 7, 6, 5 });
			Iterator<int> iter = list.begin();
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(8, *iter);
			iter++;
			Assert::AreEqual(7, *iter);
			iter++;
			Assert::AreEqual(6, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			Assert::AreEqual(list.getLength(), 5);

		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushFront(2);
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushFront(3);
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.pushBack(1);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushBack(2);
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.getLength());

			list.pushBack(3);
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(2, *(list.end()--));
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PopFront)
		{
			List<int> list;
			list.pushFront(1);
			list.pushFront(2);
			list.pushFront(3);
			list.popFront();
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(2, list.getLength());
		}

		TEST_METHOD(PopBack)
		{
			List<int> list;
			list.pushFront(1);
			list.pushFront(2);
			list.pushFront(3);
			list.popBack();
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(2, list.getLength());
		}

		TEST_METHOD(Insert)
		{
			List<int> list;
			list.pushFront(1);
			list.pushFront(1);
			list.insert(1, 1);
			Assert::AreEqual(3, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
		}

		TEST_METHOD(Remove)
		{
			List<int> list;
			Assert::IsNotNull(&list);
			list.pushBack(1);
			list.pushBack(0);
			list.pushBack(1);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(3);
			list.pushBack(1);
			Assert::AreEqual(7, list.getLength());
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(1, *iter);

			int count = list.remove(1);
			Assert::AreEqual(4, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(*iter, list.first());
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			Assert::AreEqual(*iter, list.last());

			//test for when removing a value that isn't in the list
			count = list.remove(5);
			Assert::AreEqual(0, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			

			//test for the entire list being the same value
			list = List<int>();
			Assert::IsNotNull(&list);
			list.pushBack(3);
			list.pushBack(3);
			list.pushBack(3);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			count = list.remove(3);
			Assert::AreEqual(3, count);
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			
			
		}

		TEST_METHOD(Destroy)
		{
			List<int> list;
			list.pushFront(1);
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());

			list.pushFront(1);
			list.pushFront(2);
			list.popFront();
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());

			list.pushFront(1);
			list.pushFront(2);
			list.popBack();
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());

			list.pushFront(1);
			list.pushFront(2);
			list.pushFront(3);
			list.pushFront(4);
			list.popBack();
			list.popFront();
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
		}


		//the first, last, begin, and end functions are being used in every other test
	};
}
