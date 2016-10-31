/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Note: inspired by qw3rtman  on leetcode discussion

*/

class Solution {
public:
     int lengthOfLastWord(string s) {
        int length = s.length()-1;
        int count = 0;

        while(length>=0 && s[length]==' '){
            length--; //reduce the starting point to where a word appears
        }

        while(length>=0){
            if(s[length]==' ') break;
            else count++;
            
            length--;
        }

        return count;

    }

};


/*
 int lengthOfLastWord(string s) {
        int length = s.length();
        if(length==0) return 0;
        int count =0;
        int word_count=0;
        for(int i=length ; i>=0;i--){
            if(count>0){
                if(s[i]!=' ') break;
            }
            else{
                if(s[i]!='/0' && s[i]!=' ') count++;
            }
        }

        for(int x=(length-count);x>=0;x--){
            if(s[x]!=' ') word_count ++;
        }

        return word_count-count;


*/