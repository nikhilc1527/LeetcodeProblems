class Solution:
    def longestValidParentheses(self, s):
        if len(s) < 2:
            return 0
        stack = 0
        res = 0
        j = -1
        for i in range(len(s)):
            if (s[i] == '('):
                stack += 1
            if (s[i] == ')'):
                stack -= 1
            if (stack == 0):
                res = max(res, i - j)
            if (stack < 0):
                stack = 0
                j = i
            
        j = len(s)
        stack = 0
        for i in range(len(s) - 1, -1, -1):
            if (s[i] == ')'):
                stack += 1
            if (s[i] == '('):
                stack -= 1
            if (stack == 0):
                res = max(res, j - i)
            if (stack < 0):
                stack = 0
                j = i
        return res

a = Solution
print(a.longestValidParentheses(a, ")()())")) # 4
print(a.longestValidParentheses(a, "()")) # 2
print(a.longestValidParentheses(a, "(()")) # 2
print(a.longestValidParentheses(a, "()()()))()(((((())))()()))()()(()()())()(()()()())()))")) # 44
print(a.longestValidParentheses(a, "")) # 0
print(a.longestValidParentheses(a, "(")) # 0
print(a.longestValidParentheses(a, ")(")) # 0
print(a.longestValidParentheses(a, "(((")) # 0
print(a.longestValidParentheses(a, ")))")) # 0

