//寻找两个有序数组中的中位数
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
using namespace std;

double middlenum(vector<int>&nums1,int start1,int end1,vector<int>& nums2,int start2,int end2,int middle){
      
      int len1=end1-start1+1;
      int len2=end2-start2+1;

      if(len1>len2){
        return middlenum(nums2,start2,end2,nums1,start1,end1,middle);
      }
      if(len1==0)
      {
        return nums2[start2+middle-1];
      }
      if(middle==1)
      {
       return min(nums1[start1],nums2[start2]); 
      }
      
      int i=min(middle/2,len1)-1+start1;
      int j=min(middle/2,len2)-1+start2;

      if(nums1[i]>nums2[j]){
       return  middlenum(nums1,start1,end1,nums2,j+1,end2,middle-(j-start2+1));
      }
      else{
       return middlenum(nums1,i+1,end1,nums2,start2,end2,middle-(i-start1+1));//排除掉了几个小的，不符合的
      }

}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1=nums1.size();
        int length2=nums2.size();
        int middle,middle1;
        middle=(length1+length2+1)/2;
        middle1=(length1+length2+2)/2;
        return (middlenum(nums1,0,length1-1,nums2,0,length2-1,middle)+middlenum(nums1,0,length1-1,nums2,0,length2-1,middle1))/2;
    } 
   
};

int main() {
 Solution test;
 vector<int> nums1={1,2};
 vector<int> nums2={3,4};
 double ret=test.findMedianSortedArrays(nums1,nums2);
 cout<<ret<<endl;
 cout<<"hello world"<<endl;
  return 0;
}