class Solution {
public:

    void merge(vector<int> &arr, int left, int mid,int right){
        int i = left;
        int j = mid+1;
        vector<int> temp;

        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }

        }

        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }

        while( j <= right){
            temp.push_back(arr[j]);
            j++;
        }

        for(int k = left; k <= right; k++){
            arr[k] = temp[k - left];
        }
    }

    void mergeSort(vector<int> &arr, int left, int right){
        if(left >= right){
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);

    }


    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() -1;

        mergeSort(nums,left,right);

        return nums.at(nums.size() - k);
    }
};