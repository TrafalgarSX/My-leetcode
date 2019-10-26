#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

bool isnum(char c){
   switch(c){
      case '0':return true;
      case '1':return true;
      case '2':return true;
      case '3':return true;
      case '4':return true;
      case '5':return true;
      case '6':return true;
      case '7':return true;
      case '8':return true;
      case '9':return true;
   }
   return false;
}
bool isnp(char c){
   switch(c){
      case '+':return true;
      case '-':return true;
   }
   return false;
}
//菜鸡的炒鸡复杂解法
class Solution 
{
public:
   int myAtoi(string str)
   {
      if(str==""){
         return 0;
      }
      string substr;
      bool sign=true;
      for(int i=0;i<str.size();i++)
      {
         if(str[i]!=' ')
         {
            sign=false;
            if(isnp(str[i])||isnum(str[i]))
            {
               int j=i;
               while(true)
               {
                  i++;
                  if((isnp(str[i])||isnum(str[i]))&&i<str.size()){
                     continue;
                  }
                  else{
                     break;
                  }
               }
               substr=str.substr(j,i-j);
               break;
            }
            else{
               sign=true;
               break;
            }
         }
         else{
            sign=true;
         }
      }
      if(sign==true){
         return 0;
      }
      long long cur;
      stringstream stream;
      stream<<substr;
      stream>>cur;
      if(cur<INT_MIN){
         return INT_MIN;
      }
      else if(cur>INT_MAX){
         return INT_MAX;
      }
      else{
         return cur;
      }
   }
};
int main(){
   Solution test;
   cout<<test.myAtoi("0-1");

}
