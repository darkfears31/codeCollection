
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class GameMachine;

class State {
public:
    virtual ~State() = default;

    virtual void insertCoin() = 0;
    virtual void ejectCoin() = 0;
    virtual bool chooseGame() = 0;
    virtual void dispenseGame() = 0;
};

class NoCoinState : public State {
private:
    GameMachine* machine;

public:
    NoCoinState(GameMachine* m);

    void insertCoin() override;
    void ejectCoin() override;
    bool chooseGame() override;
    void dispenseGame() override;
};

class HasCoinState : public State {
private:
    GameMachine* machine;

public:
    HasCoinState(GameMachine* m);

    void insertCoin() override;
    void ejectCoin() override;
    bool chooseGame() override;
    void dispenseGame() override;
};

class GameSoldState : public State {
private:
    GameMachine* machine;

public:
    GameSoldState(GameMachine* m);

    void insertCoin() override;
    void ejectCoin() override;
    bool chooseGame() override;
    void dispenseGame() override;
};

class OutOfGamesState : public State {
private:
    GameMachine* machine;

public:
    OutOfGamesState(GameMachine* m);

    void insertCoin() override;
    void ejectCoin() override;
    bool chooseGame() override;
    void dispenseGame() override;
};

class GameMachine {
private:
    State* noCoinState;
    State* hasCoinState;
    State* gameSoldState;
    State* outOfGameState;
    State* state;

    vector<string> games = {
        "Zelda", "Mario", "Tetris", "Doom",
        "Hades", "League Of Legends",
        "Far Cry 3", "Just Cause 3"
    };

public:
    GameMachine() {
        noCoinState = new NoCoinState(this);
        hasCoinState = new HasCoinState(this);
        gameSoldState = new GameSoldState(this);
        outOfGameState = new OutOfGamesState(this);

        state = games.empty() ? outOfGameState : noCoinState;
    }

    ~GameMachine() {
        delete noCoinState;
        delete hasCoinState;
        delete gameSoldState;
        delete outOfGameState;
    }

    // Prevent accidental copying of owning raw pointers.
    GameMachine(const GameMachine&) = delete;
    GameMachine& operator=(const GameMachine&) = delete;

    void insertCoin() {
        state->insertCoin();
    }

    void ejectCoin() {
        state->ejectCoin();
    }

    void turnCrank() {
        if(state->chooseGame()) state->dispenseGame();
    }

    void setState(State* s) {
        state = s;
    }

    State* getNoCoinState() const {
        return noCoinState;
    }

    State* getHasCoinState() const {
        return hasCoinState;
    }

    State* getGameSoldState() const {
        return gameSoldState;
    }

    State* getOutOfGamesState() const {
        return outOfGameState;
    }

    int getNumOfGames() const {
        return static_cast<int>(games.size());
    }

    void displayGames() const {
        for (size_t i = 0; i < games.size(); ++i) {
            cout << i + 1 << ") " << games[i] << '\n';
        }
    }

    void releaseGame(int gameNumber) {
        if (gameNumber < 1 ||
            gameNumber > static_cast<int>(games.size())) {
            cout << "Invalid game number.\n";
            return;
        }

        cout << "You bought " << games[gameNumber - 1] << "!\n";
        games.erase(games.begin() + gameNumber - 1);
    }
};

// NoCoinState implementation

NoCoinState::NoCoinState(GameMachine* m) : machine(m) {}

void NoCoinState::insertCoin() {
    if (machine->getNumOfGames() == 0) {
        cout << "No games available.\n";
        machine->setState(machine->getOutOfGamesState());
        return;
    }

    cout << "Coin inserted.\n";
    machine->setState(machine->getHasCoinState());
}

void NoCoinState::ejectCoin() {
    cout << "There is no coin inside the machine.\n";
}

bool NoCoinState::chooseGame() {
  cout << "You need to pay first.\n";
  return false;
}

void NoCoinState::dispenseGame() {
    cout << "You need to pay first.\n";
}

// HasCoinState implementation

HasCoinState::HasCoinState(GameMachine* m) : machine(m) {}

void HasCoinState::insertCoin() {
    cout << "A coin is already inserted.\n";
}

void HasCoinState::ejectCoin() {
    cout << "Coin returned.\n";
    machine->setState(machine->getNoCoinState());
}

bool HasCoinState::chooseGame() {
    if (machine->getNumOfGames() == 0) {
        cout << "All games are sold out.\n";
        machine->setState(machine->getOutOfGamesState());
        return false;
    }

    machine->displayGames();

    cout << "Choose a game by number: ";

    int gameNumber;

    while (!(cin >> gameNumber)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a valid number: ";
    }

    cin.ignore(1000, '\n');

    if (gameNumber < 1 || gameNumber > machine->getNumOfGames()) {
        cout << "Invalid game number. Coin returned.\n";
        machine->setState(machine->getNoCoinState());
        return false;
    }

    machine->releaseGame(gameNumber);

    if (machine->getNumOfGames() == 0) {
      machine->setState(machine->getOutOfGamesState());
    } 
    else {
        machine->setState(machine->getGameSoldState());
    }
  return true;
}

void HasCoinState::dispenseGame() {
    cout << "Choose a game first.\n";
}

// GameSoldState implementation

GameSoldState::GameSoldState(GameMachine* m) : machine(m) {}

void GameSoldState::insertCoin() {
    cout << "Please wait, your game is being dispensed.\n";
}

void GameSoldState::ejectCoin() {
    cout << "You have already purchased a game.\n";
}

bool GameSoldState::chooseGame() {
    cout << "You have already selected a game.\n";
  return true;
}

void GameSoldState::dispenseGame() {
    cout << "Enjoy your game!\n";
    machine->setState(machine->getNoCoinState());
}

// OutOfGamesState implementation

OutOfGamesState::OutOfGamesState(GameMachine* m) : machine(m) {}

void OutOfGamesState::insertCoin() {
    cout << "Sorry, all games are sold out.\n";
}

void OutOfGamesState::ejectCoin() {
    cout << "There is no coin inside the machine.\n";
}

bool OutOfGamesState::chooseGame() {
  cout << "All games are sold out.\n";
  return false;
}

void OutOfGamesState::dispenseGame() {
    cout << "There are no games to dispense.\n";
}

// Main program

int main() {
    GameMachine machine;
    int choice;

    while (true) {
        cout << "1. Insert coin\n";
        cout << "2. Eject coin\n";
        cout << "3. Choose game and turn crank\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid option.\n";
            continue;
        }

        cin.ignore(1000, '\n');
        switch (choice) {
            case 1:
                machine.insertCoin();
                break;
            case 2:
                machine.ejectCoin();
                break;
            case 3:
                machine.turnCrank();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}

