void pick(int n, vector<int> &picked, int remain) {
    if (remain == 0)
        return;
    int mini = picked.empty() ? 0 : picked.back() + 1;
    for (int i = mini; i < n; i++) {
        picked.push_back(i);
        pick(n, picked, remain-1);
        picked.pop_back();
    }
}
