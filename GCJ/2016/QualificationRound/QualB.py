#https://code.google.com/codejam/contest/6254486/dashboard#s=p1

def solve():
	S = str(raw_input())
	res = 0
	for i in xrange(1,len(S)):
		if S[i] != S[i-1]:
			res += 1
	if S[len(S)-1] == '-':
		res += 1
	return res

def main():
	T = int(raw_input())
	for i in xrange(1,T+1):
		print "Case #{}: {}".format(i, solve())

if __name__=="__main__":
	main()
