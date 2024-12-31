#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std 사용

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
    // book의 이름과 저자로 비교하는 매서드 추가 : 검색 기능 추가를 위해
     // 이름 비교 메서드
    bool hasTitle(const string& otherTitle) const {
        return title == otherTitle;
    }

    // 저자 비교 메서드
    bool hasAuthor(const string& otherAuthor) const {
        return author == otherAuthor;
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장
    vector<Book> search; // 검색용 벡터
public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    // 책 이름으로 책 검색 하는 메소드
    void searchByTitle(string title) const {
        auto it = find_if(books.begin(), books.end(),
            [&title](const Book& book) { return book.hasTitle(title); });
        if (it != books.end()) {
            cout << "해당 책의 이름: " << it->title << ", 저자: " << it->author << endl;
        }
        else {
            cout << "해당 되는 책 이름이 없습니다." << endl;
        }
    }
    // 저자 이름으로 책 검색 하는 메소드
    void searchByAuthor(string author) const {
        auto it = find_if(books.begin(), books.end(),
            [&author](const Book& book) { return book.hasAuthor(author); });
        if (it != books.end()) {
            cout << "해당 책의 이름: " << it->title << ", 저자: " << it->author << endl;
        }
        else {
            cout << "해당 되는 저자 이름이 없습니다." << endl;
        }
    }
};

int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 제목을 통해 검색" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "4. 책 저자를 통해 검색" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "5. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3번 선택: 제목을 통한 검색
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            string title;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            string author;
            cout << "책 저자: ";
            cin.ignore();
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
