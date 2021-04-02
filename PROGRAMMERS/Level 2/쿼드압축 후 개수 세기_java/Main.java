import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        Solution solution = new Solution();
        int[][] arr = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
        int[] result = solution.solution(arr);
    }
}

class Solution {
    int[] point = new int[2];

    public int[] solution(int[][] arr) {
        int[] answer = new int[2];
        point = new int[2];

        QuadTree(arr);

        answer[0] = point[0];
        answer[1] = point[1];

        return answer;
    }

    void QuadTree(int[][] arr)
    {
        int length = arr.length;
        int startVal = arr[0][0];
        boolean pass = true;

        if(length <= 1)
        {
            ++point[startVal];
            return;
        }

        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < length; ++j)
            {
                if(!(startVal == arr[i][j]))
                {
                    pass = false;
                    break;
                }
            }
            if(!pass)
            {
                break;
            }
        }

        if(pass)
        {
            ++point[startVal];
            return;
        }
        else {
            int halfLength = length / 2;
            int[][] halfArr = new int[halfLength][halfLength];

            int[] posX = {0, 0, halfLength, halfLength};
            int[] posY = {0, halfLength, 0, halfLength};

            //4방향 순회
            for (int i = 0; i < 4; ++i) {
                //분리된 배열 만들기
                for (int j = 0; j < halfLength; ++j) {
                    halfArr[j] = Arrays.copyOfRange(arr[posY[i] + j], posX[i], posX[i] + halfLength);
                }
                QuadTree(halfArr);
            }
        }
        return;
    }
}