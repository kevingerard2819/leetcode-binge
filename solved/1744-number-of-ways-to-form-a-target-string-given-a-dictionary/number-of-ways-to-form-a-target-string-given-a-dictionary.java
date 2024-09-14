public class Solution {
    static final int MOD = 1000000007;

    public static int numWays(String[] words, String target) {
        int n = words.length;
        int wordLen = words[0].length();
        int targetLen = target.length();
    
        long[][] dp = new long[targetLen + 1][wordLen + 1];
        
        for (int j = 0; j <= wordLen; j++) {
            dp[0][j] = 1;
        }

        int[][] charCount = new int[wordLen][26]; // There are 26 letters in the English alphabet
        for (String word : words) {
            for (int j = 0; j < wordLen; j++) {
                charCount[j][word.charAt(j) - 'a']++;
            }
        }
 
        for (int i = 1; i <= targetLen; i++) {
            char tChar = target.charAt(i - 1);
            for (int j = 1; j <= wordLen; j++) {

                dp[i][j] = dp[i][j - 1];
                

                int charIndex = tChar - 'a';
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * charCount[j - 1][charIndex]) % MOD;
            }
        }
        

        return (int) dp[targetLen][wordLen];
    }

 
}