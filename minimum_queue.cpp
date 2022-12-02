//  Queue Modification - To find smallest/largest element in o(1).
//  queue first element will be smallest, so keep deleting all greater elements from queue.

// while (!q.empty() && q.back() > new_element)
//     q.pop_back();
// q.push_back(new_element);

Consider an - integer sequence, .We perform a query on by using an integer, , to calculate the result of the following expression :

    In other words,
    if we let,
    then you need to calculate.

    Given and queries,
    return a list of answers to each query.

               sol -
           >

           vector<int> solve(vector<int> arr, vector<int> queries)
{
    // sliding window of size queries[0]
    // find max in those winfows and each time have a min check on them
    vector<int> result;
    for (int i = 0; i < queries.size(); i++)
    {
        int k = queries[i];
        deque<int> dq;
        int ans = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            while (dq.empty() != true && arr[i] > arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for (int i = k; i < arr.size(); i++)
        {
            ans = min(ans, arr[dq.front()]);
            while (dq.empty() != true && dq.front() <= i - k)
                dq.pop_front();
            while (dq.empty() != true && arr[i] >= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans = min(ans, arr[dq.front()]);
        result.push_back(ans);
    }
    return result;
}