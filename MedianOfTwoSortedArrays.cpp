/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int firstElem = (nums1.size() + nums2.size() + 1) >> 1;
        int secondElem = (nums1.size() + nums2.size() + 2) >> 1;
        return (getKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), firstElem) + getKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), secondElem)) / 2;
    }
    double getKth(vector<int>& nums1, int st1, int sz1, vector<int>& nums2, int st2, int sz2, int k){
        if(sz1 > sz2) {
            return getKth(nums2, st2, sz2, nums1, st1, sz1, k);
        }
        if(sz1 == 0){
            return nums2[st2 + k - 1];
        }
        if(k == 1){
            return min(nums1[st1], nums2[st2]);
        }
        int i = min(k/2, sz1), j = min(k/2, sz2);
        if(nums1[st1 + i - 1] <= nums2[st2 + j - 1]){
            return getKth(nums1, st1 + i, sz1 - i, nums2, st2, sz2, k - i);
        }
        else {
            return getKth(nums1, st1, sz1, nums2, st2 + j, sz2 - j, k - j);
        }
        return 0;
    }
};
