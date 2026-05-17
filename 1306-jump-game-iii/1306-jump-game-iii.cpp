class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Use BFS to explore all reachable positions
        queue<int> bfsQueue{{start}};
      
        while (!bfsQueue.empty()) {
            // Get the current index from the queue
            int currentIndex = bfsQueue.front();
            bfsQueue.pop();
          
            // Check if we've reached a position with value 0 (target)
            if (arr[currentIndex] == 0) {
                return true;
            }
          
            // Store the jump distance before marking as visited
            int jumpDistance = arr[currentIndex];
          
            // Mark current position as visited by setting it to -1
            arr[currentIndex] = -1;
          
            // Calculate the two possible next positions (forward and backward jumps)
            vector<int> nextPositions = {currentIndex + jumpDistance, currentIndex - jumpDistance};
          
            for (int nextIndex : nextPositions) {
                // Check if the next position is within bounds and not visited
                // ~arr[nextIndex] checks if arr[nextIndex] != -1 (bitwise NOT of -1 is 0)
                if (nextIndex >= 0 && nextIndex < arr.size() && arr[nextIndex] != -1) {
                    bfsQueue.push(nextIndex);
                }
            }
        }
      
        // No path to a position with value 0 was found
        return false;
    }
};