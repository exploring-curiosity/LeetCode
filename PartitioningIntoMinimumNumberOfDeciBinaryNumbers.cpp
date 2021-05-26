class Solution {
public:
    int minPartitions(string n) {
        char max='1';
        for(int i=0;i<n.size();i++)
        {
            if(max<n[i])
                max=n[i];
        }
        return max-'0';
    }
};