#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {

    // Binary search hamesha chhote array par karenge
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int left = 0;
    int right = m;

    while (left <= right) {

        // nums1 ka partition
        int cut1 = (left + right) / 2;

        // nums2 ka partition
        int cut2 = (m + n + 1) / 2 - cut1;

        // Left side ke maximum values
        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        // Right side ke minimum values
        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        // Correct partition mil gaya
        if (left1 <= right2 && left2 <= right1) {

            // Total elements odd
            if ((m + n) % 2 == 1) {
                return (double)(left1 > left2 ? left1 : left2);
            }

            // Total elements even
            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;

            return ((double)maxLeft + minRight) / 2.0;
        }

        // nums1 ka partition left/right adjust karo
        else if (left1 > right2) {
            right = cut1 - 1;
        }
        else {
            left = cut1 + 1;
        }
    }

    return 0.0;
}