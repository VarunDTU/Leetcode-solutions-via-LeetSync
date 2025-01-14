class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=0,e=arr.size()-1,mid;

        while(st<=e){
            mid=st+(e-st)/2;
           
            if(mid==0||arr[mid]>arr[mid-1]){
                if(mid==arr.size()-1||arr[mid]>arr[mid+1])return mid;
                else st=mid+1;
            }
            else  e=mid-1;
        }
        return mid;
    }
};