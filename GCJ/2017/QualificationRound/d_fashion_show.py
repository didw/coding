def main():
    fname = 'C-large.in'
    fname_out = 'C-large.out'
    fout = open(fname_out, 'wt')
    with open(fname) as fin:
        T = int(fin.readline().strip())
        for t in range(1, T+1):


if __name__ == '__main__':
    main()
