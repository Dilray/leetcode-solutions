string longestCommonPrefix(vector<string>& strs) {
    string res = strs[0];

    for (uint16_t ch = 0; ch < strs.size(); ch++) {

        string sub = "";

        for (uint16_t chs = 0; chs < strs[ch].length(); chs++)
            if (strs[ch][chs] == res[chs])
                sub += strs[ch][chs];
            else
                break;

        if (sub == "") return sub;

        res = sub;
    }

    return res;
}