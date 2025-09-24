#include <iostream>
using namespace std;

class solution{
public:
 bool isPalindrome(int x)
   {
      if(x<0)  return false; // there is no negative palindrome number

      int original=x;
      long reverse=0;

      while(x>0){
        int num = x%10;
        reverse = reverse*10 + num;
        x/=10;
      }
      return original == reverse;
    }
};
int main()
{
    solution solo;
    int x;
    cout<<"Enter testing number:"<<endl;
    cin>>x;
    cout<<boolalpha<<solo.isPalindrome(x)<<endl;
    return 0;
}
