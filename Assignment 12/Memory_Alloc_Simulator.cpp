#include<bits/stdc++.h>
using namespace std;

#define re(i,n) for(int i = 0;i<n;i++)
vector<int> occupied(100005,-1);
class memory{
private:
	int mem_size;
	map<int,vector<pair<int,int> > >log_address;
	//map<int,int> log_add_size;
public:
	void initialize();
	void alloc();
	void free();
	void printPhysicalDistribution();
};

void memory :: initialize(){
	int size;
	cin>>size;
	mem_size = size;
}

void memory :: alloc(){
	int size;
	cin>>size;
	if(log_address.size()==0){
		if(size > mem_size){
			cout<<"Can't allocate that much memory.Either memory is full or size is exceeding memory limit"<<endl; 
			return;
		}
		log_address[0].push_back(make_pair(0,size-1)); 
		occupied[0]=size-1;
		//cout<<"HI"<<endl;
		cout<<"Logical Address "<<0<<endl;
	}else{
		vector<pair<int,int> > req_ch;
		int flag2 = 0;
		int ch = 0;
		int comp=0;
		int flag  = 0;
		int flag4  = 0;
		int log_add = -1;
		int flag3 = 0;
		int flag5 = 0;
		pair<int,int> chunk;
		re(i,mem_size){
			if(occupied[i]!=-1){
				if(flag == 1){
					chunk.second = ch+chunk.first;
					req_ch.push_back(make_pair(chunk.first,chunk.second-1));
					ch = 0;
					flag3 = 0;
					flag = 0;
					if(comp == size){
						flag5 = 1;
					}
				}
				i = occupied[i];
			}else{
				flag = 1;
				if(flag2 == 0 ){
				log_add = i;
				flag2 = 1;
				}
				if(flag3 == 0){
					chunk.first = i;
					flag3 = 1;
				}
				if(comp == size){
				//	flag4 = 1;
					chunk.second = ch+chunk.first;
					req_ch.push_back(make_pair(chunk.first,chunk.second-1));
					re(i,req_ch.size()){

						log_address[log_add].push_back(req_ch[i]);
						occupied[req_ch[i].first]=req_ch[i].second;
					//	cout<<req_ch[i].first<<" "<<req_ch[i].second<<endl;
					}
					cout<<"Logical Address "<<log_add<<endl;
					req_ch.clear();
					flag4 = 1;
					flag5 = 0;
					break;
				}
			comp++;
			ch++;

			}
		}
		if(comp == size && flag4 == 0){
				//	flag4 = 1;
					chunk.second = ch+chunk.first;
					if(flag5 ==0)
					req_ch.push_back(make_pair(chunk.first,chunk.second-1));
					re(i,req_ch.size()){

						log_address[log_add].push_back(req_ch[i]);
						occupied[req_ch[i].first]=req_ch[i].second;
						//cout<<req_ch[i].first<<" "<<req_ch[i].second<<endl;
					}
					cout<<"Logical Address "<<log_add<<endl;
					req_ch.clear();
				}
		if(comp != size){
			cout<<"Sorry, no free size"<<endl;
			req_ch.clear();
		}
	}
}

void memory :: free(){
	int log_add;
	cin>>log_add;
	std::map<int,vector<pair<int,int> > >::iterator it;
	it = log_address.find(log_add);
	if(it!=log_address.end()){
		int n = log_address[log_add].size();
		re(i,n){
			occupied[log_address[log_add][i].first]=-1;
			cout<<log_address[log_add][i].first<<endl;
		}
		log_address.erase(log_add);
	}

}

void memory :: printPhysicalDistribution(){
	cout<<"------------------------------------------------------------------------------"<<endl;
	vector<int> size;
	int n = log_address.size();
	std::map<int,vector<pair<int,int> > >::iterator it;
	for(it = log_address.begin();it!=log_address.end();it++){
		int s=0;
		int m = it->first;
		re(j,log_address[m].size()){
			s+=log_address[m][j].second-log_address[m][j].first+1;
		}
		size.push_back(s);
	}
	int i = 0;
	for(it = log_address.begin();it!=log_address.end();it++){
		int m = it->first;
		cout<<"Logical Address : "<<it->first<<endl;
		cout<<"Chunk Size : "<<size[i]<<endl;
		cout<<"chunk in memeory : "<<endl;
		re(j,log_address[m].size()){
			cout<<log_address[m][j].first<<" "<<log_address[m][j].second<<endl;
		}
		i++;
		cout<<"-----------------------------------------------------------------------------"<<endl;
	}
}

int main(){
	memory m1;
	while(1){
	string s;
	cin>>s;
	if(!s.compare("initialize")){
		m1.initialize();
	}else if(!s.compare("alloc")){
		m1.alloc();
	}else if(!s.compare("free")){
		m1.free();
	}else if(!s.compare("printPhysicalDistribution")){
		m1.printPhysicalDistribution();
	}
}
}