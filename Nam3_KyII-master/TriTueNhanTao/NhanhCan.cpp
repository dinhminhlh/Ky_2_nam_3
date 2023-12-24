#include<bits/stdc++.h>
using namespace std;

class Dfs {
	int soLuong, countPath;
	map<string, map<string, int> > a;
	vector<pair<int, string> > dsL;
	map<string, string> father;
	stack<string> path;
	map<string, int> trongSo;
	
	public:
	void input(){
		for(int i = 0; i < 1000; i++) {
			string tempX;
			cin >> tempX; // nhap dinh
			int x, s;// x: trong so dinh, s: so dinh ke.
			cin >> x >> s;
			trongSo[tempX] = x;
			
			for(int i = 0; i < s; i++){
				string tempY;
				int trongSo;
				cin >> tempY;
				cin >> trongSo;
				
				a[tempX][tempY] = trongSo;
				father[tempY] = tempY;
			}
			
			father[tempX] = tempX;
		}	 
	}
	void dfs(string start, string finish) {
		stack<pair<int, string>> st;
		st.push({0, start});
		dsL.push_back({0, start});	
		printf("%-8s|%-7s|%-7s|%-7s|%-7s|%-7s|%-23s|%-30s\n", "PTTT", "TTK", "k(u, v)", "k(v)", "g(v)", "f(v)", "Danh sach L1", "Danh sach L");
		cout << "===========================================================================================================\n";
		
		while(!st.empty()) {
			pair<int, string> temp = st.top();	
			cout << temp.second << "-" << temp.first << "\t|";
			cout << right << setw(8) << "|" 
					<< right << setw(8) << "|" 
					<< right << setw(8) << "|" 
					<< right << setw(8) << "|" 
					<< right << setw(8) << "|" 
					<< right << setw(24) << "|";
			dsL.pop_back();
			st.pop();		
			
			if(temp.second == finish) {
				int minPath = INT_MAX;
				
				for(auto test : dsL) {
					if(test.first < minPath) {
						minPath = test.first;
					}	
				}
				
				if(temp.first <= minPath) {
					findPath(start, finish, temp.first);
					return;
				} else {
					cout << "\n\t|Trang thai ket thuc tim duoc duoc di tam thoi do dai " << minPath;
				}
			}
			
			multimap<int, string> dsL1;
			
			//ds ke
			for(auto dinhKe : a[temp.second]) {
				int g = temp.first + dinhKe.second;
				
				// cap nhat trong so G khi khong phai dinh dau tien
				if(temp.second != start) {
					g -= trongSo[temp.second];
				}
				
				int f = g + trongSo[dinhKe.first];
				
				cout << endl 
					<< right << setw(9) << "|" 
					<< left << setw(7) << dinhKe.first << "|" 
					<< left << setw(7) << dinhKe.second <<"|" 
					<< left << setw(7) << trongSo[dinhKe.first] << "|" 
					<< left << setw(7) << g << "|" 
					<< left << setw(7) << f
					<< left << setw(24) << "|"
					<< "|";
				dsL1.insert({f, dinhKe.first});
			}
			
			// ds L1
			string str = "";
			for (auto it : dsL1) {
        		str += it.second + "-" + to_string(it.first) + " ";
    		}
    		
    		if(str != "") {
    			cout << endl 
				<< right << setw(9) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< left << setw(23) << str
				<< "|";
			}

			for (auto it = dsL1.rbegin(); it != dsL1.rend(); ++it) {
				st.push({it->first , it->second});
				dsL.push_back({it->first , it->second});
				father[it->second] = temp.second;
			}
			
			//in dsL
			str = "";
			for(int i = dsL.size()-1; i >= 0; i--){
				str += dsL[i].second + "-" + to_string(dsL[i].first) + " ";
			}
			
			cout << endl
				<< right << setw(9) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(8) << "|" 
				<< right << setw(24) << "|"
				<< left << setw(30) << str;
			
			cout << "\n===========================================================================================================\n";
		}
		cout << "\n----------------------------------------------\n";
		cout << "\nKhong tim thay duong di tu " << start << " -> " << finish;
	}
	
	void findPath(string start, string finish, int distance) {
		cout << "\n===========================================================================================================\n";
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
		
		cout << "\nDo dai duong di la: " << distance; 
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
