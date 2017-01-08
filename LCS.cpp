#include<iostream>
#include<cstring>
#include<cstdlib>

void LCS(char *ip1, char *ip2, int n1, int n2)
{
    int mat[n1+1][n2+1];

    for(int i = 0; i < n1+1 ;i++)
    {    for(int j = 0; j < n2+1 ;j++)
         {
			if( i == 0 || j == 0)
            	mat[i][j] = 0;
			else if( ip1[i -1] == ip2[j -1] )
                mat[i][j] = mat[i-1][j-1] +1;
            else
                mat[i][j] = std::max (mat[i-1][j], mat[i][j-1]);
         }   
    }
    // debug print
    /*
	for(int i = 0; i < n1+1 ;i++)
    {    for(int j = 0; j < n2+1 ;j++)
            std::cout<<mat[i][j]<<" ";
        std::cout<<std::endl;
    }
	*/
   int index = mat[n1][n2];
 
   char lcs[index+1];
   lcs[index] = '\0'; 
   
   int i = n1, j = n2;
   while (i > 0 && j > 0)
   {
      if (ip1[i-1] == ip2[j-1])
      {
          lcs[index-1] = ip1[i-1]; 
          i--; 
		  j--; 
          index--;  
      }
 
      else if (mat[i-1][j] > mat[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   std::cout << "LCS is: "<<lcs;             
                
}

int main()
{
  char ip1[] = "mzjawxu";
  char ip2[] = "xmjyauz";
  int m = strlen(ip1);
  int n = strlen(ip2);
  LCS(ip1, ip2, m, n);   
 return 0;
}
