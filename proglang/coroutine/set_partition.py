# Set Partition
# 
# A set partition of the set [n] = {1,2,3,...,n} is a collection B0,
# B1, ... Bj of disjoint subsets of [n] whose union is [n]. Each Bj
# is called a block. Below we show the partitions of [4]. The periods
# separtate the individual sets so that, for example, 1.23.4 is the
# partition {{1},{2,3},{4}}.
#   1 block:  1234
#   2 blocks: 123.4   124.3   134.2   1.234   12.34   13.24   14.23
#   3 blocks: 1.2.34  1.24.3  14.2.3  13.2.4  12.3.4
#   4 blocks: 1.2.3.4
#
# Each partition above has its blocks listed in increasing order of
# smallest element; thus block 0 contains element 1, block1 contains
# the smallest element not in block 0, and so on. A Restricted Growth
# string (or RG string) is a sring a[1..n] where a[i] is the block in
# whcih element i occurs. Restricted Growth strings are often called
# restricted growth functions. Here are the RG strings corresponding
# to the partitions shown above.
#
#   1 block:  0000
#   2 blocks: 0001, 0010, 0100, 0111, 0011, 0101, 0110
#   3 blocks: 0122, 0121, 0112, 0120, 0102, 
# 
# ...more
#
# Reference:
# Frank Ruskey. Simple combinatorial Gray codes constructed by
# reversing sublists. Lecture Notes in Computer Science, #762,
# 201-208. Also downloadable from
# http://webhome.cs.uvic.ca/~ruskey/Publications/SimpleGray/SimpleGray.html

def stirling2nd(n, k):
    '''
    Stirling number of second kind. Note that this function is for
    testing purpose only and is slow because of reducdant calculation.
    '''
    if (k >= n or k <= 1): return 1
    return stirling2nd(n-1, k-1) + k * stirling2nd(n-1, k)

def set_partition(n, k):
    if k%2 == 0: 
        for x, y in GEN0_even( n, k ):
            yield x, y
    else: 
        for x, y in GEN0_odd( n, k):
            yield x, y
    assert stirling2nd(n, k) == cnt


def Move ( x, y ):
    yield x, y


# The lists S(n,k,0) and S(n,k,1) satisfy the following properties.
# 1. Successive RG sequences differ in exactly one position.
# 2. first(S(n,k,0)) = first(S(n,k,1)) = 0^{n-k}0123...(k-1)
# 3. last(S(n,k,0)) = 0^{n-k}12...(k-1)0
# 4. last(S(n,k,1)) = 012...(k-1)0^{n-k}
# Note that first(S'(n,k,p)) = last(S(n,k,p))

def GEN0_even ( n, k ):
    ''' S(n,k,0) even k '''
    if not (k > 0 and k < n): return
    for x, y in GEN0_odd(n-1, k-1):    # S(n-1, k-1, 0).(k-1)
        yield x, y
    for x, y in Move(n-1,k-1):
        yield x, y
    for x, y in GEN1_even(n-1, k):     # S(n-1, k, 1).(k-1)
        yield x, y
    for x, y in Move(n, k-2):
        yield x, y
    for x, y in NEG1_even(n-1, k):     # S'(n-1, k, 1).(k-2)  
        yield x, y
    for i in range(k-3, 0, -2):
        for x, y in Move(n, i):
            yield x, y
        for x, y in GEN1_even(n-1, k):   # S(n-1, k, 1).i
            yield x, y
        for x, y in Move(n, i-1):
            yield x, y
        for x, y in NEG1_even(n-1, k):   # S'(n-1, k, 1).(i-1)
            yield x, y


def NEG0_even ( n, k ):
    ''' S'(n,k,0) even k '''
    if not (k > 0 and k < n): return
    for i in range(1, k-2, 2):
        for x, y in GEN1_even(n-1, k):   # S(n-1, k, 1).(i-1)
            yield x, y
        for x, y in Move(n, i):      
            yield x, y
        for x, y in NEG1_even(n-1, k):   # S'(n-1, k, 1).i
            yield x, y
        for x, y in Move(n, i+1):
            yield x, y
    for x, y in GEN1_even(n-1, k):     # S(n-1, k, 1).(k-2)
        yield x, y
    for x, y in Move(n, k-1):
        yield x, y
    for x, y in NEG1_even(n-1, k):     # S(n-1, k, 1).(k-1)
        yield x, y
    for x, y in Move(n-1, 0):      
        yield x, y
    for x, y in NEG0_odd(n-1, k-1):    # S(n-1, k-1, 1).(k-1)
        yield x, y


