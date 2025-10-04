class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int firstPoint=0;
        int lastPoint=height.size()-1;

        while(firstPoint<lastPoint){
            int minHeight=min(height[firstPoint],height[lastPoint]);
            int width=lastPoint-firstPoint;
            int area=minHeight*width;
            maxArea=max(maxArea,area);
            if(height[firstPoint]<=height[lastPoint]){
                firstPoint++;
            }else{
                lastPoint--;
            }
        }
        return maxArea;
    }
};