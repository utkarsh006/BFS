class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        queue<string> q;  //make a queue
        unordered_set<string> vis;  // make a visited data structure
        
        q.push(start);
        vis.insert(start);
        
        int count=0; //minimum mutations to return
        
            while(!q.empty())
            {
                int n = q.size();
                for(int i=0; i<n; i++)
                {
                    //take out the string from front of the queue
                    string node = q.front();
                    q.pop();
                    
                    //if its equal to the end, return count. No need of mutation
                    if(node==end) return count;
                    
                      //check each character "ACGT" in this string and make adjacent node
                    
                        for(char ch: "ACGT")
                        {   
                            for(int j=0; j<node.size(); j++)
                            {
                                string neighbour = node;
                                neighbour[j]=ch;
                                
                                //this neighbour should be unvisited and present in bank.
                                
                                if(!vis.count(neighbour) && 
                                 find(bank.begin(), bank.end(), neighbour) != bank.end())
                                {
                                    q.push(neighbour);
                                    vis.insert(neighbour);
                                }
                            }
                        }
                }
                count++;
            }
        
        return -1;
    }
};
