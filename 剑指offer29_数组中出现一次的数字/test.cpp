#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
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

void TestFunc(){
	vector<int> array{1, 1, 2, 3, 3, 3, 4, 4, 5, 5};
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