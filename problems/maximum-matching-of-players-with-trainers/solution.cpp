class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int match = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        for(int train : trainers){
            if(match < players.size() && train >= players[match])
                match++;
        }
        return match;
    }
};