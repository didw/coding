def solve():
	s = set()
	N = int(raw_input())
	if N == 0:
		return "INSOMNIA"
	else:
		for i in xrange(1, 1000):
			for j in str(i*N):
				s.add(j)
			if len(s)==10:
				return i*N

def main():
	T = int(raw_input())
	for i in xrange(1, T+1):
		print "Case #{}: {}".format(i, solve())

if __name__ == "__main__":
	main()
