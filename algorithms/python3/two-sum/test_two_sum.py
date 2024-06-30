import unittest
from two_sum import Solution


class TestTwoSum(unittest.TestCase):
    def test_twoSum(self):
        s = Solution()
        self.assertEqual(s.twoSum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(s.twoSum([3, 2, 4], 6), [1, 2])
        self.assertEqual(s.twoSum([3, 3], 6), [0, 1])
        self.assertEqual(s.twoSum([1], 1), [])


if __name__ == "__main__":
    unittest.main(verbosity=2)
