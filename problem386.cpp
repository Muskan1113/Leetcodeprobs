//lexicographical order

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> lexicalOrder(int n) //The function lexicalOrder takes an integer n as input and returns a vector of integers
    {
        vector<int> ans;//an empty vector ans is created to store the resulting lexicographically ordered numbers.

                        //The code then defines a lambda function dfs that performs a depth-first search to generate the numbers in the desired order.
                        // The lambda function takes two parameters: self, which is a reference to itself, and cur, which represents the current number in the search.

        auto dfs = [&](const auto & self, long long cur) -> void 
        {
            if(cur > n ) return;//The first condition inside dfs checks if the current number cur exceeds the given limit n.
            // If it does, the function returns, indicating the end of the search for that branch.
            ans.push_back(cur);
            //If the current number is within the range, it is added to the ans vector using ans.push_back(cur)
            self(self, cur * 10);//The dfs function calls itself recursively twice. The first recursive call is made with cur * 10. 
                                 //This is done to explore the next level of the search tree by appending a zero at the end of the current number.
                                 // For example, if cur is 1, the next number to explore would be 10.

            if(cur % 10 != 9) /* The second recursive call is made with cur + 1.
                               This is done to explore the sibling nodes in the search tree, which means incrementing the current number by 1.
                                However, this call is made only if the last digit of the current number is not 9, as adding 1 to a number whose last digit is 9 would result in a number with a leading zero, which is not allowed in the lexicographical order.
                              The dfs function is initially called with dfs(dfs, 1) to start the depth-first search from the number 1.
                              Finally, when the search is complete, the ans vector containing the lexicographically ordered numbers is returned.*/
            {
                self(self, cur + 1);
            }
        };
        dfs(dfs, 1);
        return ans;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> result = solution.lexicalOrder(n);

    cout << "Lexicographical order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}