 
vector<long long> lps_array_of_kmp_algo(string s)
{
    long long n=s.size();
    vector<long long> array(n);
    array[0]=0;
    long long j=0;
    for(int i=1;i<n;i++)
    {
        while((j>0)&&(s[i]!=s[j]))
        {
            j=array[j-1];
        }
        if(s[i]==s[j])j++;
        array[i]=j;
    }
    return array;
}
 