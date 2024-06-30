#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
// int main()
// {
//     string str;
//     getline(cin,str);
    
//     int length = 0;
//     int n = str.size();

//     int i = n - 1;
//     while(i>=0 && str[i] == ' ')
//     {
//         i--;
//     }

//     while(i>=0 && str[i] != ' ')
//     {
//         length++;
//         i--;
//     }
//     cout<<length<<endl;
//     return 0;

// }









// int main()
// {
//     string r = "abcdefg";
//     int k = 2;
//     for(int i = 0;i<r.size();i++)
//     reverse(r.begin(),r.begin()+k);
//     cout<<r<<endl;
//     return 0;
// }

// int main()
// {
//     string str;
//     getline(cin,str);
//     for(int i = 0;i<str.size();i++)
    
    
//     reverse(str.begin(),str.begin()+2);
//     cout<<str<<endl;
    
//     return 0;
// }







// class Solution
// {
// public:
//     string reverseStr(string s,int k )
//     {
//         int n = s.length();
//         for(int i = 0;i<n;i += 2*k)
//         {
//             reverse(s.begin()+i,s.begin()+min(i+k,n));
            
            
//         }
//         return s;
//     }
// };


// int main()
// {
//     Solution sol;
//     string s = "abcdefg";
//     int k = 2;
//     cout<<sol.reverseStr(s,k)<<endl;

// }




// string reverseWords(const string &r)
// {
//     string result = r;
//     auto world_start = result.begin();
//     while(world_start != result.end())
//     {
//         auto world_end = find(world_start,result.end(),' ');
//         reverse(world_start,world_end);
//         if(world_end == result.end()) break;
//         else
        
//             world_start = world_start + 1;

//         }
//         return result;

// }



// int main()
// {
//     string r = "hello world";
//     cout<<reverseWords(r)<<endl;
//     return 0;
// }






// int main()
// {
//     string num1 = "22";
//     string num2 = "41";
//     int n = num1.size();
//     int b = num2.size();
//     for(int i = 0;i<num1.size();i++)
//     {
        
//     }
//     return 0;
// }


