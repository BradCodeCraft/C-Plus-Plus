#include <map>
#include <string>

class Account {
public:
  // --- General Constructor
  Account(std::string inputLoginUsername, std::string inputLoginPassphrase,
          std::string inputAccountName, std::string inputAccountType);

  // --- Login Constructor
  Account(std::string inputLoginUsername, std::string inputLoginPassphrase,
          std::map<std::string, std::map<std::string, std::string>>
              inputAccountsMap);

  // --- Register Constructor
  Account(std::string inputLoginUsername, std::string inputLoginPassphrase,
          std::string inputAccountName, std::string inputAccountType,
          std::map<std::string, std::map<std::string, std::string>>
              &inputAccountsMap);

  // --- Getters
  std::map<std::string, std::string> getAccountDetails();

  // --- Setters
  void setAccountName(std::string inputNewAccountName);
  void setLoginPassphrase(std::string inputNewLoginPassphrase);

private:
  // --- Struct of AccountDetails
  // loginUsername: string
  // loginPassphrase: string
  // accountName: string
  // accountType: string enum("USER", "ADMIN")
  std::map<std::string, std::string> AccountDetails;

  // --- Login Method
  bool validateLoggingInAccount(
      std::string inputLoginUsername, std::string inputLoginPassphrase,
      std::map<std::string, std::map<std::string, std::string>>
          inputAccountsMap);

  // --- Register Method
  bool validateRegisteringAccount(
      std::string inputLoginUsername, std::string inputLoginPassphrase,
      std::string inputAccountName,
      std::map<std::string, std::map<std::string, std::string>>
          inputAccountsMap);

  // --- Validate Account Password
  bool validateAccountPassword(std::string inputLoginPassphrase);
};
