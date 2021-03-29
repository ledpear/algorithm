import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String input = br.readLine(), output = "";

        StringTokenizer strToken = new StringTokenizer(input, "-");
        
        while(strToken.hasMoreTokens() == true){
            String token = strToken.nextToken();
            output += token.charAt(0);
        }

        System.out.println(output);
    }
}