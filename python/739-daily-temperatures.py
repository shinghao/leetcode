# Time -> O(n), Space -> O(n)

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        result = [0] * len(temperatures)

        for i, value in enumerate(temperatures):
            while (len(stack) and value > temperatures[stack[-1]]):
                top = stack.pop()
                result[top] = i - top
            stack.append(i)

        return result