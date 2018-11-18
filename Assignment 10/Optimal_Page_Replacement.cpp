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
    unordered_map<int,vector<int> > page_index;
    re(i,total_pages){
        page_index[pages[i]].push_back(i);
    }
    for(auto it = page_index.begin();it!=page_index.end();it++){
        reverse(it->second.begin(),it->second.end());
    }
    int curr_size = 0;
    vector<bool> is_present(100,false);
    vector<int> in_mem;
    re(i,total_pages){
        re(k,in_mem.size()){
            cout<<in_mem[k]<<" ";
        }
        cout<<endl;
        curr_size = in_mem.size();
        if(curr_size < page_size){
            page_fault++;
            int size = page_index[pages[i]].size();
            page_index[pages[i]].pop_back();
            is_present[pages[i]]=true;
            in_mem.push_back(pages[i]);
        }
        else{
            if(is_present[pages[i]]==true){
                page_index[pages[i]].pop_back();
            }else{
                int max_ind = INT_MIN;
                pair<int,int> to_rem = {0,0};
                re(j,in_mem.size()){
                    int size = page_index[in_mem[j]].size();
                    if(size == 0){
                         to_rem = make_pair(in_mem[j],j);
                         break;
                    }
                    if(max_ind < page_index[in_mem[j]][size-1]){
                        to_rem = make_pair(in_mem[j],j);
                        max_ind = page_index[in_mem[j]][size-1];                
                    }
                }
                     page_index[pages[i]].pop_back();
                in_mem.erase(in_mem.begin()+to_rem.second);
                in_mem.push_back(pages[i]);
                is_present[pages[i]]=true;
                is_present[to_rem.first]=false;
                page_fault++;
            }
        }
     //   cout<<i<<" "<<page_fault<<endl;
    }
    cout<<page_fault<<endl;

}