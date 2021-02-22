import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;

public class codingTest{
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println("test");
    }
}

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> Result = new ArrayList();
        List<Integer> nList = new ArrayList();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for(int i = 0; i < nums.length; i++)
        {
            nList.add(nums[i]);
            if(map.containsKey(nums[i]))
                map.replace(nums[i], map.get(nums[i]) + 1);
            else
                map.put(nums[i], 1);
        }
        nList.sort(Comparator.naturalOrder());
        
        for(int i = 0; i < nums.length - 2; i++)
        {
            for(int j = i + 1; j < nums.length - 1; j++)
            {
                int nTarget = -(nList.get(i) + nList.get(j));

                if(map.containsKey(nTarget))
                {
                    List<Integer> temp = new ArrayList();
                    temp.add(nList.get(i));
                    temp.add(nList.get(j));
                    temp.add(nTarget);
                    if(!Result.contains(temp))
                        Result.add(temp);
                }

                if(!map.containsKey(nList.get(j)))
                {
                    map.put(nList.get(j), 1);
                }
            }
        }


        return Result;
    }
}