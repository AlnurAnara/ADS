#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator> // Required for std::inserter
using namespace std;

void solve_plagiarism_optimized_final() {
    string s1, s2, t;
    // Set up fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> s1 >> s2 >> t)) return;
    if (t.length() > s1.length() || t.length() > s2.length()) {
        cout << 0 << "\n";
        return; 
    }

    // A constant to represent "not found"
    const size_t not_found = string::npos;
    
    // Vectors to store the starting indices of the parasite word in each string.
    // The find operation naturally populates these in sorted order.
    vector<int> positions_s1;
    vector<int> positions_s2;

    // --- Helper function to find all (overlapping) occurrences ---
    auto find_all_occurrences = [&](const string& text, const std::string& pattern, std::vector<int>& results) {
        size_t current_pos = text.find(pattern, 0); // Start searching from index 0

        while (current_pos != not_found) {
            results.push_back((int)current_pos); 
            
            // Crucial step for finding OVERLAPPING matches:
            // The next search must begin one position *after* the current match began.
            // If we shifted by pattern.length(), we would miss overlaps.
            current_pos = text.find(pattern, current_pos + 1); 
        }
    };

    // 2. Populate the position vectors using the highly optimized string::find.
    find_all_occurrences(s1, t, positions_s1);
    find_all_occurrences(s2, t, positions_s2);

    // 3. Find the number of common positions using a sorted intersection algorithm.
    // std::set_intersection is designed to work efficiently (linear time in the size
    // of the inputs) on two sorted ranges (our vectors are sorted).
    
    // A temporary vector to hold the common positions (the intersection).
    vector<int> common_positions;

    // std::set_intersection requires the vectors to be sorted, which they are.
    // It finds all elements present in both input ranges and writes them to the output.
    set_intersection(
        positions_s1.begin(), positions_s1.end(),
        positions_s2.begin(), positions_s2.end(),
        back_inserter(common_positions) // Inserts the common elements into our result vector
    );

    // 4. The result is the size of the intersection vector.
    // If the input vectors are of length M and N, set_intersection runs in O(M + N).
    cout << common_positions.size() << "\n";
}

int main() {
    solve_plagiarism_optimized_final();
    return 0;
}