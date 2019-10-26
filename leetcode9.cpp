#include<iostream>
#include<sstream>
#include<string>
using namespace std;
//菜鸡复杂解法
class Solution {
public:
    bool isPalindrome(int x) {
    stringstream stream;
    string str;
    stream<<x;
    stream>>str;
    string cur;
        for(int i=0;i<str.size();i++){
            cur.push_back('#');
            cur.push_back(str[i]);
        }
        cur.push_back('#');
        int left=cur.size()/2-1,right=cur.size()/2+1;
        for(int j=0;j<cur.size()/2;j++){
            if(cur[left]==cur[right]){
                left--;
                right++;
            }
            else{
                return false;
            }
        }
    return true;
    }
};
class Solution1{
    public:
    bool isPalindrome(int x){
        if(x<0||(x%10==0&&x!=0)){
            return false;
    }
    int temp=0;
    while(temp<x){  
        temp=temp*10+x%10;
        x/=10;
    }
    return x==temp||temp/10==x;
    }
};

int main(){
    Solution1 test;
    if(test.isPalindrome(121)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}