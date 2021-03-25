import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int size = Integer.parseInt(br.readLine()) ;
        int result = 1;

        for(int i = 0; i < size; ++i){
            int temp = Integer.parseInt(br.readLine());
            result = result + temp - 1;
        }
 
        System.out.println(result);
    }
}

class Solution {
    
}