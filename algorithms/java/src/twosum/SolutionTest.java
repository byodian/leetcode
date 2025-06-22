package twosum;

import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;


public class SolutionTest {

    @Test
    public void shouldFindTarget() {
        int[] result;
        int[] nums = { 2, 7, 11, 15 };
        int target = 9;
        result = new Solution().twoSum(nums, target);
        assertEquals(result[1], 1);
    }

}
