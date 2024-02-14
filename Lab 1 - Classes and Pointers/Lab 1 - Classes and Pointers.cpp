using namespace std;
#include <iostream>
#include <windows.h>
#include <string>
void MainMenu();
class Achievement {
public:
    string GetAchievementName() {
        return achievementName;
    }
    string GetAchievementDescription() {
        return achievementDescription;
    }
    int GetAchievementScore() {
        return achievementScore;
    }
    void SetAchievementName(string achievementName) {
        this->achievementName = achievementName;
    }

    void SetAchievementDescription(string achievementDescription) {
        this->achievementDescription = achievementDescription;
    }

    void SetAchievementScore(int achievementScore) {
        this->achievementScore = achievementScore;
    }
private:
    int achievementScore = 0;
    string achievementName = "";
    string achievementDescription = "";
};

class Game {
public:
    
    string GetGameName() {
        return gameName;
    }
    string GetPublisher() {
        return publisherName;
    }
    string GetDeveloper() {
        return developerName;
    }
    void SetGameName(string name) {
        this->gameName = name;
    }

    void SetPublisher(string publisherName) {
        this->publisherName = publisherName;
    }

    void SetDeveloper(string developerName) {
        this->developerName = developerName;
    }
    int GetTotalAchievements() {
        return totalAchievements;
    }
    int GetTotalAchievementScore() {
        return TotalAchievementScore;
    }
    void SetTotalAchievements(int totalAchievements) {
        this->totalAchievements += totalAchievements;
    }
    void AddAchievementsToGame() {
        int menuchoice = 1;
        int achievementCount = 0;
        system("cls");
        cout << "How many achievements would you like to add? (minimum 5): ";
        cin >> achievementCount;
        SetTotalAchievements(achievementCount);
        

        Achievement* achievementList = new Achievement[GetTotalAchievements()];

        for (int i = 0; i < GetTotalAchievements() && i < totalAchievementsAdded; i++) {
            achievementList[i] = gameAchievements[i];
        }

        delete[] gameAchievements;

        gameAchievements = achievementList;

        for (int i = totalAchievementsAdded; i < GetTotalAchievements(); ++i) {
            system("cls");
            string achievementName = "";
            string achievementDescription = "";
            int achievementScore = 0;
            
            cout << "Achievement: " << i + 1 - totalAchievementsAdded <<"\n";

            cout << "Enter the achievement name: ";
            cin.ignore();
            getline(cin, achievementName);
            gameAchievements[i].SetAchievementName(achievementName);

            cout << "Enter the achievement description: ";
            cin.ignore();
            getline(cin, achievementDescription);
            gameAchievements[i].SetAchievementDescription(achievementDescription);

            cout << "Enter the achievement score: ";
            cin >> achievementScore;
            gameAchievements[i].SetAchievementScore(achievementScore);
            TotalAchievementScore += achievementScore;
        }

        totalAchievementsAdded = GetTotalAchievements();
        DisplayAchievements();
    }
    void DisplayAchievements() {
        system("cls");
        int menuchoice = 0;
        cout << "Achievements \n";
        cout << "\n";
        for (int i = 0; i < totalAchievements; ++i) {
            cout << "  Achievement name: " << gameAchievements[i].GetAchievementName() << "\n";
            cout << "  Description: " << gameAchievements[i].GetAchievementDescription() << "\n";
            cout << "  Score: " << gameAchievements[i].GetAchievementScore() << "\n";
            cout << "\n";
        }
        cout << "1. to go back to main menu\n";
        cin >> menuchoice;
        if (menuchoice == 1) {
            MainMenu();           
        }
    }
private:
    string gameName = "";
    string publisherName = "";
    string developerName = "";

    int totalAchievements = 0;
    int TotalAchievementScore = 0;
    int totalAchievementsAdded = 0;
    Achievement* gameAchievements = nullptr;
};

class Platform {
    
public:
    string GetPlatformName() {
        return platformName;
    }
    string GetManufacturerName() {
        return manufacturerName;
    }
    void SetPlatformName(string platformName) {
        this->platformName = platformName;
    }
    void SetManufacturerName(string manufacturerName) {
        this->manufacturerName = manufacturerName;
    }
    int GetTotalGames() {
        return totalGames;
    }
    void SetTotalGames(int totalGames) {
        this->totalGames += totalGames;
    }

