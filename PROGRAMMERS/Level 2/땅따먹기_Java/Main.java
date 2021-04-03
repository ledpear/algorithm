import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        Solution solution = new Solution();
    }
}

class Solution {
    int solution(int[][] land) {
        int answer = 0;

        int max = Integer.MIN_VALUE;
        int size = land.length;

        int[][] DP = new int[size][4];

        for(int index = 0; index < size; ++index)
        {
            if(index == 0)
            {
                for(int i = 0; i < 4; ++i)
                {
                    DP[index][i] = land[index][i];
                }
            }
            else
            {
                for(int i = 0; i < 4; ++i)
                {
                    max = Integer.MIN_VALUE;
                    for(int j = 0; j < 4; ++j)
                    {
                        if(i == j)
                        {
                            continue;
                        }

                        max = Integer.max(max, DP[index - 1][j]);
                    }
                    DP[index][i] = land[index][i] + max;
                }
            }
        }

        max = Integer.MIN_VALUE;
        for(int j = 0; j < 4; ++j)
        {
            max = Integer.max(max, DP[size - 1][j]);
        }

        return max;
    }
}