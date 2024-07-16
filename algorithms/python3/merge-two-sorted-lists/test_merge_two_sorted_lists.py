import unittest
from merge_two_sorted_lists import Solution, ListNode


class TestMergeTwoSortedLists(unittest.TestCase):
    def test_not_empty_lists(self):
        s = Solution()

        # 1->2->4
        l1 = ListNode(1, ListNode(2, ListNode(4)))

        # 1->3->5
        l2 = ListNode(1, ListNode(3, ListNode(5)))
        result = s.mergeTwoLists(l1, l2)

        self.assertEqual(result.val, 1)
        self.assertEqual(result.next.val, 1)
        self.assertEqual(result.next.next.val, 2)

    def test_single_empty_list(self):
        s = Solution()

        l1 = None

        # 1->3->5
        l2 = ListNode(1, ListNode(3, ListNode(5)))
        result = s.mergeTwoLists(l1, l2)

        self.assertEqual(result.val, 1)
        self.assertEqual(result.next.val, 3)
        self.assertEqual(result.next.next.val, 5)

    def test_empty_lists(self):
        s = Solution()

        # 1->2->4
        l1 = None

        l2 = None
        result = s.mergeTwoLists(l1, l2)

        self.assertEqual(result, None)


if __name__ == "__main__":
    unittest.main(verbosity=2)
