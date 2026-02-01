#include <iostream>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {

    if(s1.length() > s2.length()) return false;

    int freq[26] = {0};

    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int left = 0, right = 0, needed = s1.length();

    while(right < s2.length()) {

        if(freq[s2[right] - 'a'] > 0) {
            needed--;
        }

        freq[s2[right] - 'a']--;
        right++;

        if(right - left > s1.length()) {

            if(freq[s2[left] - 'a'] >= 0) {
                needed++;
            }

            freq[s2[left] - 'a']++;
            left++;
        }

        if(needed == 0) return true;
    }

    return false;
}

int main() {
    string s1, s2;

    cout << "Enter s1 = ";
    cin >> s1;

    cout << "Enter s2 = ";
    cin >> s2;

    if(checkInclusion(s1, s2))
        cout << "Permutation exists ";
    else
        cout << "Permutation NOT found ";

    return 0;
}