def GEN1_even ( n, k ):
    ''' S(n,k,1) even k '''
    if not (k > 0 and k < n): return
    for x, y in GEN1_odd(n-1, k-1):
        yield x, y
    for x, y in Move(k, k-1):
        yield x, y
    for x, y in NEG1_even(n-1, k):
        yield x, y
    for x, y in Move(n, k-2):
        yield x, y
    for x, y in GEN1_even(n-1, k):
        yield x, y
    for i in range(k-3, 0, -2):
        for x, y in Move(n, i):
            yield x, y
        for x, y in NEG1_even(n-1, k):
            yield x, y
        for x, y in Move(n, i-1):
            yield x, y
        for x, y in GEN1_even(n-1, k):
            yield x, y


def NEG1_even ( n, k ):
    ''' S'(n,k,1) even k '''
    if not (k > 0 and k < n): return
    for i in range(1, k-2, 2):
        for x, y in NEG1_even(n-1, k): 
            yield x, y
        for x, y in Move(n, i):      
            yield x, y
        for x, y in GEN1_even(n-1, k): 
            yield x, y
        for x, y in Move(n, i+1):
            yield x, y
    for x, y in NEG1_even(n-1, k):     
        yield x, y
    for x, y in Move(n, k-1):
        yield x, y
    for x, y in GEN1_even(n-1, k):    
        yield x, y
    for x, y in Move(k, 0):      
        yield x, y
    for x, y in NEG1_odd(n-1, k-1):  
        yield x, y


def GEN0_odd ( n, k ):
    ''' S(n,k,0) odd k '''
    if not (k > 1 and k < n): return
    for x, y in GEN1_even(n-1, k-1): 
        yield x, y
    for x, y in Move(k,k-1):
        yield x, y
    for x, y in NEG1_odd(n-1, k): 
        yield x, y
    for i in range(k-2, 0, -2):
        for x, y in Move(n, i):
            yield x, y
        for x, y in GEN1_odd(n-1, k):
            yield x, y
        for x, y in Move(n, i-1):
            yield x, y
        for x, y in NEG1_odd(n-1, k): 
            yield x, y


def NEG0_odd ( n, k ):
    ''' S'(n,k,0) odd k '''
    if not (k > 1 and k < n): return
    for i in range(1, k-1, 2):
        for x, y in GEN1_odd(n-1, k): 
            yield x, y
        for x, y in Move(n, i):      
            yield x, y
        for x, y in NEG1_odd(n-1, k):  
            yield x, y
        for x, y in Move(n, i+1):
            yield x, y
    for x, y in GEN1_odd(n-1, k): 
        yield x, y
    for x, y in Move(k, 0):
        yield x, y
    for x, y in NEG1_even(n-1, k-1):
        yield x, y


def GEN1_odd ( n, k ):
    ''' S(n,k,1) odd k '''
    if not (k > 1 and k < n): return
    for x, y in GEN0_even(n-1, k-1):
        yield x, y
    for x, y in Move(n-1,k-1):
        yield x, y
    for x, y in GEN1_odd(n-1, k): 
        yield x, y
    for i in range(k-2, 0, -2):
        for x, y in Move(n, i):
            yield x, y
        for x, y in NEG1_odd(n-1, k):
            yield x, y
        for x, y in Move(n, i-1):
            yield x, y
        for x, y in GEN1_odd(n-1, k): 
            yield x, y


def NEG1_odd ( n, k ):
    ''' S'(n,k,1) odd k '''
    if not (k > 1 and k < n): return
    for i in range(1, k-1, 2):
        for x, y in NEG1_odd(n-1, k): 
            yield x, y
        for x, y in Move(n, i):      
            yield x, y
        for x, y in GEN1_odd(n-1, k):  
            yield x, y
        for x, y in Move(n, i+1):
            yield x, y
    for x, y in NEG1_odd(n-1, k): 
        yield x, y
    for x, y in Move(n-1, 0):
        yield x, y
    for x, y in NEG0_even(n-1, k-1):
        yield x, y


if __name__ == "__main__":
    n, k = 4, 2
    b = [0 for i in range(n-k+1)] + list(range(k))
    cnt = 1
    for x, y in set_partition(n,k):
        old = b[x]
        b[x] = y    
        cnt += 1
        print(b[1:], ": Move {} from block {} to {}".format(x, old, y))
    assert stirling2nd(n, k) == cnt
    print("Done.")
