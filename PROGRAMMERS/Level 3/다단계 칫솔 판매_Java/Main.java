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
    public static final int ZERO = 0;

    public static final int ROOT_NUMBER = -1;
    public static final String ROOT_STRING = "-";

    public static final int TOOTHBRUSH_PRICE = 100;
    public static final int REWARD_RATE = 10;

    //가진 돈과 이번에 얻는 돈의 구분을 확실히 해야한다
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        Map<String, Integer> MemberNumber = new HashMap<>();

        int enrollSize = enroll.length;
        int sellerSize = seller.length;

        int[] answer = new int[enrollSize];

        //이름을 입력하면 인덱스가 나오도록
        for(int index = ZERO; index < enrollSize; ++index)
        {
            MemberNumber.put(enroll[index], index);
        }

        //각자 추천인 등록
        Member[] members = new Member[enrollSize];
        for(int index = ZERO; index < enrollSize; ++index)
        {
            String referralName = referral[index];
            if(referralName.equals(ROOT_STRING))
            {
                members[index] = new Member(ROOT_NUMBER);
            }
            else
            {
                int referralNumber = MemberNumber.get(referralName);
                members[index] = new Member(referralNumber);
            }
        }

        //이익 배분
        for(int index = ZERO; index < sellerSize; ++index)
        {
            int sellerNumber = MemberNumber.get(seller[index]);
            int revenue = amount[index] * TOOTHBRUSH_PRICE;

            Calculate(sellerNumber, revenue, members, answer);
        }

        return answer;
    }

    static public class Member
    {
        int referralNuber = ROOT_NUMBER;
        int haveMoney = ZERO;

        public Member(int referralNuber)
        {
            this.referralNuber = referralNuber;
            haveMoney = ZERO;
        }
    }

    void Calculate(int sellerNumber, int revenue, Member[] members, int[] answer)
    {
        int reward = revenue / REWARD_RATE;
        revenue -= reward;

        members[sellerNumber].haveMoney += revenue;
        answer[sellerNumber] = members[sellerNumber].haveMoney;

        int referralNuber = members[sellerNumber].referralNuber;
        //자신이 루트가 아니라면 제귀
        if(referralNuber != ROOT_NUMBER)
        {
            Calculate(referralNuber, reward, members, answer);
        }
    }
}