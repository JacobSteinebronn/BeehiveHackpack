/**
 * Author: Jacob Steinebronn
 * Date: 2020-10-26
 * License: CC0
 * Description: Angular Sort with Cross-product
 * Time: O(N\log N)
 * Status: Works, but not stress-tested
 */
#pragma once

sort(pts.begin(), pts.end(), [](const P& p1, const P& p2)->bool{
  int s1 = p1.y < 0 || (p1.y == 0 && p1.x < 0); 
  int s2 = p2.y < 0 || (p2.y == 0 && p2.x < 0);
  if(s1 != s2) return s1 < s2;
  return p1.cross(p2) > 0; 
});