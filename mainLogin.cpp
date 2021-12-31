#include "Login.h"

int Account::_num = 0;
int PasswordChecker::_count = 0;
int main()
{

    LinkedListAccount *linkedList = new LinkedListAccount;
    linkedList->readFileJson("loginInfo.json");
    signUp(linkedList);
    // Mình đăng nhập và trả vè con trỏ currentAccount nha
    // Nó là con trỏ mới trỏ song song vào vùng nhớ được chọn
    Account *currentAccount = logIn(linkedList);
    currentAccount->print();
    // Tại đây mình log Out nè
    // Mình xóa con trỏ mới tạo lúc nãy á
    // Do là con trỏ song song nên mình xóa nó cũng không ảnh hưởng gì hết
    /*
    json j;
    fstream is;
    is.open("flights.json", ios::in | ios::binary);
    is >> j;
    for (size_t i = 0; i < j.size(); ++i)
    {
        cout << j[i]["ArrivalAirport"] << " to " << j[i]["DepartureAirport"] << "\n";
    }
    is.close();
    ////
    ////
    ///
    */

    logOut(&currentAccount);
    linkedList->updateDatabase("loginInfo.json");
    system("pause");
    return 0;
}