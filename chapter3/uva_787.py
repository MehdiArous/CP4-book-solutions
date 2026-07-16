from functools import reduce
from itertools import groupby
import math
import operator
import sys

# sys.stdin = open('in.txt', 'r')
raw_input = sys.stdin.read()
all_numbers = list(map(int, raw_input.split()))

def solve_subarray(v):
    """Returns the maximum product of a non-empty subarray with no zeros."""
    if len(v) == 1:
        return v[0]
        
    neg_indices = [idx for idx, val in enumerate(v) if val < 0]
    
    if len(neg_indices) % 2 == 0:
        return reduce(operator.mul, v)
        
    left_prefix = v[:neg_indices[-1]]
    right_suffix = v[neg_indices[0] + 1:]
    
    candidates = []
    if left_prefix:
        candidates.append(reduce(operator.mul, left_prefix))
    if right_suffix:
        candidates.append(reduce(operator.mul, right_suffix))
        
    return max(candidates) if candidates else -math.inf

def process_test_case(data):
    """Processes a single test case (data ending before -999999)."""
    if not data:
        return
        
    # Split on 0s
    subarrays = [list(group) for is_zero, group in groupby(data, lambda x: x == 0) if not is_zero]
    zero_exist = 0 in data
    
    ans = -math.inf
    for v in subarrays:
        ans = max(ans, solve_subarray(v))
        
    if zero_exist:
        ans = max(ans, 0)
        
    print(ans)

current_case = []
for num in all_numbers:
    if num == -999999:
        process_test_case(current_case)
        current_case = []  
    else:
        current_case.append(num)
