import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int size = Integer.parseInt(br.readLine());
        int[][] arr = new int[size][3];

        for(int i = 0; i < size; ++i)
        {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            arr[i][2] = Integer.parseInt(st.nextToken());
        }

        int[][] DP_min = new int[size][3];
        DP_min[0][0] = arr[0][0];
        DP_min[0][1] = arr[0][1];
        DP_min[0][2] = arr[0][2];
        int[][] DP_max = new int[size][3];
        DP_max[0][0] = arr[0][0];
        DP_max[0][1] = arr[0][1];
        DP_max[0][2] = arr[0][2];

        for(int i = 1; i < size; ++i)
        {
            DP_min[i][0] = arr[i][0] + Math.min(DP_min[i-1][0], DP_min[i-1][1]);
            DP_min[i][1] = arr[i][1] + Math.min(DP_min[i-1][0], Math.min(DP_min[i-1][2], DP_min[i-1][1]));
            DP_min[i][2] = arr[i][2] + Math.min(DP_min[i-1][2], DP_min[i-1][1]);

            DP_max[i][0] = arr[i][0] + Math.max(DP_max[i-1][0], DP_max[i-1][1]);
            DP_max[i][1] = arr[i][1] + Math.max(DP_max[i-1][0], Math.max(DP_max[i-1][2], DP_max[i-1][1]));
            DP_max[i][2] = arr[i][2] + Math.max(DP_max[i-1][2], DP_max[i-1][1]);
        }

        System.out.println(Integer.toString(Math.max(DP_max[size-1][0], Math.max(DP_max[size-1][2], DP_max[size-1][1])))+' '
                        +Integer.toString(Math.min(DP_min[size-1][0], Math.min(DP_min[size-1][2], DP_min[size-1][1]))));
    }
}
