/*Given a string, sort it in decreasing order based on the frequency of characters.
 *
 *Example 1:
 *
 *Input:
 *"tree"
 *
 *Output:
 *"eert"
 *
 *Explanation:
 *'e' appears twice while 'r' and 't' both appear once.
 *So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 *Example 2: 
 *
 *Input:
 *"cccaaa"
 *
 *Output:
 *"cccaaa"
 *
 *Explanation:
 *Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 *Note that "cacaca" is incorrect, as the same characters must be together.
 *Example 3:
 *
 *Input:
 *"Aabb"
 *
 *Output:
 *"bbAa"
 *
 *Explanation:
 *"bbaA" is also a valid answer, but "Aabb" is incorrect.
 *Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> map1;
        map<char,int>::iterator p;
        string ret;
        for(char key:s) map1[key]++;
        int maxFre=0;
        while(!map1.empty()){
            for(auto it=map1.begin();it!=map1.end();it++){
                if(maxFre<it->second){
                    maxFre=it->second;
                    p=it;
                }
            }
            for(int i=0;i<maxFre;i++) ret.push_back(p->first);
            map1.erase(p);
            maxFre=0;
        }
        return ret;
    }
};
