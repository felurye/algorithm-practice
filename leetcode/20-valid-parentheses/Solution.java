
class Solution {

    private boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')')
                || (open == '[' && close == ']')
                || (open == '{' && close == '}');
    }

    public boolean isValid(String s) {
        if (s == null || s.length() % 2 != 0) {
            return false;
        }

        java.util.Deque<Character> stack = new java.util.ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char open = stack.pop();
                if (!isMatchingPair(open, c)) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}
