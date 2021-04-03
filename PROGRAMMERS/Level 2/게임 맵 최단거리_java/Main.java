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
    public int solution(int[][] maps) {
        int answer = 0;

        int sizeH = maps.length;
        int sizeW = maps[0].length;

        GraphSearch graphSearch = new GraphSearch();
        graphSearch.matrix = maps;
        graphSearch.visit = new boolean[sizeH][sizeW];
        graphSearch.setSize(sizeW, sizeH);

        answer = graphSearch.BFS(0,0);

        return answer;
    }
}

class GraphSearch {
    int sizeX, sizeY;
    int[][] matrix;
    boolean[][] visit;

    //우 좌 하 상 우하 우상 좌하 좌상
    //문제에 따라 방향은 수정
    int[] moveX = new int[]{1, -1, 0, 0};
    int[] moveY = new int[]{0, 0, 1, -1};

    void setSize(int sizeX, int sizeY) {
        this.sizeX = sizeX;
        this.sizeY = sizeY;
    }

    void DFS(Integer x, Integer y) {
        if (visit[y][x]) {
            return;
        }

        visit[y][x] = true;

        for (int i = 0; i < 8; ++i) {
            int targetX = x + moveX[i];
            int targetY = y + moveY[i];

            if (targetX >= 0 && targetX < sizeX && targetY >= 0 && targetY < sizeY) {
                if (matrix[targetY][targetX] == 1 && !visit[targetY][targetX]) {
                    DFS(targetX, targetY);
                }
            }
        }
    }

    int BFS(int x, int y) {
        int destinationX = sizeX - 1;
        int destinationY = sizeY - 1;

        int result = -1;

        Queue<location> BFS_queue = new LinkedList<>();

        BFS_queue.add(new location(x, y, 1));

        while (!BFS_queue.isEmpty()) {
            location loc = BFS_queue.poll();
            int score = loc.score;

            if (loc.x == destinationX && loc.y == destinationY) {
                result = score;
                break;
            }

            for (int i = 0; i < moveX.length; ++i) {
                int targetX = loc.x + moveX[i];
                int targetY = loc.y + moveY[i];

                if (targetX >= 0 && targetX < sizeX && targetY >= 0 && targetY < sizeY) {
                    if (matrix[targetY][targetX] == 1 && !visit[targetY][targetX]) {
                        visit[targetY][targetX] = true;
                        BFS_queue.add(new location(targetX, targetY, score + 1));
                    }
                }
            }
        }

        return result;
    }

    static public class location {
        int x, y, score;

        public location(int x, int y, int score) {
            this.x = x;
            this.y = y;
            this.score = score;
        }
    }
}
