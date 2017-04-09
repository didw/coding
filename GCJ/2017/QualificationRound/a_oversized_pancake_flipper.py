def main():
	fname = 'A-large.in'
	fname_out = 'A-large.out'
	fout = open(fname_out, 'wt')
	with open(fname) as fin:
		T = int(fin.readline().strip())
		for t in range(1, T+1):
			cakes, k = fin.readline().strip().split(' ')
			cakes = list(cakes)
			k = int(k)
			res = 0
			for i in range(len(cakes)-k+1):
				#print(cakes)
				if cakes[i] == '-':
					res += 1
					for j in range(i, i+k):
						cakes[j] = '+' if cakes[j] == '-' else '-'
			#print(cakes, res)
			if '-' in cakes:
				res = "IMPOSSIBLE"
			#print("Case #%d: %s" % (t, str(res)))
			fout.write("Case #%d: %s\n" % (t, str(res)))

if __name__ == '__main__':
	main()
