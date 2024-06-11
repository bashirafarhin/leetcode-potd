class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int i=0,k=0;
        int n=arr1.size();
        int m=arr2.size();
        while(i<n && k<m){
            int j=i;
            while(j<n){
                if (arr1[j]==arr2[k]){
                    swap(arr1[i],arr1[j]);
                    i++;
                }
                j++;
            }
            k++;
        }
      
       cout<<i<<endl;

        for(int j=i;j<n;j++){
            int mini=j;
            for(int k=j;k<n;k++){
                if(arr1[k]<arr1[mini]){
                    mini=k;
                }
            }
            swap(arr1[j],arr1[mini]);
        }
        return arr1;

    }
};