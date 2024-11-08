int removeDuplicates(vector<int>& nums) {
	unordered_map<int, bool> hashTable;
	for (uint16_t num = 0; num < nums.size(); ++num)
		hashTable[nums[num]] = true;
	nums.clear();
	uint16_t sz = hashTable.size();
	for (const auto& pair : hashTable)
		//nums.push_back(pair.first);
		nums.insert(nums.begin(), pair.first);

	return sz;
}