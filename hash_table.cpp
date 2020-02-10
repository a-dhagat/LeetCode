#include<iostream>

/*
Operations:
    Insert(S,x)
    Delete(S,x)
    Search(S,x)

Direct Access Table:
    Keys are drawn from a small distribution u={0,1,....,m-1}
    Assume keys are distinct
    Set up array T[0,...,m-1] to represent dynamic set S
    such that T[k]= x if x belongs to set S and key[x]=k
                    nil, otherwise
    Operations take constant time
    If set is drawn over a 64 bit number, then u={0,...,2^64}

Hashing:
    Hash function h maps keys "randomly" into slots of table T.
    When a record to be inserted maps to an already occupied slot,
    a Collission occurs.
    Resolving collision by chaining--
        Link records in same slot into a list
    Analysis:
        Worst Case:
            All keys in S hashes to the same slot-In that case, we have 
            a long linked-list -- Thus it takes O(n) to access if |S| = n.
        Average Case
            Assumption of simple uniform hashing:
            Each k belongs to S is equally likely to be hashed in any slot T
            independent of where other keys are hashed.
    
    Define: Load Factor of a Hash Table with n keys and m slots is
            alpha = n/m = average num of keys per slot
            Expected unsuccesful search time = Order(1->hash and access slot + alpha->cost of searching list)
            Expected search time = Order(1) if alpha=O(1), if n=O(m)
    Choosing a Hash function:
    Divsion Method:
        h(k) = k mod m; m is num slots in table
        Don't pick m with a small divisor
        Generally pick a prime, but not close to 2^x or 10^y.
    Multiplication Method:
        m = 2^r. Computer has w-bit words.
        h(k) = (A.k mod 2^w)bitwise_right_shift(w-r)

    Resolving collisions by open addressing
        Probe table systematically until an empty slot found
        h u{0,1,....m-1}
        Probe seq should be permutation
        Table may fill up. => n(num of elems in table) <= m (num slots)
        Deletion is difficult.
*/