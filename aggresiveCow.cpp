#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr,int N,int C,int minAllowedDist){
    int cows = 1,lastPossibleStall = arr[0];
    for(int i=1;i<N;i++){
        if(arr[i] - lastPossibleStall >= minAllowedDist){
            cows++;
            lastPossibleStall = arr[i];
        }
        if(cows == C){
            return true;
        }
    }

    return false;
}

int minDist(vector<int> &arr,int N,int C){
    sort(arr.begin(),arr.end());

    int st=arr[0],end=arr[N-1] - arr[0];
    int ans = -1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isPossible(arr,N,C,mid)) {
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }

    return ans;
    
}

int main()
{
    vector<int> arr = {2, 1, 8, 4,9};
    int N = 4, C = 3;

    cout << minDist(arr,N,C) << endl;
    return 0;
}