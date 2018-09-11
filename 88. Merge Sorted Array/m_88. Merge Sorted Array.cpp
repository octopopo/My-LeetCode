class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nL = nums1.size()-1;
        n--;
        m--;
        while(n >= 0)
        {
            if(m >= 0)
            {
                if(nums1[m] > nums2[n])
                {
                    nums1[nL] = nums1[m];
                    m--;
                }
                else
                {
                    nums1[nL] = nums2[n];
                    n--;
                }
            }
            else
            {
                nums1[nL] = nums2[n];
                n--;
            }
            nL--;
        }
        
        return;
    }
};