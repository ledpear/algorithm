import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int matrixSize = Integer.parseInt(st.nextToken());
        int testcaseSize = Integer.parseInt(st.nextToken());

        int[][] matrix = new int[matrixSize][matrixSize];
        for(int i = 0; i < matrixSize; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < matrixSize; ++j){
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }
 
        Solution solution = new Solution();
        solution.setDpMatrix(matrix);

        for(int i = 0; i < testcaseSize; ++i){
            st = new StringTokenizer(br.readLine());
            int startX = Integer.parseInt(st.nextToken());
            int startY = Integer.parseInt(st.nextToken());
            int endX = Integer.parseInt(st.nextToken());
            int endY = Integer.parseInt(st.nextToken());

            System.out.println(solution.getResult(matrix, startX, startY, endX, endY));
        }
    }
}

class Solution {
    public void setDpMatrix(int[][] matrix){
        int matrixSize = matrix.length;
        for(int x = 0; x < matrixSize; ++x){
            for(int y = 0; y < matrixSize; ++y){
                if(x > 0){
                    matrix[x][y] += matrix[x - 1][y];
                }
                if(y > 0){
                    matrix[x][y] += matrix[x][y - 1];
                }
                if(x > 0 && y > 0){
                    matrix[x][y] -= matrix[x - 1][y - 1];
                }
            }
        }
    }

    public int getResult(int[][] dpMatrix, int startX, int startY, int endX, int endY){
        startX -= 1;
        startY -= 1;
        endX -= 1;
        endY -= 1;

        int result = dpMatrix[endX][endY];

        if(startX > 0){
            result -= dpMatrix[startX - 1][endY];
        }
        if(startY > 0){
            result -= dpMatrix[endX][startY - 1];
        }
        if(startX > 0 && startY > 0){
            result += dpMatrix[startX - 1][startY - 1];
        }

        return result;
    }
}