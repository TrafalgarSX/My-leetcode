//Z形变换
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
//方法一  按行访问
class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows==1) return s;
		
		string ret;
		int length=s.size();
		int cyclelen=2*numRows-2;

		for(int i=0;i<numRows;i++){
			for(int j=0;j+i<length;j+=cyclelen){
				ret+=s[j+i];
				if(i!=0&&i!=numRows-1&&j+cyclelen-i<length){
					ret+=s[j+cyclelen-i];
				}

			}
		}
	return ret;
	}
};
//方法二  按行排序
//从左到右迭代 ss，将每个字符添加到合适的行。
class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows==1) return s;
		string ret;
		vector<string>  rows(min(numRows,int(s.size())));
		int curRow=0;
		bool goingdown=false;
		for(char c:s){
			rows[curRow]+=c;
			if(curRow==0||curRow==numRows-1){
				goingdown=!goingdown;
			}
			curRow+=goingdown?1:-1;
		}
	for(string row:rows){
		ret+=row;
	}
	return ret;
	}
};

