class Solution {
public:
    static bool cmp(pair<int,double>& a,pair<int,double>& b)
    {
        if(a.second == b.second)
            return a.first <= b.first;
        return a.second <= b.second;
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double ans = DBL_MAX;
        vector<pair<int,double>> temp;
        for(int i=0;i<quality.size();i++)
            temp.push_back(make_pair(quality[i],(double)wage[i]/quality[i]));
        sort(temp.begin(),temp.end(),cmp);
        priority_queue<int> q;
        double sum=0;
        for(auto& it:temp)
        {
            q.push((int)it.first);
            sum+=it.first;
            if(q.size() > K)
            {
                sum-=q.top();
                q.pop();
            }
            if(q.size() == K)
                ans = fmin(ans,sum*it.second);
        }
        return ans;
    }
};