class Solution {
    vector<vector<int>>t;
    int dp(vector<vector<int>>& books,int i, int &shelfWidth,int currW,int maxheight){
        if(i==books.size())return maxheight;
        if(t[i][currW]!=-1)return t[i][currW];
        int next=INT_MAX,shelf=INT_MAX;
        if(currW>=books[i][0]){
            shelf = dp(books, i + 1,shelfWidth, currW - books[i][0], 
							  max(maxheight, books[i][1]));
        }
        next = maxheight + dp(books, i + 1,shelfWidth, shelfWidth - books[i][0], 
										   books[i][1]);
        return t[i][currW]=min(next,shelf);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        t.resize(1001, vector<int> (shelfWidth + 1, -1));
        return dp(books,0,shelfWidth,shelfWidth,0);
    }
};