#include "Login.h"

int main()
{

    AccountList *accountList = new AccountList;
    accountList->readFile();
    signUp(accountList);
    // Mình đăng nhập và trả vè con trỏ currentAccount nha
    // Nó là con trỏ mới trỏ song song vào vùng nhớ được chọn
    Account *currentAccount = logIn(accountList);
    currentAccount->print();
    // Tại đây mình log Out nè
    // Mình xóa con trỏ mới tạo lúc nãy á
    // Do là con trỏ song song nên mình xóa nó cũng không ảnh hưởng gì hết
    logOut(&currentAccount);
    accountList->update();
    return 0;
}