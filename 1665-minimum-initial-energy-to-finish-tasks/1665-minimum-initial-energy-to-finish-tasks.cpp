class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks by the difference between actual effort and minimum effort (ascending)
        // This ensures we do tasks with smaller "effort buffer" first
        sort(tasks.begin(), tasks.end(), [](const auto& taskA, const auto& taskB) { 
            return taskA[0] - taskA[1] < taskB[0] - taskB[1]; 
        });
      
        int totalEffortNeeded = 0;  // Total initial effort required
        int currentEffort = 0;      // Current available effort
      
        // Process each task in sorted order
        for (auto& task : tasks) {
            int actualEffort = task[0];   // Effort consumed by this task
            int minimumEffort = task[1];  // Minimum effort required to start this task
          
            // If current effort is less than minimum required, add the difference
            if (currentEffort < minimumEffort) {
                totalEffortNeeded += minimumEffort - currentEffort;
                currentEffort = minimumEffort;
            }
          
            // Consume the actual effort for this task
            currentEffort -= actualEffort;
        }
      
        return totalEffortNeeded;
    }
};