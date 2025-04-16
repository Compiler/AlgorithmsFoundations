
    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return {nums[left]};

        int mid = (right - left) / 2 + left;
        auto leftNums = mergeSort(nums, left, mid);
        auto rightNums = mergeSort(nums, mid+1, right);

        //merge
        std::vector<int> sorted;
        int leftPtr = 0; int rightPtr = 0;
        while(leftPtr < leftNums.size() && rightPtr < rightNums.size()) {
            auto leftNum = leftNums[leftPtr];
            auto rightNum = rightNums[rightPtr];
            if(leftNum < rightNum) {
                leftPtr++;
                sorted.push_back(leftNum);
            }else {
                rightPtr++;
                sorted.push_back(rightNum);
            }

        }

        while(leftPtr < leftNums.size()) sorted.push_back(leftNums[leftPtr++]);
        while(rightPtr < rightNums.size()) sorted.push_back(rightNums[rightPtr++]);
        return sorted;
    }

