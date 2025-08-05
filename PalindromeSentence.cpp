class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
         
        int i=0,j=s.size()-1;
        while(i < j)
        {
            while (i < j && !isalnum(s[i]))
            i++;
            while (i < j && !isalnum(s[j]))
                j--;
            char fir=s[i];
            char sec=s[j];
            if(fir >='A' && fir <='Z')
                fir=tolower(fir);
            if(sec >='A' && sec <='Z')
                sec=tolower(sec);
            if(fir != sec) return false;    
            i++;j--;
    }
};
