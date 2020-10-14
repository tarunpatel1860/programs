class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
     
        priority_queue<pair<int,int>>  pq;
        
        int i=0;
        for(i=0;i<K;i++)
        {
            int a =points[i][0],b=points[i][1];
            pq.push({(a*a)+(b*b),i});
        }
        
        while(i<points.size())
        {
             int a =points[i][0],b=points[i][1];
            int temp = (a*a)+ (b*b);
            
            if(temp<pq.top().first)
            {
                pq.pop();
                pq.push({temp,i});
            }
            i++;
        }
        
        vector<vector<int>> v;
        
        while(!pq.empty())
        {
            v.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return v;
    }
};
