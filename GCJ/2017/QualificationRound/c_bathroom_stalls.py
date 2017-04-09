import math

def main():
    fname = 'C-large.in'
    fname_out = 'C-large.out'
    fout = open(fname_out, 'wt')
    with open(fname) as fin:
        T = int(fin.readline().strip())
        for t in range(1, T+1):
            N, K = map(int, fin.readline().strip().split(' '))
            if N == 1:
                type_stalls = [0, 0]
                num_stalls = [0, 0]
            elif N%2 == 0:
                type_stalls = [int(N/2), int(N/2)-1]
                num_stalls = [1, 1]
            else:
                type_stalls = [int((N-1)/2), int((N-1)/2)-1]
                num_stalls = [2, 0]
            K -= 1
            idx = 1
            while K > num_stalls[0] + num_stalls[1]:
                print("N(%d) == %dx%d+%dx%d + K(%d)" % (N, type_stalls[0], num_stalls[0], type_stalls[1], num_stalls[1], idx))
                assert(N == type_stalls[0]*num_stalls[0] + type_stalls[1]*num_stalls[1] + idx)
                K -= (num_stalls[0] + num_stalls[1])
                idx += (num_stalls[0] + num_stalls[1])
                prev_stalls = type_stalls
                prev_num = num_stalls
                if prev_stalls[0]%2 == 0:
                    type_stalls = [int(prev_stalls[0]/2), int(prev_stalls[0]/2)-1]
                    num_stalls = [prev_num[0], prev_num[0]]
                else:
                    type_stalls = [int((prev_stalls[0]-1)/2), int((prev_stalls[0]-1)/2)-1]
                    num_stalls = [prev_num[0]*2, 0]

                if prev_stalls[1]%2 == 0:
                    num_stalls[0] += prev_num[1]
                    num_stalls[1] += prev_num[1]
                else:
                    num_stalls[1] += 2*prev_num[1]

            print(type_stalls, num_stalls, K)
            if K == 0:
                max_d = type_stalls[0]
                min_d = type_stalls[0] if num_stalls[1] == 0 else type_stalls[1]
            elif K <= num_stalls[0]:
                max_d = math.ceil((type_stalls[0]-1)/2)
                min_d = int((type_stalls[0]-1)/2)
            else:
                max_d = math.ceil((type_stalls[1]-1)/2)
                min_d = int((type_stalls[1]-1)/2)
            print("Case #%d: %d %d" % (t, max_d, min_d))
            fout.write("Case #%d: %d %d\n" % (t, max_d, min_d))

if __name__ == '__main__':
    main()
