package lcode.w44;
// https://leetcode.com/contest/biweekly-contest-44/problems/decode-xored-permutation/
class Solution1734 {
    public int[] decode(int[] encoded) {
        int sum = 0;
        for (int i = 0; i <= encoded.length; i++) {
            sum ^= i+1; 
        }
        int all = 0;
        for (int i = 0; i < encoded.length ; i++) {
            all ^= encoded[i]; 
        }
        int middle = all ^ sum;
        for(int i = 1, j = encoded.length-2; i < j;i += 2, j -= 2){
            middle ^= encoded[i]^encoded[j];
        }
      
        int[] res = new int[encoded.length + 1];
        res[encoded.length / 2] = middle;
        
        for (int i = encoded.length / 2 - 1; i >= 0; i--) {
            res[i] = res[i + 1] ^ encoded[i];
        }
        
        for (int i = encoded.length / 2 + 1; i <= encoded.length; i++) {
            res[i] = res[i - 1] ^ encoded[i-1];
        }
        
        return res;
    }
}
