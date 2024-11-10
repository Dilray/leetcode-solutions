int reverse(int x) {
	int xx = abs(x);
	int deg = 1;
	long long res = 0;
	while (xx > 0)
	{
		res = res * 10 + (xx % 10);
		xx /= 10;
	}
	if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
		return 0;
	return res * (x > 0 ? 1 : -1);
}