/*Ciprian Alex Cornila
ECE 4122
10/06/2019
*/

#include <iostream>
#include <limits.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include<math.h>
#include <algorithm>
#include <vector>
#include <chrono>
//#include <omp.h>
#include <thread>

//using std threads //using single thread

//using std::atomic;
//using std::chrono::high_resolution_clock;
//using std::chrono::duration_cast;
//using std::chrono::milliseconds;


//computes the factorial of r where r = row index
 long long int  fact(long long int r)
{
    long long int res = 1;
    for (long long int i = 2; i <= r; i++)
        res = res * i;
    return res;
}

//takes the number of combinations of r in n
//where r and n represent the indices of the bottom square
long long int nCr(long long int r, long long int n)
{
    //simplify common elements in the numerator and denominator
    //to reduce computation and avoid overflow
      long long int N = n;
      long long int R = r;
      int  i=0;
      long long int res=1;
      if (N < R/2)
      N = R - N;
      for(i = 0; i < N; i++)
      {
        res *= (R-i);
        res /= (i+1);
      }
      //output res
      return res;
}


//single thread running faster than omp thread
int main(int argc, char* argv[])
{

  //pragma omp parallel num_threads(1)
  //{
     //number of rows and columns as comand line arguments
   long long int r = std::stoi(argv[2]);
   long long int n = std::stoi(argv[4]);
   long long int a;
   int b;


   //turn matrix row and col lenghts into indices of desired value
   // col (n) stay the same row changes to row + col
   r = r + n;

   //combinations function  is called and its output is stored in out
  long long int out = nCr(r, n);

    //auto endTime = high_resolution_clock::now();
    //auto duration  = duration_cast<milliseconds>(endTime - startTime).count();
    //std::cout << "Execution time = " << duration << " ms" << std::endl;

    std::cout << "Number of Routes: "<< std::fixed << out << std::endl;

return 0;
 //}

}
