// Time -> O(n), Space -> O(n)

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
function dailyTemperatures(temperatures) {
  const n = temperatures.length;
  const stk = [];
  const result = Array(n).fill(0);

  temperatures.map((val, i) => {
    while (stk.length && temperatures[stk[stk.length - 1]] < val) {
      const top = stk.pop();
      result[top] = i - top;
    }
    stk.push(i);
  });

  return result;
}
