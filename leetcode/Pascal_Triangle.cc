/*************************************************************************
    > File Name: Pascal_Triangle.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 22 Mar 2015 11:36:55 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > generate(int numRows) {

			vector< vector<int> > ret;
			if(numRows <= 0)
				return ret;
			vector<int> temp;
			temp.push_back(1);
			ret.push_back(temp);
			for(int i = 1; i < numRows; ++i)
			{
				temp.clear();
				temp.push_back(1);
				for(int j = 1; j < i; ++j)
				{
					temp.push_back(ret[i-1][j-1] + ret[i-1][j]);
				}
				temp.push_back(1);
				ret.push_back(temp);
			}
			return ret;
		}
};
int main(int argc, char *argv[])
{
	Solution s;
	vector< vector<int> > ret = s.generate(0);
	for(int i = 0; i != ret.size(); ++i)
	{
		cout << "[";
		for(int j = 0; j != ret[i].size(); ++j)
			cout << ret[i][j] << ",";
		cout << "]";
		cout << ",";
	}
	return 0;
}


