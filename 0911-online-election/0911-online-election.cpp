/*
EXPLANATION OF PROBLEM STATEMENT
persons[] : [0,1,1,0,0,1,0]
times[] : [0,5,10,15,20,25,30]

in the above, '0' and '1' are the candidates participating in the election. At each time stamp in times[] array, we know which candidate received a vote based on persons[] array. In common words to put,

at time '0', some citizen casted a vote to candidate '0' ---> 0 is the leader now.
at time '5', some citizen casted a vote to candidate '1' ---> 1 is the leader as most recent candidate wins
at time 10, some other citizen casted a vote to candidate '1' ----> 1 is the leader as he got 2 votes
at time 15, some citizen casted a vote to candidate 0, ----> 0 is the leader as both have two votes each, however most recent wins
at time 20, some citizen casted a vote to candidate 0, ---> 0 is the leader as 0 has 3votes and 1 has 2 votes.

*/

/*
The vector inside constructor holds the count of votes of each person
currentMax will always hold which person is leading at any point of time, so that we can compare only with him
After every iteration update the map with time and current leading person ,so that we can refer to the map at later point of time

class TopVotedCandidate {
   map<int,int> mymap;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int currentMax = persons[0];
        vector<int> voteCount(persons.size(),-1);
        for(int i=0; i<persons.size(); ++i) {
            voteCount[persons[i]]++;
            if(voteCount[persons[i]] >= voteCount[currentMax])
                currentMax = persons[i];
            mymap[times[i]] = currentMax;
        }
    }
    int q(int t) {
        auto low = mymap.lower_bound(t);
        if(low->first != t) low--;
        return low->second;
    }
};
*/
class TopVotedCandidate {
public:
    
    map<int,int> mp;//ordered as we want leader in terms of sorted time in asc order
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = times.size();
        
        vector<int> voteCount(n , 0);
        int leader = persons[0];
        
        for(int i = 0 ; i < n ; i++){
            voteCount[persons[i]]++;
            if(voteCount[persons[i]] >= voteCount[leader]){
                leader = persons[i];
            }
             mp[times[i]] = leader;
        }
    }
    
    int q(int t) {
        auto low = mp.lower_bound(t);
        if(low->first != t) low--;
        return low->second;
        
        //REASON FOR THIS LOW--
        /*
        map_name.lower_bound(key)
Parameters: This function accepts a single mandatory parameter key which specifies the element whose lower_bound is to be returned.
Return Value: The function returns an iterator pointing to the key in the map container which is equivalent to k passed in the parameter. In case k is not present in the map container, the function returns an iterator pointing to the immediate next element which is just greater than k.
        */
    }
};

