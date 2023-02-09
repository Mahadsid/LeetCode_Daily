// // You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

// // Choose 2 distinct names from ideas, call them ideaA and ideaB.
// // Swap the first letters of ideaA and ideaB with each other.
// // If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
// // Otherwise, it is not a valid name.
// // Return the number of distinct valid names for the company.

// // Example 1:

// // Input: ideas = ["coffee","donuts","time","toffee"]
// // Output: 6
// // Explanation: The following selections are valid:
// // - ("coffee", "donuts"): The company name created is "doffee conuts".
// // - ("donuts", "coffee"): The company name created is "conuts doffee".
// // - ("donuts", "time"): The company name created is "tonuts dime".
// // - ("donuts", "toffee"): The company name created is "tonuts doffee".
// // - ("time", "donuts"): The company name created is "dime tonuts".
// // - ("toffee", "donuts"): The company name created is "doffee tonuts".
// // Therefore, there are a total of 6 distinct company names.

// // The following are some examples of invalid selections:
// // - ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
// // - ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
// // - ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
// Intuition :
// Here we are counting the number of distinct pairs of names, where two names are considered distinct if they have different initial characters or different suffixes (the part after the first character).
// Explanation to Approach :
// First group the names by their first characters, and then for each pair of groups, count the number of distinct pairs that can be formed between them.
// Now compute the number of common suffixes between the two groups, and then subtracting that from the total number of pairs that can be formed between the two groups.
// Add the result to the overall answer.
// Use a Set[] array named "suffixes" to store the suffixes for each group of names, with one Set for each of the 26 possible initial characters (a-z).
// The suffix for a name is computed as the substring of the name starting from the second character.
// Finally, return the value of the "ans" variable, which holds the total number of distinct pairs of names.
// Complexity
// Time complexity : O(n)+O(26^2)
// Space complexity : O(n)
class Solution
{
    public:
        long long distinctNames(vector<string> &ideas) {
            long long ans = 0;

            // Group strings by initials
            unordered_set<string> suffixes[26];

            for (const string &idea : ideas)
                suffixes[idea[0] - 'a'].insert(idea.substr(1));

            for (int i = 0; i < 25; ++i)
                for (int j = i + 1; j < 26; ++j) {
                    int count = 0;
                    for (const string &suffix : suffixes[i])
                        if (suffixes[j].count(suffix))
                            ++count;
                    ans += 2 * (suffixes[i].size() - count) * (suffixes[j].size() - count);
                }
            return ans;
        }
};
