import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String input = br.readLine(), output = "";
        String[] strSplit = input.split("-");

        for(String item : strSplit){
            output += item.charAt(0);
        }

        System.out.println(output);
    }
}