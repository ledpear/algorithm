import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int size = Integer.parseInt(br.readLine());
        ArrayList<String > matrix = new ArrayList<>();

        for(int i = 0; i < size; ++i)
        {
            matrix.add(br.readLine());
        }
 
        Solution solution = new Solution();
        Integer[] answer = solution.solution(size, matrix);
        System.out.println(Integer.toString(answer[0]) + ' ' + Integer.toString(answer[1]));
    }
}

class Solution {
    Integer[] move_x = {1, -1, 0, 0};
    Integer[] move_y = {0, 0, 1, -1};
    boolean[][] visit;
    int size;
    ArrayList<String> matrix;

    public Integer[] solution(int size, ArrayList<String> matrix){
        Integer[] answer = new Integer[2];
        this.size = size;
        this.matrix = matrix;

        int count = 0;
        visit = new boolean[size][size];
        for(int x = 0; x < size; ++x){
            for(int y = 0; y < size; ++y){
                if(!visit[x][y]){
                    ++count;
                    Character[] checks = {matrix.get(x).charAt(y)};
                    BFS(x, y, checks);
                }
            }
        }
        answer[0] = count;

        count = 0;
        visit = new boolean[size][size];
        for(int x = 0; x < size; ++x){
            for(int y = 0; y < size; ++y){
                if(!visit[x][y]){
                    ++count;
                    Character[] checks;
                    if(matrix.get(x).charAt(y) == 'R' || matrix.get(x).charAt(y) == 'G'){
                        checks = new Character[]{'R', 'G'};
                    }
                    else{
                        checks = new Character[]{'B'};
                    }

                    BFS(x, y, checks);
                }
            }
        }
        answer[1] = count;

        return answer;
    }

    public void BFS(int x, int y, Character[] checks){
        Queue<int[]> queue = new LinkedList<>();

        visit[x][y] = true;
        int[] temp = new int[2];
        temp[0] = x;
        temp[1] = y;
        queue.add(temp);

        while(!queue.isEmpty()){
            int[] now_pos = queue.poll();

            for(int i = 0; i < 4; ++i){
                int pos_x = now_pos[0] + move_x[i];
                int pos_y = now_pos[1] + move_y[i];

                if(pos_x >= 0 && pos_y >= 0 && pos_x < size && pos_y < size && !visit[pos_x][pos_y]){
                    for(Character check : checks){
                        if(matrix.get(pos_x).charAt(pos_y) == check){
                            visit[pos_x][pos_y] = true;
                            temp = new int[2];
                            temp[0] = pos_x;
                            temp[1] = pos_y;
                            queue.add(temp);
                            break;
                        }
                    }
                }
            }
        }
    }
}