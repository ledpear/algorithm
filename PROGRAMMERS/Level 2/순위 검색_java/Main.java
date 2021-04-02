import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {

        String[] info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
        String[] query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
        Solution solution = new Solution();
        int[] test = solution.solution(info, query);
    }
}

class Solution {
    public int[] solution(String[] info, String[] query)
    {
        int infoSize = info.length;
        int querySize = query.length;
        int[] answer = new int[querySize];

        List<Info> infoData = new ArrayList<>();

        for(int index = 0; index < infoSize; ++index)
        {
            String[] tokens = info[index].split(" ");
            infoData.add(new Info(tokens[0], tokens[1], tokens[2], tokens[3], Integer.parseInt(tokens[4])));
        }

        int answerIndex = 0;
        for(String queryItem : query)
        {
            String[] tokenTemp = queryItem.split(" ");
            String[] tokens = {tokenTemp[0], tokenTemp[2], tokenTemp[4], tokenTemp[6], tokenTemp[7]};
            List<Info> infoList = new ArrayList<>(infoData);

            for(int index = 0; index < 5; ++index)
            {
                if(tokens[index].equals("-"))
                {
                    continue;
                }

                int listIndex = 0;
                while(listIndex < infoList.size())
                {
                    boolean pass = false;
                    switch (index)
                    {
                        case 0:
                            pass = infoList.get(listIndex).language.equals(tokens[index]);
                            break;
                        case 1:
                            pass = infoList.get(listIndex).occupation.equals(tokens[index]);
                            break;
                        case 2:
                            pass = infoList.get(listIndex).career.equals(tokens[index]);
                            break;
                        case 3:
                            pass = infoList.get(listIndex).soulfood.equals(tokens[index]);
                            break;
                        case 4:
                            int score = Integer.parseInt(tokens[index]);
                            pass = infoList.get(listIndex).score >= score;
                            break;
                        default:
                            break;
                    }

                    if(!pass)
                    {
                        infoList.remove(listIndex);
                    }
                    else
                    {
                        ++listIndex;
                    }
                }
            }

            answer[answerIndex++] = infoList.size();
        }

        return answer;
    }

    static public class Info
    {
        String language;
        String occupation;
        String career;
        String soulfood;
        int score;

        public Info(String language, String occupation, String career, String soulfood, int score)
        {
            this.language = language;
            this.occupation = occupation;
            this.career = career;
            this.soulfood = soulfood;
            this.score = score;
        }
    }
}