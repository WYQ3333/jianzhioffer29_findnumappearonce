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

class Solution2 {
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

class Solution3 {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int i = 0;
		int j = 0;
		int count = 0;
		for (i = 0; i < data.size(); ++i){
			for (j = 0; j < data.size(); ++j){
				if (j != i&&data[i] == data[j]){
					break;
				}
			}
			if (j == data.size() && count == 0){
				num1[0] = data[i];
				count++;
			}
			else if (j == data.size() && count == 1){
				num2[0] = data[i];
				count++;
			}
		}
	}
};

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
		if (data.size() < 2)
			return;

		int resultExclusiveOR = 0;
		for (int i = 0; i < data.size(); i++){
			resultExclusiveOR ^= data[i];
		}

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		*num1 = *num2 = 0;
		for (int j = 0; j < data.size(); j++){
			if (IsBit1(data[j], indexOf1))
				*num1 ^= data[j];
			else
				*num2 ^= data[j];
		}

	}

		/*我们还是从头到尾依次异或数组中的每一个数字，
		那么最终得到的结果就是两个只出现一次的数字的异或结果。
		因为其它数字都出现了两次，在异或中全部抵消掉了。
		由于这两个数字肯定不一样，那么这个异或结果肯定不为0 ，
		也就是说在这个结果数字的二进制表示中至少就有一位为1 。
		我们在结果数字中找到第一个为1 的位的位置，记为第N 位。
		现在我们以第N 位是不是1 为标准把原数组中的数字分成两个子数组，
		第一个子数组中每个数字的第N 位都为1 ，
		而第二个子数组的每个数字的第N 位都为0 。*/

	unsigned int FindFirstBitIs1(int num){
		int indexBit = 0;
		while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
			num = num >> 1;
			indexBit++;
		}

		return indexBit;
	}

	bool IsBit1(int num, unsigned int indexBit){
		num = num >> indexBit;
		return (num & 1);
	}

};

void TestFunc(){
	vector<int> array{1, 1, 1, 1, 4, 6};
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