#include<bits/stdc++.h>
using namespace std;

const int MAX_COUNT = 3;

class Dfs {
	int soLuong, countPath;
	string tempX, tempY;
	map<string, vector<string>> a;
	vector<string> dsL;
	map<string, string> father;
	stack<string> path;
	map<string, int> trongSo;
	
	public:
	void input(){
		for(int i = 0; i < 100; i++) {
			cin >> tempX; // nhap dinh
			int x, s;// x: trong so dinh, s: so dinh ke.
			cin >> x >> s;
			trongSo[tempX] = x;
			
			for(int i = 0; i < s; i++){
				cin >> tempY;
				a[tempX].push_back(tempY);
				father[tempY] = tempY;
			}
			father[tempX] = tempX;
		}	 
	}
	void dfs(string start, string finish) {
		stack<string> st;
		st.push(start);
		dsL.push_back(start);	
		cout << " Phat trien TT  | Trang thai ke\t\t| Danh sach L1 \t\t| Danh sach L" << endl;
		cout << "--------------------------------------------------------------------------------------------" << endl;
		
		while(!st.empty()) {
			string temp = st.top();	
			cout << temp << "-" << trongSo[temp] << setw(14) << "|";
			dsL.pop_back();
			st.pop();		
			
			if(temp == finish) {
				findPath(start, finish);
				return;
			}
			
			int count = 0;
			map<int, string> dsL1;
			
			//ds ke
			for(string test : a[temp]) {
				cout << test << "-" << trongSo[test] << " ";
				dsL1[trongSo[test]] = test;
				count++;
			}
			
			formatTable(count, MAX_COUNT);
			
			count = 0;
			// ds L1
			for (auto it : dsL1) {
        		cout << it.second << "-" << it.first << " ";
        		count++;
    		}
			
			for (auto it = dsL1.rbegin(); it != dsL1.rend(); ++it) {
				st.push(it->second);
				dsL.push_back(it->second);
				father[it->second] = temp;
			}
			
			formatTable(count, MAX_COUNT);
			
			//in dsL
			for(int i = dsL.size()-1; i >= 0; i--){
				cout << dsL[i] << "-" << trongSo[dsL[i]] <<" ";
			}
			cout << endl;
		}
		cout << "\n----------------------------------------------" << endl;
		cout << "\nKhong tim thay duong di tu " << start << " -> " << finish;
	}
	
	void formatTable(int count, int maxCount) {
		cout << " ";
		for(int i = count; i <= maxCount; i++) {
			cout << " \t";
		}
		cout << "|";
	}
	
	void findPath(string start, string finish) {
		cout << "\n--------------------------------------------------------------------------------------------" << endl;
		cout << "\nKet qua cua duong di DFS tu " << start << " -> " << finish <<  " la:\n";			
		while(father[finish] != finish) {
			path.push(finish);
			finish = father[finish];
		}		
			
		cout << start;
		while(!path.empty()){
			cout << " -> " << path.top();
			path.pop();
		}
	}
};

int main() {
	string start, finish;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> start >> finish;
	Dfs d;
	d.input();
	d.dfs(start, finish);
	
	return 0;
}
