#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double calculateArea(int a, int b, int c, int d) {
      double ans = sqrt((a-c)*(a-c) + (b-d)*(b-d));
      return ans;
    }
    double herons(double a, double b, double c) {
      double semiperimeter = (a+b+c)/2;
      double ans = sqrt(
          semiperimeter*(semiperimeter-a)*(semiperimeter-b)*(semiperimeter-c)
          );
      return ans;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
      double ans = 0;
      int n =(int) points.size();
      for(int i =0; i <n; i++){ 
        for(int j = i+1; j < n; j++){
          for(int k = j+1; k < n; k++) {
            double first = calculateArea(points[i][0], points[i][1], points[j][0], points[j][1]);
            double second = calculateArea(points[i][0], points[i][1], points[k][0], points[k][1]);
            double third = calculateArea(points[j][0], points[j][1], points[k][0], points[k][1]);
            ans=max(ans, herons(first, second, third));
          }
        }
      }
      return ans;
    }
};
