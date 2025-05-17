#include <iostream>
#include <vector>


using namespace std;

//Luu ket qua
struct Result {
    int r1, c1, r2, c2, maxSum;
};

Result findMaxSumRectangle(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int maxSum = INT_MIN; // max sum
    int finalLeft, finalRight, finalTop, finalBottom; //toa do hinh chu nhat 


    //duyet tat ca bien trai pu hop truoc tien
    for (int left = 0; left < n; left++) {
        vector<int> temp(m, 0);
        

        // Duyet tat ca bien phai truoc tien 
        for (int right = left; right < n; right++) {
            for (int i = 0; i < m; i++)
                temp[i] += matrix[i][right];
            
            int sum = 0, startRow = 0;
            int localTop = 0, localBottom = 0;
            int bestSum = INT_MIN;


            //Thuat toan Kadane
            for (int i = 0; i < m; i++) {
                sum += temp[i];
                if (sum > bestSum) {
                    bestSum = sum;
                    localTop = startRow;
                    localBottom = i;
                }

                //Reset neu no bi am
                if (sum < 0) {
                    sum = 0;
                    startRow = i + 1;
                }
            }

            //Max sum moi neu tim duoc cai lon hon 
            if (bestSum > maxSum) {
                maxSum = bestSum;
                finalLeft = left;
                finalRight = right;
                finalTop = localTop;
                finalBottom = localBottom;
            }
        }
    }

    return {finalTop + 1, finalLeft + 1, finalBottom + 1, finalRight + 1, maxSum};
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    Result res = findMaxSumRectangle(matrix);

    cout << res.r1 << " " << res.c1 << " " << res.r2 << " " << res.c2 << " " << res.maxSum << endl;
    return 0;
}
