#include<bits/stdc++.h>
using namespace std;

string start, finish, tempX, tempY;
map<string, vector<string> > a;
vector<string> dsL;
map<string, string> father;
stack<string> path;

class Dfs {
	int soLuong, countPath;
	//string start, finish, tempX, tempY;
	public:
	
	void dfs(string start, string finish) {
		stack<string> st;
		st.push(start);
		dsL.push_back(start);
		//soLuong++;
		
		cout << "Phat trien TT |  Trang thai ke\t| Danh sach L" << endl;
		cout << "----------------------------------------------" << endl;
		while(!st.empty()) {
			string temp = st.top();	
			cout << left << setw(14) << temp << "|";
			//soLuong--;

			dsL.pop_back();
			st.pop();
			
			if(temp == finish) {
				cout << "\n----------------------------------------------" << endl;
				cout << "\nKet qua cua duong di DFS tu " << start << " -> " << finish <<  " la:\n";
			
				while(father[finish] != finish) {
					path.push(finish);
					finish = father[finish];
				}
				//duong di
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
				cout << left << setw(2) << next << " ";
				dsL.push_back(next);
				count++;
				
				father[next] = temp;
			}
			for(int i = count; i <= 5; i++) {
				cout << right << setw(2) << " ";
			}
			
			cout << "\t|";
			//in ds ke
			for(int i= dsL.size()-1 ;i>=0;i--){
				cout<<dsL[i]<<" ";
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
		cin >> tempX;
		int s;
		cin>>s;
		for(int i=0;i<s;i++){
			cin>>tempY;
			a[tempX].push_back(tempY);
			father[tempY] = tempY;
		}
		father[tempX] = tempX;
	}	 
	Dfs d;
	d.dfs(start, finish);
	
	return 0;
}
