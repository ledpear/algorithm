
import java.util.Scanner;
public class Main {

    public static void main(String[] args){
        Main test = new Main();
    }

    public Main(){
        Scanner sc = new Scanner(System.in);
        //입력
        int len = sc.nextInt();
        int datas[] = new int[len];
        for (int i = 0 ; i < len ; i++){
            datas[i] = sc.nextInt();
        }

        //로직
        int result = solution(datas);

        //출력
        System.out.println(result);
    }

    public int solution(int[] datas){
        //소수의 갯수
        int result = 0 ;

        //데이터 원소마다 접근
        for (int data : datas){
            //1은 소수가 아니므로 pass
            if( data ==1){
                continue;
            }

            boolean isDecimal = true;

            //2부터 해당값의 제곱근까지만 반복문 시행
            for (int i = 2 ; i* i <= data ; i++ ){
                //약수라면
                if( data % i == 0 ){
                    isDecimal = false;
                    break;
                }
            }

            if(isDecimal){
                result+=1;
            }

        }
        return result;
    }
}