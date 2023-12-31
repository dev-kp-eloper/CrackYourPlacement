//Link - https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?leftPanelTab=0


// int recursion(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
// {
//     if(day == 0){
//         int maxi = 0;
//         for(int task=0; task<3; task++){
//             if(task != last){
//                 maxi = max(maxi, points[0][task]);
//             }
//         }
//         return maxi;
//     }

//     if(dp[day][last] != -1) return dp[day][last];
    
//     int maxi = 0;
//     for(int task=0; task<3; task++){
//         if(task != last){
//             int point = points[day][task] + recursion(day-1,task,points,dp);
//             maxi = max(maxi, point);
//         }
//     }
//     return dp[day][last] = maxi;
// }

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(n, 0);
    
    prev[0] = max(points[0][1] , points[0][2]);
    prev[1] = max(points[0][0] , points[0][2]);
    prev[2] = max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][0] , max(points[0][1] , points[0][2]));
    
    for(int day=1; day<n; day++){
        vector<int> temp(4,0);
        for(int last=0; last<4; last++){
            temp[last] = 0;

            for(int task=0; task<3; task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];

}
