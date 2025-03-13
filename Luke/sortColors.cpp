
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1) return;
        static constexpr int RED = 0;
        static constexpr int GREEN = 1;
        static constexpr int BLUE = 2;

        auto sortColorsToBound = [&](int lower_bound, int colorCode) -> int{
            int colorIndex = lower_bound;
            for(int i = colorIndex; i < nums.size(); i++) {
                auto color = nums[i];
                if(color == colorCode) {
                    std::swap(nums[i], nums[colorIndex]);
                    colorIndex++;
                }
            }
            return colorIndex;
        };

        auto redLower = sortColorsToBound(0, RED);
        auto greenlower = sortColorsToBound(redLower, GREEN);

    }

