#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Leaderboard.h"
#include "GameSession.h"
#include "FPSSession.h"
#include "StrategySession.h"
#include "PuzzleSession.h"

using namespace std;

// Template sorting functions
template <class T>
void sortByRating(Leaderboard<T>& board) {
    for (int i = 0; i < board.size() - 1; i++) {
        for (int j = i + 1; j < board.size(); j++) {
            if ((*board[j]).calculateRating() > (*board[i]).calculateRating()) {
                T temp = board[i];
                board[i] = board[j];
                board[j] = temp;
            }
        }
    }
}

template <class T>
void sortByScore(Leaderboard<T>& board) {
    for (int i = 0; i < board.size() - 1; i++) {
        for (int j = i + 1; j < board.size(); j++) {
            if (*board[j] > *board[i]) {
                T temp = board[i];
                board[i] = board[j];
                board[j] = temp;
            }
        }
    }
}

int main() {
    Leaderboard<GameSession*> leaderboard;
    ifstream fin("sessions.txt");
    
    // Error handling: file doesn't exist
    if (!fin.is_open()) {
        cerr << "Error: Cannot open sessions.log" << endl;
        return 1;
    }
    
    string line;
    int lineNumber = 0;
    
    // Read from file
    cout << "=== READING SESSIONS FROM FILE ===" << endl;
    while (getline(fin, line)) {
        lineNumber++;
        
        // Skip empty lines
        if (line.empty()) continue;
        
        istringstream iss(line);
        string type;
        iss >> type;
        
        GameSession* session = nullptr;
        
        // Create correct derived object based on type
        if (type == "FPS") {
            session = new FPSSession();
        }
        else if (type == "STRATEGY") {
            session = new StrategySession();
        }
        else if (type == "PUZZLE") {
            session = new PuzzleSession();
        }
        else {
            cerr << "Warning: Unknown game type '" << type << "' at line " << lineNumber << endl;
            continue;
        }
        
        // Try to read the session data
        try {
            iss >> *session;
            
            // Check for duplicates
            if (leaderboard.contains(session)) {
                cerr << "Warning: Duplicate session (player " << session->getPlayerID() 
                     << ") at line " << lineNumber << " — skipped" << endl;
                delete session;
                continue;
            }
            
            leaderboard.insert(session);
            cout << "✓ Loaded session from line " << lineNumber << endl;
        }
        catch (const exception& e) {
            cerr << "Warning: Malformed data at line " << lineNumber << " (" 
                 << e.what() << ") — skipped" << endl;
            delete session;
        }
    }
    
    fin.close();
    cout << "Total sessions loaded: " << leaderboard.size() << endl << endl;
    
    if (leaderboard.size() == 0) {
        cout << "No sessions to process." << endl;
        return 0;
    }
    
    // Display all sessions before sorting
    cout << "=== ALL SESSIONS (BEFORE SORTING) ===" << endl;
    for (int i = 0; i < leaderboard.size(); i++) {
        cout << "Session " << i + 1 << ":\n" << *leaderboard[i] << endl;
    }
    cout << endl;
    
    // Display each session's calculated rating
    cout << "=== RATINGS FOR EACH SESSION ===" << endl;
    for (int i = 0; i < leaderboard.size(); i++) {
        cout << "Session " << i + 1 << " (" << leaderboard[i]->getGameType() << "): "
             << fixed << setprecision(2) << leaderboard[i]->calculateRating() << " rating" << endl;
    }
    cout << endl;
    
    // Count sessions by game type
    cout << "=== SESSIONS BY GAME TYPE ===" << endl;
    int fpsCount = 0, strategyCount = 0, puzzleCount = 0;
    for (int i = 0; i < leaderboard.size(); i++) {
        string type = leaderboard[i]->getGameType();
        if (type == "FPS") fpsCount++;
        else if (type == "STRATEGY") strategyCount++;
        else if (type == "PUZZLE") puzzleCount++;
    }
    cout << "FPS: " << fpsCount << endl;
    cout << "STRATEGY: " << strategyCount << endl;
    cout << "PUZZLE: " << puzzleCount << endl << endl;
    
    // Sort by score descending, display top 5
    cout << "=== TOP 5 BY SCORE ===" << endl;
    sortByScore(leaderboard);
    int topCount = (leaderboard.size() < 5) ? leaderboard.size() : 5;
    for (int i = 0; i < topCount; i++) {
        cout << "Rank " << i + 1 << ": " << *leaderboard[i] << endl;
    }
    cout << endl;
    
    // Re-sort by rating descending, display top 3
    cout << "=== TOP 3 BY RATING ===" << endl;
    sortByRating(leaderboard);
    int topRatingCount = (leaderboard.size() < 3) ? leaderboard.size() : 3;
    for (int i = 0; i < topRatingCount; i++) {
        cout << "Rank " << i + 1 << ": Rating " << fixed << setprecision(2) 
             << leaderboard[i]->calculateRating() << "\n"
             << *leaderboard[i] << endl;
    }
    cout << endl;
    
    // Demonstrate operator[]
    cout << "=== OPERATOR[] DEMONSTRATION ===" << endl;
    if (leaderboard.size() >= 2) {
        cout << "Session at index 1 (2nd session):\n" << *leaderboard[1] << endl << endl;
    }
    
    // Demonstrate find()
    cout << "=== FIND() DEMONSTRATION ===" << endl;
    string searchPlayer = "player_001";
    int foundIndex = leaderboard.find(searchPlayer);
    if (foundIndex != -1) {
        cout << "Found '" << searchPlayer << "' at index " << foundIndex << ":\n"
             << *leaderboard[foundIndex] << endl;
    }
    else {
        cout << "Player '" << searchPlayer << "' not found in leaderboard." << endl;
    }
    cout << endl;
    
    // Demonstrate removeAt()
    cout << "=== REMOVEAT() DEMONSTRATION ===" << endl;
    cout << "Leaderboard size before removal: " << leaderboard.size() << endl;
    if (leaderboard.size() > 0) {
        cout << "Removing session at index 0..." << endl;
        leaderboard.removeAt(0);
        cout << "Leaderboard size after removal: " << leaderboard.size() << endl << endl;
    }
    
    // Display final leaderboard
    cout << "=== FINAL LEADERBOARD ===" << endl;
    for (int i = 0; i < leaderboard.size(); i++) {
        cout << "Session " << i + 1 << ":\n" << *leaderboard[i] << endl;
    }
    cout << endl;
    
    cout << "Final leaderboard size: " << leaderboard.size() << endl << endl;
    
    // Cleanup: delete all dynamically allocated sessions
    cout << "=== CLEANUP ===" << endl;
    for (int i = 0; i < leaderboard.size(); i++) {
        delete leaderboard[i];
    }
    cout << "All sessions deleted." << endl;
    
    return 0;
}
