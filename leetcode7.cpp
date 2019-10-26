#include <stdio.h>
#include <vector>
#include<math.h>
#include<iostream>
#include<limits>
#include<cstdlib>
#include<sstream>
using namespace std;
//菜鸡练手法
class Solution {
public:
    int reverse(int x) {
        bool sign;
		long long reverse=x;
		if(x>=0){
			sign=true;
		}
		else{
			sign=false;
			reverse=-x;
		}
		
		string s=to_string(reverse),ss;// int类型转换string   to_string
		int length=s.size();
		for(int i=0,j=s.size()-1;i!=length/2;i++,j--){// i!=length/2   不论奇数还是偶数长度都可以完成逆序
			char c;
			c=s[i];s[i]=s[j];s[j]=c;
		}
		int first=0;
		while(true){
			if(s[first]!=0)break;
			first++;
		}
		ss=s.substr(first,s.size()-first);
		stringstream stream;  // 用字符串流的方法  将string 类型转换成int 类型
		stream<<ss;
		stream>>reverse;
		if(!sign) reverse=-reverse;
		if(reverse<pow(-2,31)||reverse>(pow(2,31)-1)){
			return 0;
		}

		return reverse;
    }
};
//简洁清晰明白法
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};


int main(){
 Solution test;
 //cout<<test.reverse(-2147483648);
  stringstream sstream;//  用字符串流的方法  将int 类型转换成string 
  string s;
  sstream<<20;
  sstream>>s;
  cout<<s;
}