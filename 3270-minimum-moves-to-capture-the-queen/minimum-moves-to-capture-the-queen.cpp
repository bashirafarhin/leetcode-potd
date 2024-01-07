class Solution {
   int wr(int r, int c, int wbr, int wbc,int qr,int qc) {
    if (r == qr && c == qc) {
        return 0;}

    if (r == qr) {
        if(r==wbr &&  ( (c<wbc && wbc<qc) || ( qc<wbc && wbc<c) ) ){return 2;}
    
        return 1;}

    if(c==qc){
        if(c==wbc &&  ( (r<wbr && wbr<qr) || ( qr<wbr && wbr<r)  ) ){return 2;}
        
        return 1;}

    return 2;}



   int wb(int r, int c,int wrr,int wrc,int qr,int qc) {
    if (r == qr && c == qc) {
        return 0;}
        
    bool rook_present_in_path=false;
    int i=r;
    int j=c;
    while(i>0 && j>0){
      if(i==wrr && j==wrc){rook_present_in_path=true;}
      if(i==qr && j==qc){
          if(rook_present_in_path){return 2;}
          return 1;}
      
      i--;
      j--;
    }
    
    rook_present_in_path=false;
    i=r;
    j=c;
    while(i>0 && j<=8){
      if(i==wrr && j==wrc){rook_present_in_path=true;}
      if(i==qr && j==qc){
          if(rook_present_in_path){return 2;}
          return 1;}
      i--;
      j++;
    }
    
    rook_present_in_path=false;
    i=r;
    j=c;
    while(i<=8 && j<=8){
      if(i==wrr && j==wrc){rook_present_in_path=true;}
      if(i==qr && j==qc){
          if(rook_present_in_path){return 2;}
          return 1;}
      i++;
      j++;
    }

    rook_present_in_path=false;
    i=r;
    j=c;
    while(i<=8 && j>0){
      if(i==wrr && j==wrc){rook_present_in_path=true;}
      if(i==qr && j==qc){
          if(rook_present_in_path){return 2;}
          return 1;}
      i++;
      j--;
    }

    return 1e9;}

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
       
       return min( wr(a,b,c,d,e,f) , wb(c,d,a,b,e,f) ); 
    }
};