import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int input = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < input; ++i){
            String output = "";
            //가장 위
            if(i == 0){
                for(int j = 0; j < input - 1; ++j){
                    output += ' ';
                }
                output += '*';
            }
            //가장 아래
            else if(i == input - 1){
                for(int j = 0; j < input * 2 - 1; ++j){
                    output += '*';
                }
            }
            //중간
            else{
                for(int j = 0; j < input - i - 1; ++j){
                    output += ' ';
                }
                output += '*';
                for(int j = 0; j < i * 2 - 1; ++j){
                    output += ' ';
                }
                output += '*';
            }

            System.out.println(output);
        }
    }
}