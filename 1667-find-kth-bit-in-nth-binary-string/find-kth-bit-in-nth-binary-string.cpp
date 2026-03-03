class Solution {
public:

    string invert(string s){
        for(int i=0;i<s.length();i++){
            s[i] = s[i] == '0' ? '1' : '0';
        }
        return s;
    }

    string nthBinarystring(int n){
        if(n==0){ return "0"; }
        string Binarystring = nthBinarystring(n-1);
        string iandr = invert(Binarystring);
        reverse(iandr.begin(), iandr.end());
        return Binarystring + "1" + iandr;
    }

    char findKthBit(int n, int k) {
        string s = nthBinarystring(n);
        return s[k-1];
    }
};