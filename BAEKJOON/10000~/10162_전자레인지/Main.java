import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        int input = Integer.parseInt(br.readLine());

        int Button_A = 0, Button_B = 0, Button_C = 0;

        if(input % 10 != 0){
            System.out.println("-1");
        }
        else{
            while(input >= 300)
            {
                Button_A += 1;
                input -= 300;
            }
    
            while(input >= 60)
            {
                Button_B += 1;
                input -= 60;
            }
    
            while(input >= 10)
            {
                Button_C += 1;
                input -= 10;
            }

            if(input == 0){
                System.out.println(Integer.toString(Button_A) + ' ' + Integer.toString(Button_B) + ' ' + Integer.toString(Button_C));
            }
            else{
                System.out.println("-1");
            }
        }
    }
}