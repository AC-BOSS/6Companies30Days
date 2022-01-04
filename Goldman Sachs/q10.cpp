// Question: Find max 10 numbers in a list having 10M entries.

vector<int> max_10_numbers(vector<int>arr)
{
  priority_queue<int,vector<int>, greater<int> >pq; 
  for(auto i:arr)
  {
    if(pq.size() < 10)
      pq.push(i);
    else
    {
      int top = pq.top();
      if(i > top)
      {
        pq.pop();
        pq.push(i);
      }
    }
}
