/*

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0

*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        int hourHand = (hour % 12) * 30;
        double minHand = ( (double) minutes/60) * 30;
        double hourAngle = hourHand + minHand;
        
        double minAngle = ((double) minutes/5) * 30;
        
        double angle = abs(minAngle - hourAngle);
        
        return angle <= 180 ? angle : 360 - angle;
        
    }
};