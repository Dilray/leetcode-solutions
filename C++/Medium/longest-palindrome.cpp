std::string longestPalindrome(std::string s) {
    std::string res = "";

    for (int i = 0; i < s.length(); i++) {

        // �������� ��� �������� ����� ����������
        int l = i, r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            if (r - l + 1 > res.length()) {
                res = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }

        // �������� ��� ������ ����� ����������
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            if (r - l + 1 > res.length()) {
                res = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
    }

    return res;
}