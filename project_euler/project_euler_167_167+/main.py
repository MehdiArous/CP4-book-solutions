# the idea was inspired with the help of this paper :
# 0n the Regularity of Certain 1 -Additive Sequences STEVEN R. FINCH 

periods = {2: 32, 3: 26, 4: 444, 5: 1628, 6: 5906, 7: 80, 8: 126960, 9: 380882, 10: 2097152}
fund_diff = {2: 126, 3: 126, 4: 1778, 5: 6510, 6: 23622, 7: 510, 8: 507842, 9: 1523526, 10: 8388606}

def solve(n, k):
    
    period = periods[n]
    l = [2, 2*n+1, 2*n+3]

    while (l[-1]+2 < l[1] + l[2]):
        l.append(l[-1]+2)
    l.append(l[1] + l[2])
    l.append(l[-2] + 2)
    
    if (k >= 1 and k <= len(l)): return l[k-1] 
    
    if (k <= period+2):
        pointer = 1
        pair_num = l[-2]
        pos_pair_num = len(l)-2
        while (len(l) < period+2):
            if (l[-1] + 2 < l[pointer] + pair_num):
                 l.append(l[-1] + 2)
            else :
                if (l[-1] + 2 > l[pointer] + pair_num):
                    #print('ssss', n)
                    l.append(l[pointer] + pair_num)
                    pointer += 1
                else : 
                    pointer += 1 
                    l.append(l[pointer] + pair_num)
                    if pointer == pos_pair_num-1 :  pointer += 2 
                    else : pointer += 1
            if (len(l) == k): return l[-1]
    
    portion = ((k-(period+2)) // period)
    portion += 1
    pos_in_portion = ((k-(period+2)) % period)
    
    cumul_diff = [0,0]
    for i in range(1,len(l)-2):
        cumul_diff.append(2*i)
    
    if (pos_in_portion >= 1 and pos_in_portion <= len(l)-2):
        return (2*n+1 + (portion*fund_diff[n]) + cumul_diff[pos_in_portion])
    
    ref = len(l) - 2
    pointer = 1
    pair_num = l[-2]
    pos_pair_num = len(l)-2
    debug = []
    while (len(l) < period+2):
        if (l[-1] + 2 < l[pointer] + pair_num):
            l.append(l[-1] + 2)
            cumul_diff.append(cumul_diff[-1] + 2)
        else :
            if (l[-1] + 2 > l[pointer] + pair_num):
                '''print (n, l[pointer], pair_num, l[-1])
                print(l)
                return ''' # debug 
                debug.append((n, l[pointer], pair_num, l[-1]))
                cumul_diff.append(cumul_diff[-1] + l[pointer] + pair_num - l[-1])
                l.append(l[pointer] + pair_num)
                pointer += 1
            else : 
                pointer += 1 
                if pointer == pos_pair_num :
                    pointer += 1
                cumul_diff.append(cumul_diff[-1] + l[pointer] + pair_num - l[-1])
                l.append(l[pointer] + pair_num)
                if pointer == pos_pair_num-1 :  pointer += 2 
                else : pointer += 1
        if pos_in_portion != 0:
            ref += 1 
            if (ref == pos_in_portion): return (2*n+1 + (portion*fund_diff[n]) + cumul_diff[ref])
    return (2*n+1 + ((portion-1)*fund_diff[n]) + cumul_diff[-1])
    
'''n, k = input().split()
print(solve(int(n), int(k)))'''

res = 0
for n in range(2, 11):
    res += solve(n, 10**11)
print(res)

print(solve(9, 10**11))