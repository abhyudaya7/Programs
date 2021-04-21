def Sum(n):
    if n==0:
        return 0
    return n+Sum(n-1)

def main():
    n = int(input())
    print(Sum(n))

if __name__ == "__main__":
    main()