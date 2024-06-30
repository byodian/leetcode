import twoSum from "./two-sum";
import { expect, test } from 'vitest'

test('returns indices of the two numbers such that they add up to the target', () => {
  expect(twoSum([2, 7, 11, 15], 9)).toEqual([0, 1]);
  expect(twoSum([3, 2, 4], 6)).toEqual([1, 2]);
  expect(twoSum([3, 3], 6)).toEqual([0, 1]);
});

test('returns an empty array if no two numbers add up to the target', () => {
  expect(twoSum([1, 2, 3], 7)).toEqual([]);
});

test('handles negative numbers', () => {
  expect(twoSum([-1, -2, -3, -4, -5], -8)).toEqual([2, 4]);
  expect(twoSum([1, -2, 3, -4, 5], 1)).toEqual([1, 2]);
});

test('handles an empty array', () => {
  expect(twoSum([], 0)).toEqual([]);
});

test('handles an array with one element', () => {
  expect(twoSum([1], 1)).toEqual([]);
});
