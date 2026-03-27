vector<int> prev(n + 1), next(n + 1);
    stack<int> st;
 
    {
        st.push(n + 1);
        for (int i = n; i >= 1; i--) {
            while (st.top() != n + 1 && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
    }
    {
        st.push(0);
        for (int i = 1; i <= n; i++) {
            while (st.top() != 0 && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
    }