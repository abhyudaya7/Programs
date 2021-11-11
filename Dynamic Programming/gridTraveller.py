# brute force recursive approach to find the solution
def gridTraveller(m,n) :
    if n == 1 and m == 1:
        return 1
    if n == 0 or m == 0:
        return 0
    return gridTraveller(m - 1,n) + gridTraveller(m, n - 1)

# memoised approach to find the optimal solution
def gridTravellermem(m,n,d = {}) :
    key = str(m) + ',' + str(n)
    if (key in d) :
        return d[key]
    if (n==1 or m==1) :
        return 1
    if (n==0 or m==0) :
        return 0
    d[key] = gridTravellermem(m-1,n,d) + gridTravellermem(m,n-1,d)
    return d[key]

if __name__ == "__main__" :
    m = int(input())
    n = int(input())
    print(gridTravellermem(m,n))