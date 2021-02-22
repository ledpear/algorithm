import java.util.Stack;

public class codingTest{
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isValid("()")?"true":"false");
        System.out.println(solution.isValid("()[]{}")?"true":"false");
        System.out.println(solution.isValid("(]")?"true":"false");
        System.out.println(solution.isValid("([)]")?"true":"false");
        System.out.println(solution.isValid("{[]}")?"true":"false");
    }
}

class Solution {
    public boolean isValid(String s) {
        boolean bResult = true;
        Stack<Character> stack = new Stack<>();

        for(int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '['){
                stack.push(s.charAt(i));
            }
            else
            {
                if(s.charAt(i) == ')'){
                    if(!stack.empty() && stack.peek() == '('){
                        stack.pop();
                    }
                    else{
                        bResult = false;
                        break;
                    }
                }
                else if(s.charAt(i) == '}'){
                    if(!stack.empty() && stack.peek() == '{'){
                        stack.pop();
                    }
                    else{
                        bResult = false;
                        break;
                    }
                }
                else if(s.charAt(i) == ']'){
                    if(!stack.empty() && stack.peek() == '['){
                        stack.pop();
                    }
                    else{
                        bResult = false;
                        break;
                    }
                }
            }
        }
        
        if(!stack.empty()){
            bResult = false;
        }

        return bResult;
    }
}