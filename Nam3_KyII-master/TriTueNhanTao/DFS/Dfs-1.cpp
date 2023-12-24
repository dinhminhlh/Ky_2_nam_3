#include<bits/stdc++.h>

using namespace std;

string start, finish, tempX, tempY;
map<string, vector<string> > a;
vector<string> dsL;
map<string, string> father;
stack<string> path;

class Dfs {
	int soLuong, countPath;
	
	public:
	void dfs(string start, string finish) {
		stack<string> st;
		st.push(start);
		dsL.push_back(start);
		
		cout << "Phat trien TT |  Trang thai ke  | Danh sach L" << endl;
		cout << "----------------------------------------------" << endl;
		while(!st.empty()) {
			string temp = st.top();	
			cout << temp << setw(14) << "|";

			dsL.pop_back();
			st.pop();
			
			if(temp == finish) {
				cout << "\n----------------------------------------------" << endl;
				cout << "\nKet qua cua duong di DFS tu " << start << " -> " << finish <<  " la:\n";
			
				while(father[finish] != finish) {
					path.push(finish);
					finish = father[finish];
				}
				cout<<start;
				while(!path.empty()){
					cout<<" -> "<<path.top();
					path.pop();
				}
				return;
			}
			
			
			int count = 0;
			
			for(string next : a[temp]) {
				st.push(next);
				//in canh ke
				cout << next << " ";
				dsL.push_back(next);

				soLuong++;
				
				father[next] = temp;
			}
			for(int i = count; i <= 5; i++) {
				cout << "  ";
			}
			
			cout << "\t\t|";
	
			//in ds ke
			for(int i = dsL.size() - 1; i >= 0; i--){
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
	//freopen("output.txt", "w", stdout);
	cin >> start >> finish;
	for(int i = 0; i < 100; i++) {
		string temp, t;
		int count = 0;
		cin >> temp;
		stringstream ss(temp);
		
		while(getline(ss, t, ',')) {
			if(count == 0) {
				tempX = t;
			} else {
				tempY = t;
				a[tempX].push_back(tempY);
				cout << tempX << " " << tempY << endl;
			}
			count++;
		}
		
		father[tempX] = tempX;
		father[tempY] = tempY;
		
	}	 
	Dfs d;
	d.dfs(start, finish);
	
	return 0;
}
