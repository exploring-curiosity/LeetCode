class Solution {
public:
    bool isPalin(string str)
    {
        int length = str.length();
        int len=(length%2==0)?length/2:(length-1)/2;
        for(int i=0;i < len ;i++)
        {
            if(str[i] != str[length-i-1]){
                return false;
            }
        }
        return true;
    }
    int superpalindromesInRange(string left, string right) {
        int count =0;
        unsigned long long spal;
        string pal;
        vector<int> array;
        long long a=stol(left);
        long long b=stol(right);
        int l=(int)sqrt(a);
        int r=(int)sqrt(b);
        int min=int(log10(l)+1);
        int max=int(log10(r)+1);
        int j,k,threshold,m,n;
        for(int i=min;i<=max;i++)
        {
            threshold = (i%2==0)?i/2:(i-1)/2;
            m=int(pow(10,threshold-1));
            n=pow(10,threshold)-1;
            for(j=m;j<=n;j++)
            {
                if(i%2==0)
                {
                    pal=to_string(j);
                    pal+=string(pal.rbegin(),pal.rend());
                    spal=stol(pal);
                    spal*=spal;
                    
                    if(spal>=a&&spal<=b)
                    {
                        // cout<<spal<<endl;
                        if(isPalin(to_string(spal)))
                        {
                            // cout<<spal<<" ";
                            count+=1;
                        }
                    }
                }
                else
                {
                    for(k=0;k<10;k++)
                    {
                        if(i!=1)
                        {
                            pal=to_string(j);
                            pal+=to_string(k)+string(pal.rbegin(),pal.rend());
                            spal=stol(pal);
                            spal*=spal;
                            
                            if(spal>=a&&spal<=b)
                            {
                                // cout<<spal<<endl;
                                if(isPalin(to_string(spal)))
                                {
                                    // cout<<spal<<" ";
                                    count+=1;
                                }
                            }
                        }
                        else
                        {
                            pal=to_string(k);
                            spal=stol(pal);
                            spal*=spal;
                            
                            if(spal>=a&&spal<=b)
                            {
                                // cout<<spal<<endl;
                                if(isPalin(to_string(spal)))
                                {
                                    // cout<<spal<<" ";
                                    count+=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};