#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    vector<long long>values;
    vector<long long>weights;
    long long n;
    long long capacity;
    cin>>capacity>>n;
    for(int i=0;i<n;i++){
        long long v;
        long long c;
        cin>>v>>c;
        values.push_back(v);
        weights.push_back(c);
    }
    vector<vector<long long>>dp(n,vector<long long>(capacity+1,0));
    for(int i=weights[0];i<=capacity;i++){
        dp[0][i]=values[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int cap=0;cap<=capacity;cap++){
            long long pick=-1e9;
            long long notpick=dp[idx-1][cap];
            if(cap>=weights[idx]) pick=values[idx]+dp[idx-1][cap-weights[idx]];
            dp[idx][cap]= max(pick,notpick);
        }
    }   
    cout<<"Max Value :"<<dp[n-1][capacity]<<endl;
    int cap=capacity;
    cout<<"Included Items: "<<endl;
    vector<long long>chosenOnes;
    int sum=0;
    for(int idx=n-1;idx>=0;idx--){
        if(idx==0 ){
            if(dp[idx][cap]!=0) {
                chosenOnes.push_back(idx);
                sum+=values[idx];
            }
            
        }else if(dp[idx][cap]!=dp[idx-1][cap]){
            chosenOnes.push_back(idx);
            sum+=values[idx];
            cap-=weights[idx];
        }
    }
    
    for(auto&it:chosenOnes){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Verification"<<endl;
    cout<<sum<<endl;

}