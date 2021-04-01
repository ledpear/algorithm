import java.util.*;
import java.io.*;

class GraphSearch {
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

    void BFS(int x, int y)
    {
        Queue<location> BFS_queue = new LinkedList<>();

        BFS_queue.add(new location(x, y));

        while(!BFS_queue.isEmpty())
        {
            location loc = BFS_queue.poll();

            for(int i = 0; i < 8; ++i)
            {
                int targetX = loc.x + moveX[i];
                int targetY = loc.y + moveY[i];

                if(targetX >= 0 && targetX < sizeX && targetY >= 0 && targetY < sizeY)
                {
                    if(matrix[targetY][targetX] == LAND && !visit[targetY][targetX])
                    {
                        visit[targetY][targetX] = true;
                        BFS_queue.add(new location(targetX, targetY));
                    }
                }
            }
        }
    }

    static public class location
    {
        int x, y;

        public location(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
}