    void CreateGames() {
        int gameCount = 0;
        string gamename = "";
        string publisherName = "";
        string developerName = "";
        system("cls");

        cout << "How many games would you like to add? (minimum 5): ";
        cin >> gameCount;
        SetTotalGames(gameCount);
        system("cls");

        Game* gamesList = new Game[GetTotalGames()];

        for (int i = 0; i < GetTotalGames() && i < totalGamesAdded; i++) {
            gamesList[i] = games[i];
        }

        delete[] games;

        games = gamesList;

        for (int i = totalGamesAdded; i < GetTotalGames(); ++i) {
            cout << "Game: "<< i +1-totalGamesAdded << "\n";
            cout << "Enter game name: ";
            cin.ignore();
            getline(cin, gamename);
            games[i].SetGameName(gamename);

            cout << "Enter publisher: ";
            cin.ignore();
            getline(cin, publisherName);
            games[i].SetPublisher(publisherName);

            cout << "Enter developer: ";
            cin.ignore();
            getline(cin, developerName);
            games[i].SetDeveloper(developerName);
            system("cls");           
        }

        totalGamesAdded = GetTotalGames();
        DisplayGames();
    }
    void DisplayGames() {
        int menuchoices = 1;
        int menuchoice = 0;
        for (int i = 0; i < totalGames; i++) {
            cout << menuchoices << "." <<"Game name: " << games[i].GetGameName() << "\n";
            cout << "  Publisher: " << games[i].GetPublisher() << "\n";
            cout << "  Developer: " << games[i].GetDeveloper() << "\n";
            cout << "  Achievements: " << games[i].GetTotalAchievements() << "\n";
            cout << "  Achievement Score: " << games[i].GetTotalAchievementScore() << "\n";
            cout << "\n";
            menuchoices++;
        }
        cout << menuchoices << ".to go back or select a game to view or add achievements to: ";
        cin >> menuchoice;
        if (menuchoice == menuchoices) {
            MainMenu();
        }
        else if (menuchoice >= 1 && menuchoice <= totalGames) {
            if (games[menuchoice - 1].GetTotalAchievements() > 0) {
                int menuchoice2 = 0;
                system("cls");
                cout << "1 to view achievements, 2 to add achievements: ";
                cin >> menuchoice2;
                if (menuchoice2 == 1) {
                    games[menuchoice - 1].DisplayAchievements();
                }
                else if (menuchoice2 == 2) {
                    games[menuchoice - 1].AddAchievementsToGame();
                }
            }
            games[menuchoice - 1].AddAchievementsToGame();
        }
    }
    
private:
    string platformName = "";
    string manufacturerName = "";
    int totalGames = 0;
    int totalGamesAdded = 0;
    Game* games = nullptr;  
};
class CreatePlatforms {
public:
    int GetPlatformCount() {
        return platformCount;
    }
    void SetPlatformCount(int platformCount) {
        this->platformCount += platformCount;
    }
    void CreatePlatform() {
        string platformName = "";
        string manufacturerName = "";
        int platformCount = 0;
        system("cls");

        cout << "How many platforms would you like?: ";
        cin >> platformCount;
        SetPlatformCount(platformCount);
        system("cls");
        
        Platform* newPlatforms = new Platform[GetPlatformCount()];

        for (int i = 0; i < GetPlatformCount() && i < totalPlatforms; i++) {
            newPlatforms[i] = platforms[i];
        }
        delete[] platforms;
        platforms = newPlatforms;

        for (int i = totalPlatforms; i < GetPlatformCount(); i++) {
        
        cout << "platform: " << i + 1 - totalPlatforms << "\n";
        cout << "Enter platform name: ";
        cin.ignore();
        getline(cin, platformName);
        platforms[i].SetPlatformName(platformName);

        cout << "\nEnter manufacturer name: ";
        cin.ignore();
        getline(cin, manufacturerName);
        platforms[i].SetManufacturerName(manufacturerName);
        system("cls");
        }

        totalPlatforms = GetPlatformCount();
        system("cls");
        DisplayPlatforms();   
    }
    void DisplayPlatforms() {
        int menuchoices = 1;
        int menuchoice = 0;
        int totalToDisplay = 0;
        for (int i = 0; i < platformCount; i++) {
            cout << menuchoices << ". Platform Name: " << platforms[i].GetPlatformName();
            cout << ", Manufacturer: " << platforms[i].GetManufacturerName();
            cout << " (Total Games: " << platforms[i].GetTotalGames() << ")\n";
            menuchoices++;         
        }
        cout << "Total Platforms: " << platformCount << "\n";
        menuchoices++;
        cout << menuchoices << ". Go back or select a platform to add games to \n";
        cin >> menuchoice;
        
        if (menuchoice == menuchoices) {
            MainMenu();
        } else if (menuchoice >= 1 && menuchoice <= platformCount)  {
            if (platforms[menuchoice-1].GetTotalGames() > 0 ) {
                int menuchoice2 = 0;
                system("cls");
                cout << "1 to view games, 2 to add mores games: ";
                cin >> menuchoice2;
                system("cls");
                if (menuchoice2 == 1) {
                    platforms[menuchoice-1].DisplayGames();
                }
                else if (menuchoice2 == 2) {
                    platforms[menuchoice-1].CreateGames();
                }
            }
            else {
                platforms[menuchoice-1].CreateGames();
            }
        } 
    }
private:
    int platformCount = 0;
    int totalPlatforms = 0;
    Platform* platforms = nullptr;
};
CreatePlatforms platforms;
void MainMenu() {
    int menuChoice = 0;
    system("cls");
   
    if (platforms.GetPlatformCount() <= 0) {
        cout << "1. Create a platform\n";
    }
    else {
        cout << "1. Create a platform\n";
        cout << "2. View platforms, add games, addachievements to games\n";   
    }
    cin >> menuChoice;

        if (menuChoice == 1) {
            platforms.CreatePlatform();
           
        }
        else if (menuChoice == 2 && platforms.GetPlatformCount() > 0) {
            system("cls");
            platforms.DisplayPlatforms();
            
        }
        else if (menuChoice == 3) {
            MainMenu();
        }
        else {
            cout << "Invaild Option: \n";
            cin >> menuChoice;
        }
      
}
int main() {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 + (6 << 4));
    MainMenu();
    return 0;
};
