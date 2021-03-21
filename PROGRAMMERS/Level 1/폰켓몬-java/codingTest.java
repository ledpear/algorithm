import java.util.*;

public class codingTest{
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[]nums = {3,1,2,3};
        System.out.println(solution.solution(nums));
        
    }
}

class Solution {
    public int solution(int[] nums) {
        int answer = 0;

        int size = nums.length / 2;
        int kinds = 0;
        Set<Integer> set = new HashSet<Integer>();
        
        for(int ponketmon : nums)
        {
            if(set.add(ponketmon))
            {
                kinds += 1;
            }
        }

        if(kinds > size)
        {
            answer = size;
        }
        else
        {
            answer = kinds;
        }

        return answer;
    }
}