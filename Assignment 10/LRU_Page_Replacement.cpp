#include<bits/stdc++.h>
#include<map>
using namespace std;
#define re(i,n) for(int i = 0;i<n;i++)
int main(){
    int total_pages;
    cin>>total_pages;
    vector<int> pages(total_pages);
    re(i,total_pages){
        cin>>pages[i];
    }
    int page_size;
    int page_fault = 0;
    cin>>page_size;
    vector<pair< int,int> > in_mem;
    int freq = 0;
    int curr_size = 0;
    vector<bool> is_present(100,false);
    re(i,total_pages){
        if(curr_size < page_size){
            curr_size++;
            page_fault++;
           // cout<<"hi"<<endl;
            freq++;
            in_mem.push_back(make_pair(pages[i],freq));
            is_present[pages[i]]=true;
        }else{
            if(is_present[pages[i]]==true){
                freq++;
                re(j,in_mem.size()){
                    if(in_mem[j].first == pages[i]){
                        in_mem[j].second=freq;
                    }
                }
            }else{
                page_fault++;
                int min = INT_MAX;
                int re = 0;
                int rj = 0;
                re(j,in_mem.size()){
                    if(min>in_mem[j].second){
                        min = in_mem[j].second;
                        re = j;
                        rj = in_mem[j].first;
                    }
                }
                is_present[rj]=false;
                is_present[pages[i]]=true;
                in_mem.erase(in_mem.begin()+re);
                in_mem.push_back(make_pair(pages[i],freq));
            }
        }
    }
    cout<<page_fault<<endl;
}