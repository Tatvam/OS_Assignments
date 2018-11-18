/**************************************************
*    NAME:           TATVAM DADHEECH(td_1417)     *
*    INSTITUITION:   IIT BHUBANESWAR              *
**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define re(i, n) for(int i = 0; i < n; i++)
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
vector<int> wt(10000,0);
class process{
    public:
        int arr;
        vector<int> cbur;
        vector<int> ibur;
        int total;
};

void waitingtime(vector<process> p,int n){
    int t = 0;
    int completed = 0;
    int min = INT_MAX;
    int proc = 0;
    deque<pair<int,int> > ioq;
     pair<int,int> top_prior;
     top_prior = make_pair(-1,-1);
    vector<bool> inq(n,false);
    while(completed!=n){
        // Min CPU burst;
        re(i,n){
            if(p[i].arr<=t && p[i].cbur.size()>0 && p[i].cbur[p[i].cbur.size()-1]<min && inq[i]==false){
                if(min!=INT_MAX)
                p[proc].cbur[p[proc].cbur.size()-1]=min;
                min =  p[i].cbur[p[i].cbur.size()-1];
                proc = i;
            }
        }
        cout<<"Process: "<<((min != INT_MAX)?(proc+1):-1)<<" "<<"I/O Queue: "<<top_prior.second+1<<" "<<"Time: "<<t<<endl;
           if(min==INT_MAX){
        }else{
            min--;
        }
                // I/O burst
        if(!ioq.empty()){
            top_prior = ioq.front();
            ioq.pop_front();
            top_prior.first--;
            if(top_prior.first <= 0){
                 p[top_prior.second].ibur.pop_back();
                inq[top_prior.second]=false;
                if(p[top_prior.second].cbur.size()==0 && p[top_prior.second].ibur.size()==0){
                completed++;
                 wt[top_prior.second]=t-(p[proc].total+p[proc].arr)+1;
                }
                if(!ioq.empty()){
                top_prior=ioq.front();
                ioq.pop_front();
                ioq.push_front(make_pair(top_prior.first-1,top_prior.second));
                }
                else{
                top_prior = make_pair(-1,-1);}
            }else{
                ioq.push_front(top_prior);
            }
        }
         if(min <= 0){
            p[proc].cbur.pop_back();
            if(p[proc].cbur.size()==0 && p[proc].ibur.size()==0){
                completed++;
                wt[proc]=t-(p[proc].total+p[proc].arr);
            }else{
                if(p[proc].ibur.size()!=0){
                    inq[proc]=true;
                    ioq.push_back(make_pair(p[proc].ibur[p[proc].ibur.size()-1],proc));
                    top_prior=ioq.front();
                }
            }
            min = INT_MAX;
        }
       t++;
         // CPU burst 
        
    }
       
}

void printwait(int n){
    re(i,n){
        cout<<"Process: "<<i+1<<" "<<"Waiting Time: "<<wt[i]<<endl;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    vector<process> p(100);
    int m,n;
    cin>>m;
    n = m;
    int j = 0;
    int i = 0;
    while(m--){
        //cout<<"Hi"<<endl;
        j = 0;
        cin>>p[i].arr;
        while(1){
            int t;
            cin>>t;
            if(t == -1){
                break;
            }
            if(j%2==0){
                p[i].cbur.push_back(t);
            }else{
                p[i].ibur.push_back(t);
            }
            j++;   
            p[i].total+=t;
        }
        reverse(p[i].cbur.begin(),p[i].cbur.end());
        reverse(p[i].ibur.begin(),p[i].ibur.end());
        i++;
        
    }
    waitingtime(p,n);
    printwait(n);
    /* re(i,5){
        cout<<p[i].arr<<endl;
        re(j,p[i].cbur.size()){
            cout<<p[i].cbur[j]<<" ";
        }cout<<endl;
        re(j,p[i].ibur.size()){
            cout<<p[i].ibur[j]<<" ";
        }cout<<endl;

    } */
    
}