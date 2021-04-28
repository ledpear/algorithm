import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        Solution solution = new Solution();
        int[][] queries = {	{2,2,5,4},{3,3,6,6},{5,1,6,3}};
        int[] result = solution.solution(6, 6, queries);
        System.out.println(result);
    }
}

class Solution {
    public static final int ZERO = 0;

    public static final int QUERIES_MIN_X = 0;
    public static final int QUERIES_MIN_Y = 1;
    public static final int QUERIES_MAX_X = 2;
    public static final int QUERIES_MAX_Y = 3;

    public static final int DIRECTION_MAX = 4;

    /*
    테스트 1 〉	통과 (0.25ms, 53.2MB)
테스트 2 〉	통과 (0.26ms, 51.9MB)
테스트 3 〉	통과 (29.72ms, 59.9MB)
테스트 4 〉	통과 (20.50ms, 59.4MB)
테스트 5 〉	통과 (25.08ms, 58.2MB)
테스트 6 〉	통과 (31.53ms, 60.6MB)
테스트 7 〉	통과 (30.74ms, 61.6MB)
테스트 8 〉	통과 (19.50ms, 57.1MB)
테스트 9 〉	통과 (25.13ms, 63.8MB)
테스트 10 〉	통과 (23.47ms, 59.6MB)
테스트 11 〉	통과 (8.27ms, 58.1MB)
     */
    public int[] solution(int rows, int columns, int[][] queries) {
        int queriesSzie = queries.length;
        int[] answer = new int[queriesSzie];

        int sizeX = rows;
        int sizeY = columns;

        //matrix 만들기
        int[][] matrix = new int[sizeX][sizeY];

        for(int x = ZERO; x < sizeX; ++x)
        {
            for(int y = ZERO; y < sizeY; ++y)
            {
                matrix[x][y] = x * sizeY + y + 1;
            }
        }

        for(int index = ZERO; index < queriesSzie; ++index)
        {
            answer[index] = Rotation(matrix, queries[index]);
        }

        return answer;
    }

    int Rotation(int[][] matrix, int[] location)
    {
        int min = Integer.MAX_VALUE;

        int minX = location[QUERIES_MIN_X] - 1;
        int minY = location[QUERIES_MIN_Y] - 1;
        int maxX = location[QUERIES_MAX_X] - 1;
        int maxY = location[QUERIES_MAX_Y] - 1;

        //진행방향 +y -> +x -> -y -> -x (Left -> Down -> Right -> Up)
        //진행을 -x -> -y -> +x -> +y로 하면 시간을 줄일수있지않을까?
        Point[] move = {new Point(1, 0), new Point(0, 1), new Point(-1, 0), new Point(0, -1)};
        Point nowPoint = new Point(minX, minY);
        int direction = ZERO;
        int saveValue = matrix[nowPoint.x][nowPoint.y];

        while(direction < DIRECTION_MAX)
        {
            int targetX = nowPoint.x + move[direction].x;
            int targetY = nowPoint.y + move[direction].y;

            min = Integer.min(matrix[nowPoint.x][nowPoint.y], min);

            if(minX <= targetX && minY <= targetY && maxX >= targetX && maxY >= targetY)
            {
                //교체
                /*int temp = matrix[targetX][targetY];
                matrix[targetX][targetY] = saveValue;
                saveValue = temp;*/

                matrix[nowPoint.x][nowPoint.y] = matrix[targetX][targetY];

                //이동
                nowPoint.x = targetX;
                nowPoint.y = targetY;
            }
            else
            {
                ++direction;
            }
        }

        matrix[nowPoint.x][nowPoint.y + 1] = saveValue;

        return min;
    }

    static public class Point
    {
        int x = ZERO;
        int y = ZERO;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
}