#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;

        while(x!=0){
          int num = x%10;
          rev = rev*10 + num;
          x/=10;

          if(rev>INT_MAX || rev<INT_MIN){ // to check for overflow in integers
            return 0;
          }
        }
        return rev;

    }
};

int main()
{
    Solution sol;
    int x;
    cout<<"Enter your number:"<<endl;
    cin>>x;
    cout<<sol.reverse(x);

}