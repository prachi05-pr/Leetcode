class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int h = n / 2;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // Check whether a palindrome is possible
        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Frequency of characters available for the left half
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        // Make palindrome from a half
        auto makePalindrome = [&](string half) {
            string right = half;
            reverse(right.begin(), right.end());

            if (mid != '#')
                return half + string(1, mid) + right;

            return half + right;
        };

        /*
            First check if the smallest possible palindrome
            is already greater than target.
        */
        string smallestHalf = "";

        for (int c = 0; c < 26; c++)
            smallestHalf += string(halfFreq[c], 'a' + c);

        string smallest = makePalindrome(smallestHalf);

        if (smallest > target)
            return smallest;

        /*
            We now need the smallest half which is
            lexicographically greater than target[0:h].

            Example:

            target half = "bababababa"

            We try to match target from left to right.
            At some position i, we make our character
            slightly larger, then put the remaining
            characters in sorted order.
        */

        vector<int> prefix(26, 0);

        string answer = "";

        for (int i = 0; i < h; i++) {

            // Check whether target[0...i-1] can be formed
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (prefix[c] > halfFreq[c]) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                break;

            // Characters remaining after matching prefix
            vector<int> remaining = halfFreq;

            for (int c = 0; c < 26; c++)
                remaining[c] -= prefix[c];

            // At position i, choose smallest character
            // strictly greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (remaining[c] == 0)
                    continue;

                string half = target.substr(0, i);

                half += char('a' + c);

                remaining[c]--;

                // Fill rest in smallest possible order
                for (int x = 0; x < 26; x++)
                    half += string(remaining[x], 'a' + x);

                string candidate = makePalindrome(half);

                if (candidate > target) {
                    if (answer.empty() || candidate < answer)
                        answer = candidate;
                }

                remaining[c]++;
            }

            // Match target[i] and continue
            int c = target[i] - 'a';

            if (prefix[c] == halfFreq[c])
                break;

            prefix[c]++;
        }

        /*
            Special case:
            The first half can be exactly equal to target's
            first half.

            The palindrome may still be greater than target
            because of its right half.
        */

        bool canEqual = true;

        for (int c = 0; c < 26; c++) {
            if (prefix[c] != halfFreq[c]) {
                canEqual = false;
                break;
            }
        }

        if (canEqual) {
            string half = target.substr(0, h);

            string candidate = makePalindrome(half);

            if (candidate > target) {
                if (answer.empty() || candidate < answer)
                    answer = candidate;
            }
        }

        return answer;
    }
};