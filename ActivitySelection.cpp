#include <bits/stdc++.h>
using namespace std;

vector<int> maxActivities(vector<int> &s, vector<int> &f)
{
    int n = s.size();

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = {f[i], i};
    }

    sort(arr.begin(), arr.end());

    vector<int> answer;

    int last = arr[0].first;
    answer.push_back(arr[0].second + 1);

    for (int i = 1; i < n; i++)
    {
        if (s[arr[i].second] >= last)
        {
            answer.push_back(arr[i].second + 1);
            last = arr[i].first;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> start;
    vector<int> end;

    for (int i = 0; i < n; i++)
    {
        int s_value;
        cin >> s_value;
        start.push_back(s_value);
    }

    for (int i = 0; i < n; i++)
    {
        int e_value;
        cin >> e_value;
        end.push_back(e_value);
    }

    vector<int> result = maxActivities(start, end);

    cout << "The maximum number of activities is: " << result.size() << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}