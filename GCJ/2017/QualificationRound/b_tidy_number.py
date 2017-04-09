def isTidy(N):
    for i in range(len(N)-1):
        if N[i] > N[i+1]:
            return False
    return True

def main():
    fname = 'B-large.in'
    fname_out = 'B-large.out'
    fout = open(fname_out, 'wt')
    with open(fname) as fin:
        T = int(fin.readline().strip())
        for t in range(1, T+1):
            N = list(fin.readline().strip())
            while not isTidy(N):
                if isTidy(N):
                    print("%s is tidy" % ''.join(N))
                else:
                    print("%s is not tidy" % ''.join(N))
                for i in range(len(N)-1):
                    
                    if int(N[i]) > int(N[i+1]):
                        N[i] = '9' if N[i] == '0' else str(int(N[i])-1)
                        for j in range(i+1, len(N)):
                            N[j] = '9'
            if isTidy(N):
                print("%s is tidy" % ''.join(N))
            else:
                print("%s is not tidy" % ''.join(N))
            fout.write("Case #%d: %d\n" % (t, int(''.join(N))))


if __name__ == '__main__':
    main()
