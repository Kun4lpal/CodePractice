// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// 7 7 6 5 5 4
// 5 7 5 6 4 7  

// first value is the size and second is the number of items ahead of it which are greater than lval

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people){
        auto comp = [](const pair<int, int>&p1, const pair<int, int>& p2) -> bool {                          
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(people.begin(), people.end(), comp);
	    vector<pair<int, int>> res;
	    for (auto&p : people)
            res.insert(res.begin() + p.second, p);
	    return res;
}