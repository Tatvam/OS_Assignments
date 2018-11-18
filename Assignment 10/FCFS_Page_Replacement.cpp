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
    vector<bool> is_present(100,false);
    queue<int> q;
    int curr_size = 0;
    re(i,total_pages){

        curr_size = q.size();
        if(curr_size < page_size){
            is_present[pages[i]]=true;
            page_fault++;
            q.push(pages[i]);
        }else{
            if(is_present[pages[i]]==true){
                continue;
            }else{
                page_fault++;
                is_present[q.front()] = false;
                q.pop();
                q.push(pages[i]);
                is_present[pages[i]]=true;
            }
        }
    }
    cout<<page_fault<<endl;
}

// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1