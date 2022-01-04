// Question: Find total number of Squares in a N*N chessboard

int number_of_squares(int n)
{
  return n*(n+1)*(2*n+1)/6;   // Total number of squares in n*n chessboard = summation(n^2)
}
