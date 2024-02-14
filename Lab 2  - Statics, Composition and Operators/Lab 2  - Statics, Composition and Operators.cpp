#include <iostream>
#include <string>
#include <vector>

using namespace std;
void ClearConsole() {
    system("cls");
}
class Weapon {
public:
    Weapon() : name("No Weapon"), damage(0), specialAbilityName("No Special Ability"), specialAbilityDamage(0) {}

    Weapon(string name, int damage, string specialAbilityName, int specialAbilityDamage)
        : name(name), damage(damage), specialAbilityName(specialAbilityName), specialAbilityDamage(specialAbilityDamage){}

    friend ostream& operator<<(ostream& output, const Weapon& weapon) {
        output << "Weapon: " << weapon.name << "\n";
        output << "Damage: " << weapon.damage << "\n";
        output << "Special Abilities:\n";
        output << "  " << weapon.specialAbilityName << ": Damage " << weapon.specialAbilityDamage << "\n";
        return output;
    }

    bool operator==(const Weapon& weapon) const {
        return name == weapon.name && damage == weapon.damage && specialAbilityName == weapon.specialAbilityName && specialAbilityDamage == weapon.specialAbilityDamage;
    }

    bool operator!=(const Weapon& weapon) const {
        return !(*this == weapon);
    }

    string getName() const {
        return name;
    }

    int getDamage() const {
        return damage;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setDamage(int damage) {
        this->damage = damage;
    }
    void SetVector(const string& specialAbilityName, int specialAbilityDamage) {
        specialAbilities.push_back(make_pair(specialAbilityName, specialAbilityDamage));
    }
private:
    string name = "";
    int damage = 0;
    string specialAbilityName;
    int specialAbilityDamage;
    vector<pair<string, int>> specialAbilities;
};

class Armour {
public:
    Armour() : name("No Armour"), description("No Description"), physicalDefense(0), magicDefense(0) {}

    Armour(string name, string description, int armorValue, int magicDefense)
        : name(name), description(description), physicalDefense(armorValue), magicDefense(magicDefense) {}

    friend ostream& operator<<(ostream& output, const Armour& armour) {
        output << "Armour Name: " << armour.name << "\n";
        output << "Item Description: " << armour.description << "\n";
        output << "Physical Defense: " << armour.physicalDefense << "\n";
        output << "Magic Defense: " << armour.magicDefense << "\n";
        return output;
    }

    bool operator==(const Armour& armour) const {
        return name == armour.name && description == armour.description && physicalDefense == armour.physicalDefense &&
            magicDefense == armour.magicDefense;
    }

    string getName() const {
        return name;
    }

    string getDescription() const {
        return description;
    }

    int getPhysicalDefense() const {
        return physicalDefense;
    }

    int getMagicDefense() const {
        return magicDefense;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setDescription(const string& description) {
        this->description = description;
    }

    void setPhysicalDefense(int physicalDefense) {
        this->physicalDefense = physicalDefense;
    }

    void setMagicDefense(int magicDefense) {
        this->magicDefense = magicDefense;
    }

private:
    string name;
    string description;
    int physicalDefense;
    int magicDefense;
};

class Character {
public:
    Character() : name("No Character"), species("No Species"), epicBackstory("No Backstory"), health(0) {}

    Character(string name, string species, string epicBackstory, int health, Weapon& weapon, Armour& armour)
        : name(name), species(species), epicBackstory(epicBackstory), health(health), weapon(weapon), armour(armour) {}

    friend ostream& operator<<(ostream& output, const Character& character) {
        output << "Name: " << character.name << "\n";
        output << "Species: " << character.species << "\n";
        output << "Backstory: " << character.epicBackstory << "\n";
        output << "Starting Health: " << character.health << "\n";
        output << character.weapon;
        output << character.armour;
        return output;
    }

    bool operator==(const Character& character) const {
        return name == character.name && species == character.species && epicBackstory == character.epicBackstory &&
            health == character.health && weapon == character.weapon && armour == character.armour;
    }

    string getName() const {
        return name;
    }

    string getSpecies() const {
        return species;
    }

    string getEpicBackstory() const {
        return epicBackstory;
    }

    int getHealth() const {
        return health;
    }

    const Weapon& getWeapon() const {
        return weapon;
    }

