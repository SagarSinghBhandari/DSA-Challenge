 int findPages(int a[], int n, int m) 
    {
        //code here
        if(m>n)
        return -1;
        
        int start=0, end=0, mid, ans;
        
        for(int i=0; i<n; i++ ){
            start=max(start, a[i]);
            end += a[i];
        }
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            int pages=0, count=1;
            
            for(int i=0; i<n; i++)
            {
                pages += a[i];
                if(pages>mid)
                {
                    count++;
                    pages=a[i];
                }
            }
            if(count <= m){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;    
    }