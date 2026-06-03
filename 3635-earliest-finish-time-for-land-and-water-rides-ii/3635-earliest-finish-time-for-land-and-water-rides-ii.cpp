class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long minA = LLONG_MAX; // earliest land finish
        for (int i = 0; i < n; i++) {
            minA = min(minA,
                       (long long)landStartTime[i] + landDuration[i]);
        }

        long long landFirst = LLONG_MAX;
        for (int j = 0; j < m; j++) {
            landFirst = min(
                landFirst,
                max((long long)waterStartTime[j], minA)
                    + waterDuration[j]
            );
        }

        long long minB = LLONG_MAX; // earliest water finish
        for (int j = 0; j < m; j++) {
            minB = min(minB,
                       (long long)waterStartTime[j] + waterDuration[j]);
        }

        long long waterFirst = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            waterFirst = min(
                waterFirst,
                max((long long)landStartTime[i], minB)
                    + landDuration[i]
            );
        }

        return (int)min(landFirst, waterFirst);
    }
};