#if !defined(IMAGE_SMOOTHER_H)

#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>>
    imageSmoother(vector<vector<int>> &img)
    {
        vector<vector<int>> result = img;
        int m = img.size();
        int n = img[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int sum = 0;
                int count = 0;
                for (int gI = -1; gI <= 1; ++gI)
                {
                    int xIndex = (i + gI);
                    if (xIndex < 0 || xIndex >= m) { continue; }
                    for (int gJ = -1; gJ <= 1; ++gJ)
                    {
                        int yIndex = (j + gJ);
                        if (yIndex < 0 || yIndex >= n) { continue; }
                        sum += img[xIndex][yIndex];
                        ++count;
                    }
                }

                int avg = (int)(floorf(sum / count));
                result[i][j] = avg;
            }
        }

        return result;
    }

    void
    driver()
    {
        vector<vector<int>> img{};
        vector<int> r0 = {100, 200, 100};
        vector<int> r1 = {200, 50, 200};
        vector<int> r2 = {100, 200, 100};
        img.push_back(r0);
        img.push_back(r1);
        img.push_back(r2);
        int m = img.size();
        int n = img[0].size();

        Solution sol{};
        auto r = sol.imageSmoother(img);
    }
};

#define IMAGE_SMOOTHER_H
#endif // IMAGE_SMOOTHER_H