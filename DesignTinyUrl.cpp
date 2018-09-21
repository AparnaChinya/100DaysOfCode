/*
535. Encode and Decode TinyURL
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

From <https://leetcode.com/problems/encode-and-decode-tinyurl/description/>
*/
class Solution {
public:
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string,string> myMap;
    string key = getRand();
    string URL = "http://tinyurl.com/";

    string getRand() {
        string result = "";
        for(int i = 0; i < 6; i++) {
            result += alphabet[rand() % alphabet.size()];
        }
        //cout << result;
        return result;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(myMap.find(key) != myMap.end()) {
            key = getRand();
        }
        myMap[key] = longUrl;
        //cout << URL + key;
        return URL + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        key = shortUrl.substr(URL.size(),URL.size()-1);
        cout << key;
        return myMap[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

