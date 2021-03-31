import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();

        Solution solution = new Solution();
        System.out.println(Integer.toString(solution.solution(input)));
    }
}

class Solution
{
    int solution(String input)
    {
        int result = 0;

        //분해했을때 한개면 내부에 있는 괄호 처리
        //여러개면 각각 재귀로 전달
        List<String> parenthesisArray = ParenthesisDecomposition(input);

        //정상적이지 않은 괄호면 0반환
        int size = parenthesisArray.size();

        if(size == 1)
        {
            String parenthesisa = parenthesisArray.get(0);

            if(parenthesisa.equals("-1"))
            {
                return 0;
            }

            int length = parenthesisa.length();
            String inner = parenthesisa.substring(1, length - 1);

            if(parenthesisa.charAt(0) == '(')
            {
                if(inner.length() == 0)
                {
                    return 2;
                }
                else
                {
                    result = 2 * solution(inner);
                }
            }
            else if(parenthesisa.charAt(0) == '[')
            {
                if(inner.length() == 0)
                {
                    return 3;
                }
                else
                {
                    result = 3 * solution(inner);
                }
            }
        }
        else
        {
            for(String parenthesisa : parenthesisArray)
            {
                result += solution(parenthesisa);
            }
        }

        return result;
    }

    List<String> ParenthesisDecomposition(String parenthesis)
    {
        List<String> result = new ArrayList<>();
        Stack<Character> stack = new Stack<Character>();
        String temp = "";

        //정상적인 괄호가 안미면 list를 비워서 반환
        for(char c : parenthesis.toCharArray())
        {
            if(c == '(' || c == '[')
            {
                stack.push(c);
            }
            else if(c == ')')
            {
                if(stack.empty() || stack.peek() != '(')
                {
                    result.clear();
                    result.add("-1");
                    return result;
                }

                stack.pop();
            }
            else if(c == ']')
            {
                if(stack.empty() || stack.peek() != '[')
                {
                    result.clear();
                    result.add("-1");
                    return result;
                }
                stack.pop();
            }

            temp += c;
            if(stack.empty())
            {
                result.add(temp);
                temp = "";
            }
        }

        if(!stack.empty())
        {
            result.clear();
            result.add("-1");
        }

        return result;
    }
}