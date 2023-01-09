// goal --> the max number of trees he can get
// he has to maximise its all his minimum values that he is getting
// make a cut at every i ,j 
// compute s1,s2,s3,s4 for each iteration
// ultimate target -->track of max X
// the complexity of the algorithm is O(N^4)
// in 1 sec 10^8 instructions are followed , if N is lager say 1000 then N^4 is 10^12 . so TLE 

// so the idea is to use an 2D prefix sums
//M(i,j) =total number of trees from 0,0 to i,j
//M(i,j) = M(i-1,j)+M(i,j-1)-M(i-1,j-1) +1 // if tree at (i,j)
//M(i,j) = M(i-1,j)+M(i,j-1)-M(i-1,j-1) +0 // if no tree at (i,j)
//s1=M(i,j)
//s2=M(x,N)-M(x,y)
//s3=M(N,y)-M(x,y)
//s4=M(N,N)-s1-s2-s3