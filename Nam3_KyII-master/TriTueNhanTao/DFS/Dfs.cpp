#include<bits/stdc++.h>
using namespace std;

class Dfs {
	int soLuong, countPath;
	string start, finish, tempX, tempY;
	map<string, vector<string> > a;
	vector<string> dsL;
	map<string, string> father;
	vector<string> path;
	
	public:
	
	void dfs(string start, string finish) {
		stack<string> st;
		st.push(start);
		soLuong++;
		
		cout << "Phat trien TT |  Trang thai ke  | Danh sach L" << endl;
		cout << "----------------------------------------------" << endl;
		while(!st.empty()) {
			string temp = st.top();	
			cout << temp << setw(14) << "|";
			soLuong--;
			st.pop();
			
			if(temp == finish) {
				cout << "\n----------------------------------------------" << endl;
				cout << "\nKet qua cua duong di DFS tu " << start << " -> " << finish <<  " la:\n";
	
				while(father[finish] != finish) {
					path[countPath++] = finish;
					countPath++;
					finish = father[finish];
				}
				
				cout << start;
				
				for(int i = countPath - 1; i >= 0; i--) {
					cout << " -> " << path[i];
				}
				return;
			}
			
			
			int count = 0;
			
			for(string next : a[temp]) {
				st.push(next);
				cout << next << " ";
				dsL.push_back(next);
				soLuong++;
				
				if(father[next] == next) {
					father[next] = temp;
				}
			}
			for(int i = count; i <= 5; i++) {
				cout << "  ";
			}
			
			cout << "\t\t|";
			
			for(int i = soLuong - 1; i >= 0; i--) {
				cout << dsL[i] << " ";
			}
			cout << endl;
		}
		cout << "\n----------------------------------------------" << endl;
		cout << "\nKhong tim thay duong di tu " << start << " -> " << finish;
	}
};




int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> start >> finish;
	for(int i = 0; i < 100; i++) {
		cin >> tempX >> tempY;
		father[tempX] = tempX;
		fahter[tempY] = tempY;
		a[tempX].pus_back(tempY);
	}	 
	
	dfs(start, finish);
	
	return 0;
}
