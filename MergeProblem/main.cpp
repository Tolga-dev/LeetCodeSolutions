#include <iostream>
#include <vector>

// problem : https://leetcode.com/problems/merge-sorted-array/

void merge(std::vector<int>& nums1, int m,std::vector<int>& nums2, int n )
{
    m = nums1.size();
    std::vector<int> cache;
    int i =0, j = 0;
    for(; i < m-n && j<n;)
    {
        if(nums1[i] < nums2[j])
        {
            cache.emplace_back(nums1[i]);

            i++;
        }
        else
        {
            cache.emplace_back(nums2[j]);
            j++;
        }
    }
    while(j < n)
    {
        cache.emplace_back(nums2[j]);
        j++;
    }

    while(i < m-n)
    {
        cache.emplace_back(nums1[i]);
        i++;
    }

    for(int v = 0; v < m; v++)
        nums1[v] = cache[v];

    for(auto& k : nums1)
        std::cout << k << " ";
    std::cout << std::endl;

}


int main() {
    std::vector<int> l = {1,2,3};
    std::vector<int> m = {2,5,6};

    std::vector<int> n = {};

    n.resize(m.size() + l.size(),-1);

    for(int b=0; b < n.size()-m.size(); b++)
        n[b] = l[b];

   merge(n,n.size(),m,m.size());


    return 0;
}
