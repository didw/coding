def solve(N, L, fees):
    min_fee = 1e9
    res = N
    for i in range(0, N-L):
        for j in range(i+L, N):
            if j-i < L:
                continue
            total_sum = 0
            for k in range(i, j):
                total_sum += fees[k]
            avg = total_sum/(j-i)
            if avg < min_fee:
                min_fee = avg
                res = j-i
    return min_fee


def main():
    with open('sample.in') as f:
        c = int(f.readline())
        for _ in range(c):
            N, L = [int(x) for x in f.readline().split()]
            fees = [int(x) for x in f.readline().split()]
            res = solve(N, L, fees)
            print(res)


if __name__ == '__main__':
    main()
