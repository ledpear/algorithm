import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        Solution solution = new Solution();
    }
}

class Solution {
    public static final int RANKING_SIZE = 6;
    public static final int LOTTO_NUMBER_SIZE = 45;
    public static final int ZERO = 0;

    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];

        boolean[] myLottoNumber = new boolean[LOTTO_NUMBER_SIZE + 1];
        int zeroCount = ZERO;
        int maxCount = ZERO;

        //자신의 번호 등록
        for(int lottoNumber : lottos)
        {
            if(lottoNumber == ZERO)
            {
                ++zeroCount;
            }
            else
            {
                myLottoNumber[lottoNumber] = true;
            }
        }

        int sameCount = ZERO;
        for(int winNumber : win_nums)
        {
            if(myLottoNumber[winNumber])
            {
                ++sameCount;
            }
        }

        //순위 계산
        maxCount = sameCount + zeroCount;

        //최고 순위
        answer[0] = getRanking(maxCount);
        answer[1] = getRanking(sameCount);

        return answer;
    }

    int getRanking(int count)
    {
        int result = ZERO;

        if(count <= 1) //최하위
        {
            result = RANKING_SIZE;
        }
        else
        {
            result = RANKING_SIZE - count + 1;
        }
        return result;
    }
}