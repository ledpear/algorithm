import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int totalCount = Integer.parseInt(st.nextToken());
        int avg = Integer.parseInt(st.nextToken());
 
        System.out.println(totalCount * (avg - 1) + 1);
        Solution solution = new Solution();
    }
}

class Solution {
    
}