    const Armour& getArmour() const {
        return armour;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setSpecies(const string& species) {
        this->species = species;
    }

    void setEpicBackstory(const string& epicBackstory) {
        this->epicBackstory = epicBackstory;
    }

    void setHealth(int health) {
        this->health = health;
    }

    void setWeapon(const Weapon& weapon) {
        this->weapon = weapon;
    }

    void setArmour(const Armour& armour) {
        this->armour = armour;
    }

private:
    string name = "";
    string species = "";
    string epicBackstory = "";
    int health = 0;
    Weapon weapon;
    Armour armour;
};

class CharacterCreation {
public:
    void MainMenu(vector<Character>& characters) {
        ClearConsole();
        cout << "Welcome :)\n";

        int menuChoice = 0;;
        do {
            if (characters.size() <= 3) {
                cout << "1. Create a character\n";
            }
            if (characters.size() >= 2) {
                cout << "2. Compare characters\n";
                cout << "3. Display all characters\n";
            }
            cout << "4. Exit\n";
            cout << "Enter the number of where you want to go: ";
            cin >> menuChoice;

            if (menuChoice == 1 && characters.size() <=3) {
                CreateCharacter(characters);               
            }
            else if (menuChoice == 2&& characters.size() >= 2) {
                CompareCharacters(characters);
            }
            else if (menuChoice == 3&& characters.size() >= 2) {
                DisplayCharacters(characters);
            }
            else if (menuChoice != 4) {
                cout << "Select another option\n";
            }
            else if (menuChoice == 4) {
                ClearConsole();
                cout << "bye bye\n";
            }
        } while (menuChoice != 4);
    }

private:
    vector<Weapon> weaponChoices = {
        Weapon("Basic Sword", 15, "Bunt", 5),
        Weapon("Wooden Staff", 5, "Ice bolt", 20),
        Weapon("Wooden sword and shield", 5, "Shield bash", 10)
    };

    vector<Armour> armourChoices = {
        Armour("Brittle Armour", "Basic balanced physical and magic defense.", 8, 5),
        Armour("Brittle Magic Armour", "Purely magic defense, with no physical defense.", 0, 18),
        Armour("Brittle Physical Armour", "Purely physical defense", 15, 0)
    };

    Weapon WeaponChoices() {
        ClearConsole();
        cout << "Choose a starting weapon (enter the number you want):\n";
        for (int i = 0; i < weaponChoices.size(); ++i) {
            cout << i + 1 << ". " << weaponChoices[i].getName() << "\n";
        }

        int menuChoice;
        cin >> menuChoice;

        if (menuChoice >= 1 && menuChoice <= weaponChoices.size()) {
            return weaponChoices[menuChoice - 1];
        }
        else {
            cout << "Invalid choice: \n";
            cin >> menuChoice;
            return weaponChoices[menuChoice-1];
        }
    }

    Armour ArmourChoices() {
        ClearConsole();
        cout << "Choose a starting armor set (enter the number you want):\n";
        for (int i = 0; i < armourChoices.size(); ++i) {
            cout << i + 1 << ". " << armourChoices[i].getName() << "\n";
        }

        int menuChoice;
        cin >> menuChoice;

        if (menuChoice >= 1 && menuChoice <= armourChoices.size()) {
            return armourChoices[menuChoice - 1];
        }
        else {
            cout << "Invalid choice: \n";
            cin >> menuChoice;
            return armourChoices[menuChoice - 1];
        }
    }

    void CreateCharacter(vector<Character>& characters) {
        ClearConsole();
        string name = "";
        string species = "";
        string epicBackstory = "";
        int health = 0;
        cout << "Enter character name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter species: ";
        getline(cin, species);
        
        cout << "Enter epic backstory: ";
        getline(cin, epicBackstory);
        
        cout << "Enter starting health: ";
        cin >> health;
        ClearConsole();
        
        Character characterCreate;
        characterCreate.setName(name);
        characterCreate.setSpecies(species);
        characterCreate.setEpicBackstory(epicBackstory);
        characterCreate.setHealth(health);

        
        characterCreate.setWeapon(WeaponChoices());
        characterCreate.setArmour(ArmourChoices());

        ClearConsole();
        cout << "Character added, congrats\n";
        cout << "\n";
        cout << characterCreate;
        cout << "\n";
        characters.push_back(characterCreate);
    }

    void CompareCharacters(vector<Character>& characters) const {
        ClearConsole();
        int firstCharacter = 0;
        int secondCharacter = 0;
        cout << "Enter the first character (1 to " << characters.size() << "): ";
        cin >> firstCharacter;
        ClearConsole();
        cout << "Enter the second character (1 to " << characters.size() << "): ";
        cin >> secondCharacter;
        ClearConsole();

        if (firstCharacter >= 1 && firstCharacter <= characters.size() &&secondCharacter >= 1 && secondCharacter <= characters.size() && firstCharacter != secondCharacter) {
            ClearConsole();
            cout << "First Character:\n";
            cout << characters[firstCharacter-1];
            cout << "\n";
            cout << "Second Character:\n";
            cout << characters[secondCharacter-1];
            cout << "\n";
        }
        else {
            cout << "Invalid character numbers. Characters must be different and within range.\n";
        }
    }

    void DisplayCharacters(vector<Character>& characters) const {
        ClearConsole();
        for (int i = 0; i < characters.size(); ++i) {
            cout << "Character " << i + 1 << ":\n";
            cout << characters[i];
            cout << "\n";
        }
        
    }

};
int main() {
    vector<Character> characters;
    CharacterCreation creation;
    creation.MainMenu(characters);

    return 0;
}
