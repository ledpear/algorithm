import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Solution solution = new Solution();

        while(true)
        {
            //matrix size 입력
            st = new StringTokenizer(br.readLine());

            int sizeW = Integer.parseInt(st.nextToken());
            int sizeH = Integer.parseInt(st.nextToken());

            //입력받은 크기가 0이면 종료
            if(sizeH == 0 && sizeW == 0)
            {
                break;
            }

            //matrix 입력
            int[][] matrix = new int[sizeH][sizeW];

            for(int h = 0; h < sizeH; ++h)
            {
                st = new StringTokenizer(br.readLine());

                for(int w = 0; w < sizeW; ++w)
                {
                    matrix[h][w] = Integer.parseInt(st.nextToken());
                }
            }

            System.out.println(solution.solution(matrix, sizeW, sizeH));
        }
    }
}

class Solution {
    int sizeX, sizeY;
    int[][] matrix;
    boolean[][] visit;

    //우 좌 하 상 우하 우상 좌하 좌상
    //문제에 따라 방향은 수정
    int[] moveX = new int[]{1, -1, 0, 0, 1, 1, -1, -1};
    int[] moveY = new int[]{0, 0, 1, -1, 1, -1, 1, -1};

    void DFS(Integer x, Integer y)
    {
        if(visit[y][x])
        {
            return;
        }

        visit[y][x] = true;

        for(int i = 0; i < 8; ++i)
        {
            int targetX = x + moveX[i];
            int targetY = y + moveY[i];

            if(targetX >= 0 && targetX < sizeX && targetY >= 0 && targetY < sizeY)
            {
                if(matrix[targetY][targetX] == LAND && !visit[targetY][targetX])
                {
                    DFS(targetX, targetY);
                }
            }
        }
    }

    public static final int LAND = 1;
    public static final int SEA = 0;

    int solution(int[][] mtx, int sizeW, int sizeH)
    {
        int result = 0;
        sizeY = sizeH;
        sizeX = sizeW;

        //배열 초기화
        matrix = mtx;
        visit = new boolean[sizeH][sizeW];

        for(int h = 0; h < sizeH; ++h)
        {
            for(int w = 0; w < sizeW; ++w)
            {
                if(matrix[h][w] == LAND && visit[h][w] == false)
                {
                    DFS(w, h);
                    ++result;
                }
            }
        }

        return result;
    }
}