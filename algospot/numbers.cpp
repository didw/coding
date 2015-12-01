// 에라토스테네스의 체
int n;
bool isPrime[MAX_N + 1];
void eratosthenes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    int sqrtn = int(sqrt(n));
    for (int i = 2; i < sqrtn; ++i) {
        if (isPrime[i])
            for (int j = i*i; j < sqrtn; j+=i)
                isPrime[j] = true;
    }
}

// 에라토스테네스의 체를 이용한 빠른 소인수 분해
int minFactor[MAX_N];
void eratosthenes2() {
    minFactor[0] = minFactor[1] = -1;
    for (int i = 0; i <= n; ++i)
        minFactor[i] = i;
    int sqrtn = int(sqrt(n));
    for (int i = 0; i < sqrtn; ++i)
        if (minFactor[i] == i)
            for (int j = i*i; j < sqrtn; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;
}

// 2이상의 자연수 n을 소인수분해한 결과를 리턴
vector<int> factor(int n) {
    vector<int> res;
    while (n > 1) {
        res.push_back(minFactor[n]);
        n /= minFactor[n];
    }
    return res;
}
