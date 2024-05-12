class Solution {
public:
    int compareVersion(string version1, string version2) {
      int i=0;
      int j=0;
      int n1=version1.size();
      int n2=version2.size();

      while(i<n1 || j<n2){
        int num1=0;
        int num2=0;

        while(i<n1 && version1[i] !='.'){
            while(i<n1 && num1==0 && version1[i]=='0'){ i++; }
            if(i<n1 && version1[i]=='.'){continue;}
            if(i<n1) { num1=num1*10+(int(version1[i])-48); i++; }
        }

        while(j<n2 && version2[j] !='.'){
            while(j<n2 && num2==0 && version2[j]=='0'){ j++; }
            if(j<n2 && version2[j]=='.'){continue;}
            if(j<n2) { num2=num2*10+(int(version2[j])-48); j++; }
        }

        if(i<n1 && version1[i]=='.')i++;
        if(j<n2 && version2[j]=='.')j++;
        cout<<num1<<" "<<num2<<endl;
        if(num1>num2)return 1;
        else if(num1<num2)return -1;
      }

      return 0;

    }
};