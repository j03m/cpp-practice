#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {

        while (!st.empty() && height[current] > height[st.top()]) {

            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            cout << "current: " << current << " d: " << distance << "\n";
            cout << "height (c): " << height[current] << " height (s): " << height[st.top()] << " height (o): " << height[top] << "\n";
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            cout << "bh: " << bounded_height << "\n";
            ans += distance * bounded_height;
            cout << "sub: " << ans << "\n";
        }
        st.push(current);
        current+=1;
    }
    return ans;
}


int main(){
    vector<int> height = {4,0,0,0,0,0,1};
    cout << trap(height);
}