public class Solution {
    static final int MOD = 1000000007;

    public static int numWays(String[] words, String target) {
        int n = words.length;
        int wordLen = words[0].length();
        int targetLen = target.length();
        
        // dp[i][j] represents number of ways to form first i characters of target using first j positions in each word
        long[][] dp = new long[targetLen + 1][wordLen + 1];
        
        // Initialize dp[0][*] to 1 since there's one way to form an empty target
        for (int j = 0; j <= wordLen; j++) {
            dp[0][j] = 1;
        }
        
        // Precompute character frequencies at each position in words
        int[][] charCount = new int[wordLen][26]; // There are 26 letters in the English alphabet
        for (String word : words) {
            for (int j = 0; j < wordLen; j++) {
                charCount[j][word.charAt(j) - 'a']++;
            }
        }
        
        // Fill the dp array
        for (int i = 1; i <= targetLen; i++) {
            char tChar = target.charAt(i - 1);
            for (int j = 1; j <= wordLen; j++) {
                // Carry forward the previous value
                dp[i][j] = dp[i][j - 1];
                
                // Update dp[i][j] considering new positions where tChar can be taken from
                int charIndex = tChar - 'a';
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * charCount[j - 1][charIndex]) % MOD;
            }
        }
        
        // The answer is in dp[targetLen][wordLen]
        return (int) dp[targetLen][wordLen];
    }

 
}