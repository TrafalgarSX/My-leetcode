//最长回文子串
/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

链接：https://leetcode-cn.com/problems/longest-palindromic-substring

*/
#include <stdio.h>
#include <vector>
#include<iostream>
#include<string>
#include<limits.h>
#include<windows.h>
#include<math.h>
using namespace std;
//暴力法   
class Solution {
public:
    string longestPalindrome(string s) {
		if(s==""){
			return "";
		}
		if(s.size()==1){
			return s;
		}
		bool sign;
        int maxlength=1;
		string sub;
		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				if(s[i]==s[j]){
					int k=i,z=j;
					if((z-k+1)%2==0){
						for(;k!=z+1;k++,z--){
                            if(s[k]==s[z]){
								sign=true;
								continue;
							}
							else{
								sign=false;
								break;
							}
						}
					}
					else{
						for(;k!=z;k++,z--){
                        if(s[k]==s[z]){
							sign=true;
								continue;
							}
							else{
								sign=false;
								break;
							}
					}
				}
				
				
				if(sign==true&&j-i+1>maxlength){
					maxlength=j-i+1;
					sub=s.substr(i,maxlength);
				} 
			}
		}
    }
	if(maxlength==1){
		return s.substr(0,1);
	}
	return sub;
	}
};

//暴力破解优化版    动态规划
class Solution1 {
public:
    string longestPalindrome(string s) {
		int maxlength=0;
		string sub="";
        int length=s.size();
		vector<vector<bool>> solve(length,vector<bool>(length));
		for(int len=1;len<=length;len++){
			for(int start=0;start<length;start++){
				int end=start+len-1;
				if(end>=length){
					break;
				}
				solve[start][end]=((len==1)||(len==2)||solve[start+1][end-1])&&s[start]==s[end];
			
				if(solve[start][end]&&len>maxlength){
					sub=s.substr(start,len);
				}
			}	
		}	
		return sub;
 	}
};
//扩展中心法
int expandAroundCenter(string &s,int left,int right){
	while(left>=0&&right<s.size()&&s[left]==s[right]){
			left--;//注意在最后一次循环时   多执行了一次   left-- right++
			right++;
	
	}
	return right-left-1;
}


class Solution2 {
public:
    string longestPalindrome(string &s) {//这里改为传引用，就可以大幅提高时间和空间效率
		if(s.size()==1){
			return s;
		}
		string sub="";
		int length=s.size();
		int begin=0,end=0;
		for(int start=0;start<length;start++){
			int len1=expandAroundCenter(s,start,start);
			int len2=expandAroundCenter(s,start,start+1);
			int len=max(len1,len2);
			if(len>end-begin+1){
				begin=start-(len-1)/2;
				end=start+len/2;
			}
		}
	return s.substr(begin,end-begin+1);
	}
	};
//马拉车算法    待学习    


int main()
{
 string str="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; 
 Solution2 test;
 cout<<test.longestPalindrome(str)<<endl;

 system("pause");
 return 0;
}
