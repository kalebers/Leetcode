class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
        nums1.swap(nums2);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (std::max(maxX, maxY) + std::min(minX, minY)) / 2.0;
            } else {
                return std::max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // This should not be reached, and it's included to avoid compilation warnings.
    return 0.0;
}

int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    
    double result = findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;

    return 0;
    }
};
