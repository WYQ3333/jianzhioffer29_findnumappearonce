#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution1 {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		sort(data.begin(), data.end());
		int flag = 0;
		int i = 0;
		int j = 1;
		while (j < data.size()){
			if (data[i] == data[j]){
				i += 2;
				j += 2;
			}
			else if (flag == 0 && data[i] != data[j]){
				int c = data[i];
				*num1 = c;
				flag = 1;
				i += 1;
				j += 1;
			}
			else if (flag == 1 && data[i] != data[j]){
				int c = data[i];
				*num2 = c;
				flag = 2;
				i += 1;
				j += 1;
			}
		}
	}
};

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int i = 0;
		int j = 0;
		int count = 0;
		for (i = 0; i < data.size(); ++i){
			for (j = i + 1; j < data.size(); ++j){
				if (data[j] == data[i]){
					break;
				}
			}
			if (j==data.size()&&count == 0){
				num1[0] = data[i];
				count++;
			}
			else if(j==data.size()&&count==1){
				num2[0] = data[i];
				count++;
			}
		}
	}
};

void TestFunc(){
	vector<int> array{2, 4, 3, 6, 3, 2, 5, 5};
	Solution s;
	int num1[] = { 0 };
	int num2[] = { 0 };
	s.FindNumsAppearOnce(array, num1, num2);
	cout << num1[0] << endl;
	cout << num2[0] << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}