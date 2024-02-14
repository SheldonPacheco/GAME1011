#include <iostream>
#include <string>
using namespace std;

//structs are all public by default, and easy to use
struct Package
{
    string m_deliveryAddress;
    string m_message = "Message.";
};

class PostOffice 
{
public:
    PostOffice() 
    {

    }

    void PrintPackages()
    {
        for (int i = 0; i < m_packageCount; i++) 
        {
            cout << m_packages[i].m_message << "\n";
        }
	}

    void SetPackages(Package* packages, int packageCount)
    {
		m_packages = packages;
        this->m_packageCount = packageCount;
	}

    void SetAddress(string address)
    {
		m_buildingAddress = address;
	}

    string GetAddress() 
    {
        return m_buildingAddress;
    }

private:
    string m_buildingAddress;
	Package* m_packages = nullptr;
	int m_packageCount = 0;
};

class MailService 
{
public:
    MailService()
    {

	}

    void SetPostOffices(PostOffice* postOffices, int postOfficeCount)
	{
        m_postOffices = postOffices;
        m_postOfficeCount = postOfficeCount;
    }

private:
    PostOffice* m_postOffices = nullptr;
	int m_postOfficeCount = 0;
    string m_businessName;
};

int main()
{
    int mailServiceCount = 0;
    int postOfficeCount = 0;
    int packageCount = 0;
    cout << "Please enter the number of mail services: " << endl;
    cin >> mailServiceCount;
    cout << "Please enter the number of post offices: " << endl;
    cin >> postOfficeCount;
    cout << "Please enter the number of packages: " << endl;
    cin >> packageCount;

    Package* packages = new Package[packageCount];
    PostOffice* postOffices = new PostOffice[postOfficeCount];
    MailService* mailServices = new MailService[mailServiceCount];
    postOffices->SetPackages(packages, packageCount);
    //mailServices.SetPostOffices(postOffices, postOfficeCount);
    //(*mailServices).SetPostOffices(postOffices, postOfficeCount);
    mailServices->SetPostOffices(postOffices, postOfficeCount);
    postOffices->PrintPackages();

    return 0;
}

